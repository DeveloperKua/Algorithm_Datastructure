#ifndef __MAZEGENERATOR_H
#define __MAZEGENERATOR_H

#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <string>
#include <list>
#include <random>
#include <ctime>

#define BLACK 0 
#define BLUE 1 
#define GREEN 2 
#define CYAN 3 
#define RED 4 
#define MAGENTA 5 
#define BROWN 6 
#define LIGHTGRAY 7 
#define DARKGRAY 8 
#define LIGHTBLUE 9 
#define LIGHTGREEN 10 
#define LIGHTCYAN 11 
#define LIGHTRED 12 
#define LIGHTMAGENTA 13 
#define YELLOW 14 
#define WHITE 15 

using namespace std;

const int WAIT_TICK = 1000 / 30;
  
#pragma once
class Maze {
private:
	enum TileInfo
	{
		NONE,
		WALL,
		PLAYER,
	};

	enum MoveDirection
	{
		UP,
		DOWN,
		RIGHT,
		LEFT
	};
	int TileWidth;
	int TileHeight;

	int playerX = 1;
	int playerY = 1;
public:
	TileInfo **tile;;

public:
	Maze();
	~Maze();

	void Initialize(int width, int height);
	void Render();
	void Update();

	void MazeGenerator_BinaryTree();
	void MazeGenerator_SideWinder();

	int GetRandom(int min, int max) {
		random_device ranDevice;
		mt19937 gen(ranDevice());
		uniform_int_distribution<int> dis(min, max - 1);

		return (int)dis(gen);
	}
	inline const int GetTileColor(TileInfo info) {
		switch (info)
		{
		case Maze::NONE:
			return LIGHTBLUE;
		case Maze::WALL:
			return RED;
		case Maze::PLAYER:
			return CYAN;
		default:
			return WHITE;
		}
	}

	inline const char* GetTileIcon(TileInfo info) {
		switch (info)
		{
		case Maze::NONE:
			return "  ";
		case Maze::WALL:
			return "бс";
		case Maze::PLAYER:
			return "б▌";
		default:
			return "\0";
		}
	}

	void MovePlayer(int moveDir);

	void MoveKeyInput() {

		int keyHit = 0;
		if (_kbhit()) {
			keyHit = _getch();
			switch (keyHit)
			{
			case 72: MovePlayer(UP);
				break;
			case 80: MovePlayer(DOWN);
				break;
			case 75: MovePlayer(LEFT);
				break;
			case 77: MovePlayer(RIGHT);
				break;
			}
		}

	}
};


#endif //!__MAZEGENERATOR_H
