#include "stdafx.h"
HINSTANCE g_hInstance;

CSystem::CSystem(void)
{

}

CSystem::~CSystem(void)
{

}

bool CSystem::Initialize(void)
{
	CBaseWindow::Initialize();
	CTimeManager::Initialize();

	m_pInputManager = new CInputManager;
	m_pInputManager->Initialize();
	g_pInputManager->SetInputHandler(this);

	myMaze = new cMaze();
	myMaze->Initialize();

	return true;
}

void CSystem::Update(void)
{
	CTimeManager::Pulse();
	m_pInputManager->Pulse();


#ifdef _DEBUG
	TCHAR buffer[128];

	//myMaze->Render();

	switch (myMaze->mazeAlgorithmType)
	{
	case 0:

		wsprintf(buffer, L"[FPS:%5d][Time:%5d]", (int)GetFPS(), (int)GetTime());
		g_pGdi->TextAtPos(10, 10, buffer);
		//_tprintf( _T("mode 1 \n"));

		break;
	case 1:
		myMaze->MazeGenerator_RecursiveBacktracking();
		//_tprintf(_T("mode 2 \n"));

		break;
	}



#endif

	g_pGdi->Blt();
}

void CSystem::Terminate(void)
{
	CBaseWindow::Terminate();
	CTimeManager::Terminate();
	myMaze->~cMaze();
}

void CSystem::Run(void)
{
	MSG msg;

	PeekMessage(&msg, NULL, 0, 0, PM_REMOVE);
	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else	return;

		}
		else if (m_bIsActive)
		{
			Update();
		}
		else
		{
			WaitMessage();
		}
	}
}

void CSystem::KeyboardHandler()
{
	if (g_pKeyCodeScan(VK_ESCAPE))
	{
		SendMessage(this->GetHandle(), WM_DESTROY, 0, 0);
		//PostQuitMessage(0);
	}
}

void CSystem::MouseHandler(MOUSESTATE diMouseState)
{
	m_bIsMouseLeft = (diMouseState.btn[0]) ? true : false;
	m_bIsMouseMid = (diMouseState.btn[2]) ? true : false;
	m_bIsMouseRight = (diMouseState.btn[1]) ? true : false;
	m_vMouseXY.x = diMouseState.x;
	m_vMouseXY.y = diMouseState.y;
}