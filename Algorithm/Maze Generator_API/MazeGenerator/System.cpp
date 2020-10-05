#include "stdafx.h"

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

	myMaze = new cMaze();
	myMaze->Initialize();

	return true;
}

void CSystem::Update(void)
{
	CTimeManager::Pulse();

#ifdef _DEBUG
	TCHAR buffer[128];

	//wsprintf(buffer, L"[FPS:%5d][Time:%5d]", (int)GetFPS(), (int)GetTime());
	//g_pGdi->TextAtPos(10, 10, buffer);
	myMaze->MazeGenerator_RecursiveBacktracking();
	//myMaze->Render();



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