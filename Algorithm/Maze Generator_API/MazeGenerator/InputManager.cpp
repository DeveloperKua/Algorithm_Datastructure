#include "StdAfx.h"
#include "InputManager.h"


CInputManager::CInputManager(void)
{
	m_pCurInputHandler = NULL;
}


CInputManager::~CInputManager(void)
{
}

bool CInputManager::Initialize()
{
	memset( m_OldKeyState, 0, sizeof(m_OldKeyState) );
	memset( m_CurKeyState, 0, sizeof(m_CurKeyState) );

	memset( &m_diMouseState, 0,sizeof(MOUSESTATE) );
	
	return true;
}

void CInputManager::Terminate()
{

}

void CInputManager::Keyboard()
{
	for (int nCnt = 0; nCnt < 256; nCnt++)
	{
		if (HIBYTE(GetAsyncKeyState(nCnt)))
		{
			m_CurKeyState[nCnt] = 1;
		}
		else
		{
			m_CurKeyState[nCnt] = 0;
		}
	}
	m_pCurInputHandler->KeyboardHandler();

	memcpy(m_OldKeyState, m_CurKeyState, 256);
}

void CInputManager::Mouse()
{
	m_diMouseState.btn[0] = (m_CurKeyState[VK_LBUTTON]) ? 1 : 0;
	m_diMouseState.btn[1] = (m_CurKeyState[VK_RBUTTON]) ? 1 : 0;
	m_diMouseState.btn[2] = (m_CurKeyState[VK_MBUTTON]) ? 1 : 0;
	POINT	pt;
	GetCursorPos(&pt); //화면전체 마우스 좌표
	ScreenToClient(g_pSystem->GetHandle(), &pt); //윈도우좌표계 전환
	m_diMouseState.x = pt.x;
	m_diMouseState.y = pt.y;

	m_pCurInputHandler->MouseHandler(m_diMouseState);
}

void CInputManager::Pulse()
{
	if (m_pCurInputHandler)
	{
		Keyboard();
		Mouse();
	}
}
