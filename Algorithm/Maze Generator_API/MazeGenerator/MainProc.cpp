#include "MainProc.h"
#include "System.h"
#include "imgBuffer.h"
#include <stdio.h>

extern BOOL bIsActive;

IMGBUFFER* Buffer;

POINT ptMouse;
int nFPS;
int nCount;


int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Buffer = CreateImageBuffer(hWnd);
	bIsActive = true;
	SetTimer(hWnd, 0, 1000, NULL);

	return 1;
}

int OnPaint(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	HDC	hdc;
	PAINTSTRUCT	ps;

	char strBuffer[1024];
	hdc = BeginPaint(hWnd, &ps);


	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			grid[y][x].drawLine(hdc);
		}
	}

	EndPaint(hWnd, &ps);

	return 0;
}

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	nFPS = nCount;
	nCount = 0;

	return 1;
}

int OnMouseLButton(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	ptMouse.x = LOWORD(lParam);
	ptMouse.y = HIWORD(lParam);


	return 1;
}

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam)
{

	bIsActive = false;

	DeleteImageBuffer(Buffer);

	PostQuitMessage(0);

	return 1;
}

void Run()
{
	char strBuffer[16];
	DWORD t;

	ClearScreen(Buffer, RGB(255, 255, 255));

	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			grid[y][x].drawLine(Buffer->hdcBack);
		}
	}

	SwapBuffer(Buffer);

	nCount++;

	Sleep(1000 / 66);
}