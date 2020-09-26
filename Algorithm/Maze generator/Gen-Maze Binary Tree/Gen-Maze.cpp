#include "MazeGenerator.h"

int main()
{
	Maze maze;
	maze.Initialize(21,21);

	int lastTick = 0;
	while (true) {
	#pragma region FrameSet
		int currentTick = GetTickCount();
		if (currentTick - lastTick < WAIT_TICK)
			continue;
		lastTick = currentTick;
	#pragma endregion
		maze.Render();
		maze.Update();
		
	}
}
