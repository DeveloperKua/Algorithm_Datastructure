#include <windows.h>
#include "System.h"
#include "MainProc.h"
#include "imgBuffer.h"

WCHAR TEXT[100] = L"Maze Generator";

HWND g_hWnd;

LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_CREATE:
		return OnCreate(hWnd, wParam, lParam);

	case WM_TIMER:
		return OnTimer(hWnd, wParam, lParam);

	case WM_LBUTTONDOWN:
		return OnMouseLButton(hWnd, wParam, lParam);

	case WM_CLOSE:
	case WM_DESTROY:
		return OnDestroy(hWnd, wParam, lParam);
	}

	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

int APIENTRY WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpCmdLine, int nShowCmd)
{
	RECT rtSystemSize = { 0, 0, WIDTH + 40, HEIGHT + 45 };

	WinInit(TEXT);

	g_hWnd = WinCreate(TEXT, TEXT, hInst, WS_OVERLAPPEDWINDOW, rtSystemSize);

	//MsgLoop();

	//return 0;
	return GameLoop();
}