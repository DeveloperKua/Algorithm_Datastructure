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




#endif
	TCHAR buffer[128];

	//myMaze->Render();
	wsprintf(buffer, L"[FPS:%5d][Time:%5d]", (int)GetFPS(), (int)GetTime());
	g_pGdi->TextAtPos(10, 0, buffer);

	wsprintf(buffer, L"미로 생성 알고리즘 F1-Binary Tree F2-SideWinder F3-RecursiveBacktracking ");
	g_pGdi->TextAtPos(170, 0, buffer);
	switch (myMaze->mazeAlgorithmType)
	{
	case 0:
		break;
	case 1:
		wsprintf(buffer, L"현재 알고리즘:Binary Tree Algorithm");
		g_pGdi->TextAtPos(10, 20, buffer);
		myMaze->MazeGenerator_BinaryTree();
		break;
	case 2:
		wsprintf(buffer, L"현재 알고리즘:SideWinder Algorithm");
		g_pGdi->TextAtPos(10, 20, buffer);
		myMaze->MazeGenerator_SideWinder();
		break;
	case 3:
		wsprintf(buffer, L"현재 알고리즘:Recursive Backtracking Algorithm");
		g_pGdi->TextAtPos(10, 20, buffer);
		myMaze->MazeGenerator_RecursiveBacktracking();
		break;
	case 4:
		break;
}
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