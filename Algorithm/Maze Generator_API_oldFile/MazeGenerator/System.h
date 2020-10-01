#pragma once
#include <windows.h>

#define	WIDTH	800
#define	HEIGHT	800

BOOL WinInit(LPCWSTR pWinName);

HWND WinCreate(LPCWSTR pClassName, LPCWSTR pWindowName, HINSTANCE hInst, int nWindowStyle, RECT rtWindowSize);

VOID MsgLoop();

int GameLoop();