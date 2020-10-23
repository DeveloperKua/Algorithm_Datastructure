#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <utility>
#include <set>

using namespace std;

class myGraph {
private:
	string dataName;
	//해쉬 테이블로 이웃한 그래프 노드와 간선의 가중치 표현

public:
	unordered_map<string, int> neighbors;

	myGraph();
	myGraph(string NodeName);
	~myGraph();

public:
	string getName();
	void addNeighbor(string key, int value);

};