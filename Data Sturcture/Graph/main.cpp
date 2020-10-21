#include "Graph.h"

int main()
{
	myGraph seoul("seoul");
	myGraph busan("busan");

	seoul.addNeighbor(busan.getName(), 120);
	busan.addNeighbor(seoul.getName(), 130);

	cout << "서울 노드의 이웃: " << seoul.getNeighbor().getName() 
		<< " 이웃과의 가중치: " << seoul.getWeigh() << endl;

	cout << "부산 노드의 이웃: " << busan.getNeighbor().getName()
		<< " 이웃과의 가중치: " << busan.getWeigh() << endl;


}

void DijkstraAlgorithm(myGraph start, myGraph & other) { 
	unordered_map<string, int> distanceRoute;

	distanceRoute.insert(make_pair(start.getName(), 0));
}