#include "../stdafx.h"
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
	mMazeWidth = 800 / gTileSize;
	mMazeHeight = 800 / gTileSize;
	visitedCellCount = 1;
	
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

	curTile = &Maze[0][0];

	//MazeGenerator_BinaryTree();
	//MazeGenerator_SideWinder();
	//MazeGenerator_RecursiveBacktracking();
	//default_Maze();

	g_pInputManager->SetInputHandler(this);

}

void cMaze::Render()
{
	for (int y = 0; y < mMazeHeight; y++)
	{
		for (int x = 0; x < mMazeWidth; x++)
		{
			Maze[y][x].drawLine();
		}
	}
}

void cMaze::default_Maze()
{
	this->Render();
}

void cMaze::MazeGenerator_BinaryTree()
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

			if (GetRandom(0, 1) == 0)
				OpenWall(RIGHT, x, y);
			else
				OpenWall(BOTTOM, x, y);
		}
	}
	this->Render();
	
	bIsCompleteGenerated = true;
}

void cMaze::MazeGenerator_SideWinder()
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
		}
	}
	bIsCompleteGenerated = true;

}

void cMaze::MazeGenerator_RecursiveBacktracking()
{

	//다음 타일 랜덤 선정(checkNeighborTiles)
	curTile->bIsVisited = true;
	cTile * nextTile = this->checkNeighborTiles(*curTile);

	if (visitedCellCount < mMazeWidth * mMazeHeight) {
		if (nextTile != nullptr) {
			nextTile->bIsVisited = true;

			//stack push
			tileStack.push(curTile);

			//벽 제거
			OpenWall(curTile, nextTile);

			//현재 타일 갱신
			curTile = nextTile;

			//알고리즘 종료 여부 확인을 위한 카운트
			visitedCellCount++;
		}
		else if (!tileStack.empty()) {

			curTile = tileStack.top();
			tileStack.pop();
		}
	}
	this->Render();
	curTile->drawCurrentTileRect();


	Sleep(50);
}

void cMaze::KeyboardHandler(void)
{
	if (g_pKeyCodeScan(VK_LEFT)) {
		_tprintf(_T("mode 2 \n"));
	}

	if (g_pKeyCodeScan(VK_F1)) { mazeAlgorithmType = 0; }
	if (g_pKeyCodeScan(VK_F2)) { mazeAlgorithmType = 1; 
	_tprintf(_T("mode 2 \n"));

	}
}

void cMaze::MouseHandler(MOUSESTATE diMouseState)
{
}


