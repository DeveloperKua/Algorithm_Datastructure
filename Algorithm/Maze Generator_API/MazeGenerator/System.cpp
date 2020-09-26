#include "System.h"
#include "MainProc.h"

BOOL bIsActive = false;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

BOOL WinInit(LPCWSTR pClassName)
{
	WNDCLASSEX wcex;

	HINSTANCE hInstance = GetModuleHandle(NULL);

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	wcex.hCursor = LoadCursor(0, IDC_ARROW);
	wcex.hIcon = LoadIcon(hInstance, (LPCTSTR)IDI_APPLICATION);
	wcex.hIconSm = LoadIcon(wcex.hInstance, (LPCTSTR)IDI_APPLICATION);
	wcex.lpfnWndProc = WndProc;
	wcex.lpszClassName = pClassName;
	wcex.lpszMenuName = NULL;
	wcex.style = CS_HREDRAW | CS_VREDRAW;

	if (RegisterClassEx(&wcex) == NULL)	return FALSE;

	return TRUE;
}

HWND WinCreate(LPCWSTR pClassName, LPCWSTR pWindowName, HINSTANCE hInst, int nWindowStyle, RECT rtWindowSize)
{
	HWND hWnd;

	hWnd = CreateWindow(pClassName, pWindowName,
		nWindowStyle,
		rtWindowSize.left, rtWindowSize.top, rtWindowSize.right - rtWindowSize.left, rtWindowSize.bottom - rtWindowSize.top,
		NULL, NULL, hInst, NULL);

	ShowWindow(hWnd, SW_SHOW);
	UpdateWindow(hWnd);

	return hWnd;
}

VOID MsgLoop()
{
	MSG		msg;

	while (GetMessage(&msg, 0, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
}

int GameLoop()
{
	MSG		msg;

	while (1)
	{
		if (PeekMessage(&msg, NULL, 0, 0, PM_NOREMOVE))
		{
			if (GetMessage(&msg, NULL, 0, 0))
			{
				TranslateMessage(&msg);
				DispatchMessage(&msg);
			}
			else
			{
				return (int)msg.wParam;
			}
		}
		else if (bIsActive)
		{
			Run();
		}
		else
		{
			WaitMessage();
		}
	}

	return 1;
}