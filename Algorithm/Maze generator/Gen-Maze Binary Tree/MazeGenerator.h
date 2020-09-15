#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <list>

using namespace std;

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cusorInfo;
COORD pos = { 0,0 };

const int WAIT_TICK = 1000 / 30;

#pragma once
class Maze {
private:

public:
	Maze();
	~Maze();

	void Initialize();

};

