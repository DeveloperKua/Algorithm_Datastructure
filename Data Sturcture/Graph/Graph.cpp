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

void myGraph::addNeighbor(myGraph* key, int value)
{
	neighbors.insert(make_pair(key, value));
}
