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

public:
	unordered_map<string, int> neighbors;

	myGraph();
	myGraph(string NodeName);
	~myGraph();

public:
	string getName();
	void addNeighbor(string key, int value);

};