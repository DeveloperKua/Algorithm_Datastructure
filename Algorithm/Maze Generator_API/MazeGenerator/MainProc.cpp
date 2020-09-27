#include "MainProc.h"
#include "System.h"
#include "imgBuffer.h"
#include "maze Source/MazeGenerator.h"
#include <stdio.h>

extern BOOL bIsActive;

IMGBUFFER* Buffer;

POINT ptMouse;
int nFPS;
int nCount;

cMaze * myMaze = new cMaze();

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam)
{
	Buffer = CreateImageBuffer(hWnd);
	bIsActive = true;
	SetTimer(hWnd, 0, 1000, NULL);

	myMaze->Initialize();

	return 1;
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

	myMaze->MazeGenerator_BinaryTree(Buffer->hdcBack);
	myMaze->Render(Buffer->hdcBack);
	
	SwapBuffer(Buffer);

	nCount++;

	Sleep(1000 / 66);
}