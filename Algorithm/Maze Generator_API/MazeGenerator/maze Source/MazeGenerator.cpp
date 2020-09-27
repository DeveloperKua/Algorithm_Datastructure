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

	static DWORD time;

	if (GetTickCount() - time >= 50) {

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

				Render(hdc);
			}
		}
	}
	time = GetTickCount();
	Render(hdc);


	bIsCompleteGenerated = true;
}

void cMaze::MazeGenerator_SideWinder(HDC hdc)
{
	for (int y = 0; y < mMazeHeight; y++)
	{
		for (int x = 0; x < mMazeWidth; x++)
		{
			//Maze[y][x].drawLine(hdc);
		}
	}

	//for (int y = 0; y < TileHeight; y++)
	//{
	//	int count = 1;
	//	for (int x = 0; x < TileWidth; x++)
	//	{
	//		if (x % 2 == 0 || y % 2 == 0)
	//			continue;
	//		if (y == TileHeight - 2 && x == TileWidth - 2)
	//			continue;
	//		if (y == TileHeight - 2) {
	//			tile[y][x + 1] = NONE;
	//			continue;
	//		}

	//		if (x == TileWidth - 2) {
	//			tile[y + 1][x] = NONE;
	//			continue;
	//		}

	//		if (GetRandom(0, 2) == 0) {
	//			tile[y][x + 1] = NONE;
	//			++count;
	//		}
	//		else {
	//			int RandomX = GetRandom(0, count);
	//			tile[y + 1][x - RandomX * 2] = NONE;
	//			count = 1;
	//		}
	//	}
	//}
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

