#include "stdafx.h"
#include "BaseWindow.h"

CBaseWindow::CBaseWindow(void) : m_bIsActive(false)
{
}


CBaseWindow::~CBaseWindow(void)
{
}

bool CBaseWindow::Initialize()
{
	HINSTANCE g_hInstance = GetModuleHandle(NULL);

	TCHAR szTitle[MAX_LOADSTRING];
	LoadString(g_hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING );

	//������ Ŭ���� ����/�ʱ�ȭ
	WNDCLASSEX wcex;
	wcex.cbSize			= sizeof(WNDCLASSEX); 
	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= (WNDPROC)MainWndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= g_hInstance;
	wcex.hIcon			= LoadIcon(g_hInstance, (LPCTSTR)IDI_MAZEGENERATOR);
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground  = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName	= NULL;
	wcex.lpszClassName	= szTitle;
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_SMALL);

	RegisterClassEx(&wcex); //������ Ŭ���� ���

	//������ ����
	m_hWnd = CreateWindow(szTitle, szTitle, WS_BORDER| WS_CAPTION | WS_SYSMENU,
		0, 0, 0, 0, NULL, NULL, g_hInstance, NULL);

	RECT rtRect; //�簢�� ����ü

	rtRect.left = 0;
	rtRect.top = 0;
	rtRect.right = 810;
	rtRect.bottom = 810;

	//������ ������ ������ �Լ�
	AdjustWindowRect(&rtRect, WS_BORDER| WS_CAPTION | WS_SYSMENU, false);

	//������ ��ġ
	SetWindowPos(m_hWnd, NULL, 0, 0, rtRect.right - rtRect.left, rtRect.bottom - rtRect.top, SWP_SHOWWINDOW);

	if (!m_hWnd)
	{
		return false;
	}
	m_bIsActive = true;

	ShowWindow(m_hWnd, SW_SHOW);
	UpdateWindow(m_hWnd);

	return true;
}

void CBaseWindow::Terminate()
{
}