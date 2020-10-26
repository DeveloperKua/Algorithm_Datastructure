#include "Graph.h"
unordered_map<string, pair<string, int>> DijkstraAlgorithm(myGraph start, vector<myGraph*> other);
int main()
{
	myGraph seoul("seoul");
	myGraph busan("busan");
	myGraph chungju("chungju");
	myGraph incheon("incheon");
	myGraph jeju("jeju");

	seoul.addNeighbor(busan.getName(), 100);
	seoul.addNeighbor(incheon.getName(), 160);
	busan.addNeighbor(chungju.getName(), 120);
	busan.addNeighbor(incheon.getName(), 180);
	chungju.addNeighbor(jeju.getName(), 80);
	incheon.addNeighbor(chungju.getName(), 40);
	incheon.addNeighbor(jeju.getName(), 140);

	vector<myGraph*> other{ &busan, &chungju, &incheon, &jeju };
	
	unordered_map<string, pair<string, int>> cheapestRoute = DijkstraAlgorithm(seoul, other);

	cout << jeju.getName() <<"까지 최단 루트" << endl;
}

myGraph * findGraph(vector<myGraph*> other, string findValue) {

	for (myGraph * node : other) {
		if (node->getName() == findValue) {
			return node;
		}
	}
}

unordered_map<string, pair<string, int>> DijkstraAlgorithm(myGraph start, vector<myGraph*> other) {

	string temp = "none";
	/*	
	가장 싼 루트를 저장할 해시 해시의 key는 노드의 이름
	해시의 value는 pair를 통해 2가지 정보를 기입 
	first -  해당 노드 이전 노드
	secont - 싼 루트 가중치
	*/
	unordered_map<string, pair<string, int>> cheapestRoute;
	//cheapestRoute 값 대입 편의성을 위한 변수
	pair<string, int> cheapestRoute_Info = make_pair(start.getName(), 0);
	
	//set 컨테이너로 이미 방문 하였는지를 확인 set은 중복을 포함하지 않기에
	set<string> visited;
	myGraph * current = &start;
	//연결된 간선의 가중치
	int neighborCost;

	//초기화 작업
	cheapestRoute[start.getName()] = cheapestRoute_Info;

	for(myGraph * node : other)
	{
		cheapestRoute_Info = make_pair(node->getName(), INT32_MAX);
		cheapestRoute[node->getName()] = cheapestRoute_Info;
	}

	//알고리즘 로직
	while (current != nullptr) {
		visited.insert(current->getName());

		//현재 노드의 neighbor 모두 탐색
		for (pair<string, int> node : current->neighbors) {
			//현재 노드에서 다른 노드로 향하는 간선의 가중치가 
			//현재 RouteCost가 가진 가중치보다 값이 작으면 RouteCost 갱신
			neighborCost = cheapestRoute[node.first].second;

			if (neighborCost > node.second + neighborCost) {
				//neighborCost 초기화된 값이라면 재설정
				if (neighborCost == INT32_MAX) neighborCost = 0;
				cheapestRoute_Info = make_pair(current->getName(), node.second + neighborCost);
				cheapestRoute[node.first] = cheapestRoute_Info;
			}
		}

		current = nullptr;
		int cheapestFromCurrent = INT32_MAX;
		//다음으로 탐색할 노드 찾기
		for (pair<string, pair<string, int>> node : cheapestRoute) {
			
			neighborCost = node.second.second;

			if (neighborCost < cheapestFromCurrent && visited.insert(node.first).second) {
				cheapestFromCurrent = neighborCost;
				current = findGraph(other, node.first);
			}
		}
	}

	return cheapestRoute;
}