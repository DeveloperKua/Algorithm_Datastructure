#include "stdafx.h"
#include "MainProc.h"

HDC		g_hdcScreen;
HINSTANCE g_hInstance;

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	///log 확인용 콘솔 생성
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
//  함수: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  목적: 주 창의 메시지를 처리합니다.
//
//  WM_COMMAND	- 응용 프로그램 메뉴를 처리합니다.
//  WM_PAINT	- 주 창을 그립니다.
//  WM_DESTROY	- 종료 메시지를 게시하고 반환합니다.
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