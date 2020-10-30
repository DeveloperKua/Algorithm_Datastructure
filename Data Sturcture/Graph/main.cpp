#include "Graph.h"
void dijkstraAlgorithm(myGraph start, myGraph end, vector<myGraph*> other);
int main()
{
	myGraph seoul("seoul");
	myGraph busan("busan");
	myGraph chungju("chungju");
	myGraph incheon("incheon");
	myGraph jeju("jeju");

	seoul.addNeighbor(&busan, 100);
	seoul.addNeighbor(&incheon, 160);
	busan.addNeighbor(&chungju, 120);
	busan.addNeighbor(&incheon, 180);
	chungju.addNeighbor(&jeju, 80);
	incheon.addNeighbor(&chungju, 40);
	incheon.addNeighbor(&jeju, 140);

	vector<myGraph*> other{ &busan, &chungju, &incheon, &jeju };
	
	dijkstraAlgorithm(seoul, jeju,other);

}

myGraph * findGraph(vector<myGraph*> other, string findValue) {

	for (myGraph * node : other) {
		if (node->getName() == findValue) {
			return node;
		}
	}
}

void dijkstraAlgorithm(myGraph start, myGraph end, vector<myGraph*> other) {

	/*	
	가장 싼 루트를 저장할 해시 해시의 key는 노드의 이름
	해시의 value는 pair를 통해 2가지 정보를 기입 
	first -  해당 노드 이전 노드
	secont - 싼 루트 가중치
	*/
	unordered_map<string, pair<string, int>> cheapestRoute;
	priority_queue<pair<myGraph*, int>> pQueue; //우선순위 큐
	
	myGraph * current;

	//초기화 작업
	cheapestRoute[start.getName()] = make_pair(start.getName(), 0);
	pQueue.push(make_pair(&start, 0));
	for(myGraph * node : other) cheapestRoute[node->getName()] = make_pair(node->getName(), INT32_MAX);

	//알고리즘 로직
	while (!pQueue.empty()) {
		current = pQueue.top().first;
		int currentCost = -pQueue.top().second;

		pQueue.pop();
		//현재 노드의 neighbor 모두 탐색
		for (pair<myGraph*, int> curNeighbor : current->neighbors) {
			//지금 탐색중인 현재 노드의 이웃의 cheapestRoute가 가진 값
			int cur_routeCost = cheapestRoute[curNeighbor.first->getName()].second;
			int newCost = curNeighbor.second + currentCost;
			//현재 노드에서 다른 노드로 향하는 간선의 가중치가 현재 RouteCost가 가진 가중치보다 값이 작으면 RouteCost 갱신
			if (cur_routeCost > newCost) {
				cheapestRoute[curNeighbor.first->getName()] = make_pair(current->getName(), newCost);
				pQueue.push(make_pair(curNeighbor.first, -newCost));
			}
		}
	}

	cout << " d";
}

/*unordered_map<string, pair<string, int>> dijkstraAlgorithm(myGraph start, myGraph end, vector<myGraph*> other) {

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

	for (myGraph * node : other)
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

			if (neighborCost > node.second + cheapestRoute[current->getName()].second) {
				//neighborCost 초기화된 값이라면 재설정
				if (neighborCost == INT32_MAX) neighborCost = 0;
				cheapestRoute_Info = make_pair(current->getName(), node.second + cheapestRoute[current->getName()].second);
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
				visited.erase(node.first);
			}
		}
	}

	return cheapestRoute;
}*/