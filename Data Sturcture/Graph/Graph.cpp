#include "Graph.h"

myGraph::myGraph(string NodeName)
{
	dataName = NodeName;
}

myGraph::~myGraph()
{
}

string myGraph::getName()
{
	return dataName;
}

myGraph myGraph::getNeighbor()
{
	auto item = neighbors.begin();
	if (item != neighbors.end()) {
		return item->first;
	}
}

int myGraph::getWeigh()
{
	auto item = neighbors.begin();
	if (item != neighbors.end()) {
		return item->second;
	}
}

void myGraph::addNeighbor(string key, int value)
{
	neighbors.insert(make_pair(key, value));
}
