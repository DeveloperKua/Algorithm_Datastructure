#include "BinaryTree.h"
#include "BinaryTree.cpp"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cusorInfo;

MyBinaryTree<int> BinaryTree;

template<typename T>
void show_BinaryTree(TreeNode<T>* Node, COORD Pos) {

	if (Node == nullptr) return;
	SetConsoleCursorPosition(hConsole, Pos);

	cout << Node->getData() << endl;

	COORD LPos = { Pos.X - 2, Pos.Y + 1 };
	show_BinaryTree(Node->getLeftChild(), LPos);

	COORD RPos = { Pos.X + 2, Pos.Y + 1 };
	show_BinaryTree(Node->getRightChild(), RPos);

}

void display() {
	SetConsoleTextAttribute(hConsole, 12);
	SetConsoleCursorPosition(hConsole, { 0,0 });
	cout << "Current Tree" << endl;

	COORD Pos = { 13,1 };
	SetConsoleCursorPosition(hConsole, Pos);

	show_BinaryTree(BinaryTree.getRootNode(), Pos);
}

int main()
{
	int num = 1;
	int utilData;

	while (num != 0) {
		system("cls");

		display();

		SetConsoleTextAttribute(hConsole, 10);

		SetConsoleCursorPosition(hConsole, { 0,9 });
		cout << "1.노드 추가 || 2.노드 제거 || 3.노드 검색 || 4.전체 제거 || 0.종료" << endl;
		cout << "|>>|";
		cin >> num;

		switch (num)
		{
		case 0:
			num = 0;
			break;
		case 1:
			cout << endl << "추가할 노드 값 입력" << endl;
			cout << "|>>|";
			cin >> utilData;
			
			BinaryTree.insert(utilData, BinaryTree.getRootNode());
			break;
		case 2:
			cout << endl << "제거할 노드 값 입력" << endl;
			cout << "|>>|";
			cin >> utilData;

			BinaryTree.remove(utilData, BinaryTree.getRootNode());

			break;
		case 3:
			cout << endl << "검색할 값 입력" << endl;
			cout << "|>>|";
			cin >> utilData;
			
			BinaryTree.Search(utilData, BinaryTree.getRootNode());

			break;

		case 4:

			break;
		}
	}

	system("PAUSE");

	return 0;
}
