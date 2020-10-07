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

//미로 생성 과정을 화면에 렌더하기 위해 수정한 code
void cMaze::MazeGenerator_BinaryTree()
{
	curTile->bIsVisited = true;
	cTile * nextTile;
	//x가 마지막일 경우 y 갱신
	if (curTile->mX == mMazeWidth - 1) { nextTile = &Maze[curTile->mY + 1][0]; }
	else { nextTile = &Maze[curTile->mY][curTile->mX + 1]; }

	if (visitedCellCount < mMazeWidth * mMazeHeight) {

		#pragma region MazeConner Exception Handling
		if (curTile->mY == mMazeHeight - 1 && curTile->mX == mMazeWidth - 1) {
			curTile = nextTile;
			visitedCellCount++;
			return;
		}
		if (curTile->mY == mMazeHeight - 1) {
			OpenWall(RIGHT, curTile->mX, curTile->mY);
			curTile = nextTile;
			visitedCellCount++;
			return;
		}
		if (curTile->mX == mMazeWidth - 1) {
			OpenWall(BOTTOM, curTile->mX, curTile->mY);
			curTile = nextTile;
			visitedCellCount++;
			return;
		}
		#pragma endregion

		if (GetRandom(0, 1) == 0)
			OpenWall(RIGHT, curTile->mX, curTile->mY);
		else
			OpenWall(BOTTOM, curTile->mX, curTile->mY);

		curTile = nextTile;
		visitedCellCount++;
	}
	this->Render();
}

//미로 생성 과정을 화면에 렌더하기 위해 수정한 code
void cMaze::MazeGenerator_SideWinder()
{
	if (visitedCellCount < mMazeWidth * mMazeHeight) {

		curTile->bIsVisited = true;
		cTile * nextTile;
		//x가 마지막일 경우 y 갱신
		if (curTile->mX == mMazeWidth - 1) { nextTile = &Maze[curTile->mY + 1][0]; }
		else { nextTile = &Maze[curTile->mY][curTile->mX + 1]; }

		//side winder code
		if (curTile->mY == 0) {
			if (curTile->mX != mMazeWidth - 1)
				OpenWall(RIGHT, curTile->mX, curTile->mY);
		}
		else if (GetRandom(0, 1) == 0 || curTile->mX + 1 == mMazeWidth) {
			int RandomX = GetRandom(curTile->mX - SideWinderCount, curTile->mX);
			SideWinderCount = 0;
			OpenWall(TOP, RandomX, curTile->mY);
		}
		else if (curTile->mX + 1 != mMazeWidth) {
			OpenWall(RIGHT, curTile->mX, curTile->mY);
			SideWinderCount++;
		}
		curTile = nextTile;
		visitedCellCount++;
	}
	this->Render();
	Sleep(0);

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

}

void cMaze::KeyboardHandler(void)
{

	if (g_pKeyCodeScan(VK_F1)) { 
		mazeAlgorithmType = 1; 
		ResetMaze();
	}
	if (g_pKeyCodeScan(VK_F2)) { 
		mazeAlgorithmType = 2; 
		ResetMaze();
		visitedCellCount = 0;
	}
	if (g_pKeyCodeScan(VK_F3)) { 
		mazeAlgorithmType = 3; 
		ResetMaze();
	}
	if (!g_pKeyCodeScan(VK_F1)) { isReset = false; }
	if (!g_pKeyCodeScan(VK_F2)) { isReset = false; }
	if (!g_pKeyCodeScan(VK_F3)) { isReset = false; }
}

void cMaze::MouseHandler(MOUSESTATE diMouseState)
{
}

//기존 binary tree code
/*void cMaze::MazeGenerator_BinaryTree()
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
}*/

//기존 sidewinder 코드
/*void cMaze::MazeGenerator_SideWinder()
{
	if (bIsCompleteGenerated) return;

	for (int y = 0; y < mMazeHeight; y++)
	{
		int count = 0;
		for (int x = 0; x < mMazeWidth; x++)
		{
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
	this->Render();

	bIsCompleteGenerated = true;

}*/


