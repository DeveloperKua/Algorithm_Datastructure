#include "MazeGenerator.h"
HANDLE hConsole;
CONSOLE_CURSOR_INFO cusorInfo;
COORD pos;

Maze::Maze()
{
	hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	cusorInfo.bVisible = false;
	cusorInfo.dwSize = 1;

	SetConsoleCursorInfo(hConsole, &cusorInfo);
	
	pos = { 0,0 };
}

Maze::~Maze()
{
	for (int i = 0; i < TileHeight; ++i) {
		delete[] tile[i];
	}
	delete[] tile;
}

void Maze::Initialize(int width, int height)
{
	TileWidth = width;
	TileHeight = height;

	tile = new TileInfo*[TileHeight];
	for (int i = 0; i < TileHeight; ++i) {
		tile[i] = new TileInfo[TileWidth];
		memset(tile[i], 0, sizeof(int) * TileWidth);
	}

	//MazeGenerator_BinaryTree();
	MazeGenerator_SideWinder();
}

void Maze::Render()
{
	SetConsoleCursorPosition(hConsole, pos);
	SetConsoleTextAttribute(hConsole, 12);
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			SetConsoleTextAttribute(hConsole, GetTileColor(tile[y][x]));
			tile[playerY][playerX] = PLAYER;
			cout << GetTileIcon(tile[y][x]);
		}
		cout << endl;
	}
}

void Maze::Update()
{
	MoveKeyInput();
	//MovePlayer(GetRandom(0, 4));
	//Sleep(100);
}

void Maze::MazeGenerator_BinaryTree()
{
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				tile[y][x] = WALL;
			else
				tile[y][x] = NONE;
		}
		cout << endl;
	}

	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
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

			if (GetRandom(0, 2) == 0)
				tile[y][x + 1] = NONE;
			else
				tile[y + 1][x] = NONE;

		}
		cout << endl;
	}
}

void Maze::MazeGenerator_SideWinder()
{
	for (int y = 0; y < 25; y++)
	{
		for (int x = 0; x < 25; x++)
		{
			if (x % 2 == 0 || y % 2 == 0)
				tile[y][x] = WALL;
			else
				tile[y][x] = NONE;
		}
		cout << endl;
	}

	for (int y = 0; y < 25; y++)
	{
		int count = 1;
		for (int x = 0; x < 25; x++)
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
		cout << endl;
	}
}

void Maze::MovePlayer(int moveDir)
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
		tile[playerY][playerX] = NONE;
		playerY += moveY;
		playerX += moveX;
	}
	else return;
}
