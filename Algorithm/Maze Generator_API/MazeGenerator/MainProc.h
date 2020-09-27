#pragma once
#include <windows.h>

int OnCreate(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnTimer(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnMouseLButton(HWND hWnd, WPARAM wParam, LPARAM lParam);

int OnDestroy(HWND hWnd, WPARAM wParam, LPARAM lParam);

void Run();

