// WndGameBase.cpp : ���� ���α׷��� ���� �������� �����մϴ�.
//

#include "stdafx.h"
#include "WndGameBase.h"

// ���� ����:
HINSTANCE hInst;								// ���� �ν��Ͻ��Դϴ�.

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
