#pragma once
#include <Windows.h>
#include <conio.h> 

#include <stack>
#include <iostream>
#include <string>
#include <chrono>
#include <vector>
#include <list>
#include <random>
#include <ctime>

#include "../System.h"


using namespace std;

const int gTileSize = 40;

#pragma once
class cMaze {

	int mMazeWidth;
	int mMazeHeight;

public:
	friend cTile;
	cTile **Maze;

public:
	cMaze();
	~cMaze();

	void Initialize(int width, int height);
	void Render();
	void Update();

	void default_Maze();
	void MazeGenerator_BinaryTree();
	void MazeGenerator_SideWinder();
	void MazeGenerator_RecursiveBacktracking();

	int GetRandom(int min, int max) {
		random_device ranDevice;
		mt19937 gen(ranDevice());
		uniform_int_distribution<int> dis(min, max - 1);

		return (int)dis(gen);
	}
};


class cTile {
public:
	int mX, mY;
	bool bIsWallOpen[4] = { true, true, true, true };

	cTile(int _x, int _y) {
		mX = _x;
		mY = _y;
	};

	cTile() {
		mX = 0;
		mY = 0;
	};

	void drawLine(HDC hdc) {
		int drawX = mX * gTileSize;
		int drawY = mY * gTileSize;

		/*
	(drawX,drawY)        (drawX + gTileSize ,drawY)
	      Ｋ							 Ｉ
			忙式式式式式式式式式式式式式式式式式式式式式式式忖
			弛						弛
			弛					    弛
			弛					    弛
			弛					    弛
			弛					    弛
			弛					    弛
			弛					    弛
			弛					    弛
			戌式式式式式式式式式式式式式式式式式式式式式式式戎
		   Ｈ						 Ｊ
(drawX,drawY + gTileSize)        (drawX + gTileSize ,drawY)
		*/

		//Cell top Wall
		if (bIsWallOpen[0]) MyLineTo(hdc, drawX, drawY, drawX + gTileSize, drawY);

		//Cell right Wall
		if (bIsWallOpen[1]) MyLineTo(hdc, drawX + gTileSize, drawY, drawX + gTileSize, drawY + gTileSize);

		//Cell bottom Wall
		if (bIsWallOpen[2]) MyLineTo(hdc, drawX + gTileSize, drawY + gTileSize, drawX, drawY + gTileSize);

		//Cell left Wall
		if (bIsWallOpen[3]) MyLineTo(hdc, drawX, drawY + gTileSize, drawX, drawY);
	}

	void MyLineTo(HDC hdc, int startX, int startY, int endX, int endY) {
		MoveToEx(hdc, startX, startY, NULL);
		LineTo(hdc, endX, endY);
	}
};
