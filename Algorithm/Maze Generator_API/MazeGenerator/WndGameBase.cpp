// WndGameBase.cpp : 응용 프로그램에 대한 진입점을 정의합니다.
//

#include "stdafx.h"
#include "WndGameBase.h"

// 전역 변수:
HINSTANCE hInst;								// 현재 인스턴스입니다.

int APIENTRY _tWinMain(_In_ HINSTANCE hInstance,
                     _In_opt_ HINSTANCE hPrevInstance,
                     _In_ LPTSTR    lpCmdLine,
                     _In_ int       nCmdShow)
{
	CSystem* pSystem = new CSystem;

	pSystem->Initialize();

	pSystem->Run();

	pSystem->Terminate();

	delete pSystem;
}
