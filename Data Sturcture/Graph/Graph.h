#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

class myGraph {
private:
	string dataName;
	//해쉬 테이블로 이웃한 그래프 노드와 간선의 가중치 표현

public:
	unordered_map<string, int> neighbors;

	myGraph(string NodeName);
	~myGraph();

public:
	string getName();
	myGraph getNeighbor();
	int getWeigh();
	void addNeighbor(string key, int value);

};