#pragma once
#include <unordered_map>
#include <map>
#include <string>
#include <iostream>
#include <Windows.h>
#include <algorithm>
#include <utility>
#include <set>
#include <queue>

using namespace std;

class myGraph {
private:
	string dataName;

public:
	map<myGraph*, int> neighbors;

	myGraph();
	myGraph(string NodeName);
	~myGraph();

public:
	string getName();
	void addNeighbor(myGraph* key, int value);

};
