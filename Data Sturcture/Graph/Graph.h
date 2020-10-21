#pragma once
#include <unordered_map>
#include <string>
#include <iostream>
#include <Windows.h>

using namespace std;

class myGraph {
private:
	string dataName;
	//�ؽ� ���̺�� �̿��� �׷��� ���� ������ ����ġ ǥ��

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