// stdafx.h : 자주 사용하지만 자주 변경되지는 않는
// 표준 시스템 포함 파일 및 프로젝트 관련 포함 파일이
// 들어 있는 포함 파일입니다.
//

#pragma once

#include "targetver.h"

#define WIN32_LEAN_AND_MEAN             // 거의 사용되지 않는 내용은 Windows 헤더에서 제외합니다.
// Windows 헤더 파일:
#include <windows.h>
#include <mmsystem.h>

// C 런타임 헤더 파일입니다.
#include <stdlib.h>
#include <malloc.h>
#include <memory.h>
#include <tchar.h>
#include <time.h>

#include <conio.h> 
#include <stack>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <ctime>

// TODO: 프로그램에 필요한 추가 헤더는 여기에서 참조합니다.
#define MAX_LOADSTRING 128

#include "resource.h"
#include "Singleton.h"
#include "BaseWindow.h"
#include "TimeManager.h"
#include "Gdi.h"
#include "maze Source/MazeGenerator.h"
#include "System.h"
#include "MainProc.h"
