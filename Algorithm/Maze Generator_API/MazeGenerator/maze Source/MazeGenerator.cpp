#include "MazeGenerator.h"
HANDLE hConsole;
CONSOLE_CURSOR_INFO cusorInfo;
COORD pos;


cMaze::cMaze()
{
	
}

cMaze::~cMaze()
{
	for (int i = 0; i < mMazeHeight; ++i) {
		delete[] Maze[i];
	}
	delete[] Maze;
}

void cMaze::Initialize()
{
	mMazeWidth = WIDTH / gTileSize;
	mMazeHeight = HEIGHT / gTileSize;

	Maze = new cTile*[mMazeHeight];
	for (int i = 0; i < mMazeHeight; ++i) {
		Maze[i] = new cTile[mMazeWidth];
		memset(Maze[i], 0, sizeof(int) * mMazeWidth);
	}

	for (int y = 0; y < mMazeHeight; y++)
	{
		for (int x = 0; x < mMazeWidth; x++)
		{
			Maze[y][x].mX = x;
			Maze[y][x].mY = y;
			Maze[y][x].bIsWallOpen[0] = true;
			Maze[y][x].bIsWallOpen[1] = true;
			Maze[y][x].bIsWallOpen[2] = true;
			Maze[y][x].bIsWallOpen[3] = true;
		}
	}
	bIsCompleteGenerated = false;
	//MazeGenerator_BinaryTree();
	//MazeGenerator_SideWinder();
	//MazeGenerator_RecursiveBacktracking();
	//default_Maze();
}

void cMaze::Render(HDC hdc)
{
	for (int y = 0; y < mMazeHeight; y++)
	{
		for (int x = 0; x < mMazeWidth; x++)
		{
			Maze[y][x].drawLine(hdc);
		}
	}

}

void cMaze::Update()
{
	//MoveKeyInput();
	//MovePlayer(GetRandom(0, 4));
	//Sleep(100);
}

void cMaze::default_Maze(HDC hdc)
{
	for (int y = 0; y < mMazeHeight; y++)
	{
		for (int x = 0; x < mMazeWidth; x++)
		{
			Maze[y][x].drawLine(hdc); 
		}
	}
}

void cMaze::MazeGenerator_BinaryTree(HDC hdc)
{
	if (bIsCompleteGenerated) return;

	for (int y = 0; y < mMazeHeight; y++)
	{
		for (int x = 0; x < mMazeWidth; x++)
		{
			if (y == mMazeHeight - 1 && x == mMazeWidth - 1)
				continue;
			if (y == mMazeHeight - 1) {
				OpenWall(RIGHT, x, y);
				continue;
			}

			if (x == mMazeWidth - 1) {
				OpenWall(BOTTOM, x, y);
				continue;
			}

			if (GetRandom(0, 2) == 0)
				OpenWall(RIGHT, x, y);
			else
				OpenWall(BOTTOM, x, y);
		}
	}

	bIsCompleteGenerated = true;
}

void cMaze::MazeGenerator_SideWinder(HDC hdc)
{
	if (bIsCompleteGenerated) return;

	for (int y = 0; y < mMazeHeight; y++)
	{
		int count = 0;
		for (int x = 0; x < mMazeWidth; x++)
		{
		/*	if (y == mMazeHeight - 1 && x == mMazeWidth - 1)
				continue;*/
			if (y == 0) {
				if(x == mMazeWidth - 1) continue;
				OpenWall(RIGHT, x, y);
				continue;
			}

			if (GetRandom(0, 1) == 0 || x + 1 == mMazeWidth) {
				int RandomX = GetRandom(x - count, x);
				count = 0;
				OpenWall(TOP, RandomX, y);
			}
			else if(x + 1 < mMazeWidth){
				OpenWall(RIGHT, x, y);
				++count;
			}
			this->Render(hdc);
		}
	}
	bIsCompleteGenerated = true;

}

void cMaze::MazeGenerator_RecursiveBacktracking(HDC hdc)
{
	for (int y = 0; y < mMazeHeight; y++)
	{
		for (int x = 0; x < mMazeWidth; x++)
		{
			//Maze[y][x].drawLine(hdc);
		}
	}
	bIsCompleteGenerated = true;

}

