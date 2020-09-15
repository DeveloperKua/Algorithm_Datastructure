#include "MazeGenerator.h"

int main()
{
	cusorInfo.bVisible = false;
	cusorInfo.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &cusorInfo);

	Maze maze;
	maze.Initialize();

	int lastTick = 0;
	while (true) {
	#pragma region FrameSet
		int currentTick = GetTickCount();
		if (currentTick - lastTick < WAIT_TICK)
			continue;
		lastTick = currentTick;
	#pragma endregion

		SetConsoleCursorPosition(hConsole, pos);
		SetConsoleTextAttribute(hConsole, 12);
		for (int i = 0; i < 25; i++) 
		{
			for (int j = 0; j < 25; j++) 
			{
				
				cout << "■";
			}
			cout << endl;
		}
	}
}
