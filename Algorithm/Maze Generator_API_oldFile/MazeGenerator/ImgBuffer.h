#pragma once
#include <windows.h>

typedef struct tagIMGBUFFER
{
	HWND hWnd;
	HDC hdcFront;				//전면 버퍼
	HDC hdcBack;             //후면 버퍼
	HDC hdcImg;               //출력될 이미지 버퍼
	HBITMAP hbmBack;   //후면 버퍼 내용물
	HBITMAP hbmImg;     //이미지 버퍼 내용물
	RECT BufferSize;         //버퍼 크기
}IMGBUFFER;

IMGBUFFER* CreateImageBuffer(HWND hWnd);

void LoadImage(IMGBUFFER* ib, LPCWSTR filename);

void DrawImage(IMGBUFFER* ib, int x, int y);

HBITMAP LoadImage(LPCWSTR filename);

void ClearScreen(IMGBUFFER* ib,  COLORREF color);

void SwapBuffer(IMGBUFFER* ib);

void DeleteImageBuffer(IMGBUFFER* ib);

