#pragma once
#include <windows.h>

typedef struct tagIMGBUFFER
{
	HWND hWnd;
	HDC hdcFront;				//���� ����
	HDC hdcBack;             //�ĸ� ����
	HDC hdcImg;               //��µ� �̹��� ����
	HBITMAP hbmBack;   //�ĸ� ���� ���빰
	HBITMAP hbmImg;     //�̹��� ���� ���빰
	RECT BufferSize;         //���� ũ��
}IMGBUFFER;

IMGBUFFER* CreateImageBuffer(HWND hWnd);

void LoadImage(IMGBUFFER* ib, LPCWSTR filename);

void DrawImage(IMGBUFFER* ib, int x, int y);

HBITMAP LoadImage(LPCWSTR filename);

void ClearScreen(IMGBUFFER* ib,  COLORREF color);

void SwapBuffer(IMGBUFFER* ib);

void DeleteImageBuffer(IMGBUFFER* ib);

