#include "stdafx.h"
#include "MainProc.h"

HDC		g_hdcScreen;
HINSTANCE g_hInstance;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	///log Ȯ�ο� �ܼ� ����
	/*AllocConsole();
	_tfreopen(_T("CONOUT$"), _T("w"), stdout);
	_tfreopen(_T("CONIN$"), _T("r"), stdin);
	_tfreopen(_T("CONERR$"), _T("w"), stderr);
	_tsetlocale(LC_ALL, _T(""));*/
	g_hdcScreen = GetDC(hWnd);

	CreateWindow(L"button", L"SendButton", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 
		10, 160, 100, 30, hWnd, (HMENU)IDC_SEND1, g_hInstance, NULL);

	g_pGdi->StartDraw(g_hdcScreen);
	SetTimer(hWnd, 0, 1000, NULL);

	return 0;
}

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

int OnKeyDown(HWND hWnd, WPARAM wParam, LPARAM lParam)
{

	return 0;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	g_pGdi->StopDraw(g_hdcScreen);
	ReleaseDC(hWnd, g_hdcScreen);
	PostQuitMessage(0);
	return 0;
}

int OnCommand(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	return 0;
}

int OnSize(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	return  0;
}

int OnMouseMove(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	POINT pt = { LOWORD(lParam), HIWORD(lParam) };

	return 0;
}

//
//  �Լ�: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  ����: �� â�� �޽����� ó���մϴ�.
//
//  WM_COMMAND	- ���� ���α׷� �޴��� ó���մϴ�.
//  WM_PAINT	- �� â�� �׸��ϴ�.
//  WM_DESTROY	- ���� �޽����� �Խ��ϰ� ��ȯ�մϴ�.
//
//
LRESULT CALLBACK MainWndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		return OnCreate(hWnd, wParam, lParam);
	case WM_COMMAND:
		return OnCommand(hWnd, wParam, lParam);
	case WM_SIZE:
		return OnSize(hWnd, wParam, lParam);
	case WM_TIMER:
		return OnTimer(hWnd, wParam, lParam);
	case WM_KEYDOWN:
		return OnKeyDown(hWnd, wParam, lParam);
	case WM_MOUSEMOVE:
		return OnMouseMove(hWnd, wParam, lParam);
	case WM_DESTROY:
		return OnDestroy(hWnd, wParam, lParam);
	case WM_CLOSE:
		//FreeConsole();
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}