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

void cMaze::Initialize(int width, int height)
{
	mMazeWidth = WIDTH / gTileSize;
	mMazeHeight = HEIGHT / gTileSize;

	Maze = new cTile*[mMazeHeight];
	for (int i = 0; i < mMazeHeight; ++i) {
		Maze[i] = new cTile[mMazeWidth];
		memset(Maze[i], 0, sizeof(int) * mMazeWidth);
	}

	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			Maze[y][x].x = x;
			Maze[y][x].y = y;
			Maze[y][x].bIsWallOpen[0] = true;
			Maze[y][x].bIsWallOpen[1] = true;
			Maze[y][x].bIsWallOpen[2] = true;
			Maze[y][x].bIsWallOpen[3] = true;
		}
	}

	//MazeGenerator_BinaryTree();
	//MazeGenerator_SideWinder();
	//MazeGenerator_RecursiveBacktracking();
	//default_Maze();
}

void cMaze::Render()
{
	SetConsoleCursorPosition(hConsole, pos);
	SetConsoleTextAttribute(hConsole, 12);
	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			SetConsoleTextAttribute(hConsole, GetTileColor(tile[y][x]));
			if(isGoaled) tile[playerY][playerX] = GOALED_PLAYER;
			else tile[playerY][playerX] = PLAYER;
			cout << GetTileIcon(tile[y][x]);
		}
		cout << endl;
	}
}

void cMaze::Update()
{
	MoveKeyInput();
	//MovePlayer(GetRandom(0, 4));
	//Sleep(100);
}

void cMaze::default_Maze()
{
	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			//tile[y][x] = WALL;
		}
	}
}

void cMaze::MazeGenerator_BinaryTree()
{
	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			if (x % 2 == 0 || y % 2 == 0) 
				tile[y][x] = WALL;
			else
				tile[y][x] = NONE;
		}
	}

	//for (int y = 0; y < TileHeight; y++)
	//{
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

	//		if (GetRandom(0, 2) == 0)
	//			tile[y][x + 1] = NONE;
	//		else
	//			tile[y + 1][x] = NONE;

	//	}
	//}
}

void cMaze::MazeGenerator_SideWinder()
{
	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				tile[y][x] = WALL;
			else
				tile[y][x] = NONE;
		}
	}

	for (int y = 0; y < TileHeight; y++)
	{
		int count = 1;
		for (int x = 0; x < TileWidth; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				continue;
			if (y == TileHeight - 2 && x == TileWidth - 2)
				continue;
			if (y == TileHeight - 2) {
				tile[y][x + 1] = NONE;
				continue;
			}

			if (x == TileWidth - 2) {
				tile[y + 1][x] = NONE;
				continue;
			}

			if (GetRandom(0, 2) == 0) {
				tile[y][x + 1] = NONE;
				++count;
			}
			else {
				int RandomX = GetRandom(0, count);
				tile[y + 1][x - RandomX * 2] = NONE;
				count = 1;
			}
		}
	}
}

void cMaze::MazeGenerator_RecursiveBacktracking()
{
	for (int y = 0; y < TileHeight; y++)
	{
		for (int x = 0; x < TileWidth; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				tile[y][x] = WALL;
			else
				tile[y][x] = NONE;
		}
	}
}

void cMaze::MovePlayer(int moveDir)
{
	int moveX = 0;
	int moveY = 0;
	switch (moveDir)
	{
	case Maze::UP:
		moveY -= 1;
		break;
	case Maze::DOWN:
		moveY += 1;
		break;
	case Maze::RIGHT:
		moveX += 1;
		break;
	case Maze::LEFT:
		moveX -=1;
		break;
	}
	
	if (tile[playerY + moveY][playerX + moveX] == NONE) {
		
		if (playerY == goalY && playerX == goalX) tile[playerY][playerX] = GOAL;
		else tile[playerY][playerX] = NONE;
		playerY += moveY;
		playerX += moveX;
		isGoaled = false;
	}
	else if (tile[playerY + moveY][playerX + moveX] == GOAL) {
		tile[playerY][playerX] = NONE;
		playerY += moveY;
		playerX += moveX;
		isGoaled = true;
	}
	else return;
}
