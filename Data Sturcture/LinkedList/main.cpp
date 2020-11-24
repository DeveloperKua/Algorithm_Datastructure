#include "LinkedList.h"
#include "LinkedList.cpp"


HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cusorInfo;

LinkedList<int> ml_int;
LinkedList<float> ml_float;
LinkedList<char> ml_char;

list<int> sl_int;
list<float> sl_float;
list<char> sl_char;

#pragma region UtilFunc
void show_myListInfo();
void show_stlListInfo();
void show_myListInfo();
void show_stlListInfo();
void push_front_AllList();
void push_back_AllList();
void pop_front_AllList();
void pop_back_AllList();
void clear_AllList();
void insert_AllList();
void erase_AllList();
#pragma endregion

int addID_int;
float addID_float;
char addID_str;

int main()
{
	sl_int.reverse();
	int num = 1;
	
	while (num != 0) {

		system("cls");
		show_myListInfo();
		show_stlListInfo();

		SetConsoleTextAttribute(hConsole, 10);
		SetConsoleCursorPosition(hConsole, { 0,9 });
		cout << "1.Push_front || 2.Push_back || 3.Pop_front || 4.Pop_back" << endl;
		cout << "5.Clear  || 6.insert || 7.erase || 0.종료" << endl;
		cout << "|>>|";
		cin >> num;

		switch (num)
		{
		case 0:
			num = 0;
			break;
		case 1:
			push_front_AllList();
			break;
		case 2:
			push_back_AllList();
			break;
		case 3:
			pop_front_AllList();
			break;
		case 4:
			pop_back_AllList();
			break;

		case 5:
			clear_AllList();
			break;

		case 6:
			insert_AllList();
			break;

		case 7:
			erase_AllList();
			break;
		}

	}
}

void show_myListInfo() {
	SetConsoleTextAttribute(hConsole, 12);
	SetConsoleCursorPosition(hConsole, { 0,0 });
	cout << "MY List" << endl;

	SetConsoleCursorPosition(hConsole, { 0,2 });
	cout << "my List(int)  : ";
	for (int i = 0; i < ml_int.size(); i++) {
		cout << ml_int.SearchNode(i)->getData() << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 0,3 });
	cout << "리스트 크기:" << ml_int.size();

	SetConsoleCursorPosition(hConsole, { 0,4 });
	cout << "my List(float): ";
	for (int i = 0; i < ml_float.size(); i++) {
		cout << ml_float.SearchNode(i)->getData() << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 0,5 });
	cout << "리스트 크기:" << ml_float.size();

	SetConsoleCursorPosition(hConsole, { 0,6 });
	cout << "my List(char): ";
	for (int i = 0; i < ml_char.size(); i++) {
		cout << ml_char.SearchNode(i)->getData() << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 0,7 });
	cout << "리스트 크기:" << ml_char.size();
}

void show_stlListInfo() {
	SetConsoleTextAttribute(hConsole, 11);
	SetConsoleCursorPosition(hConsole, { 60,0 });
	cout << "STL List" << endl;

	SetConsoleCursorPosition(hConsole, { 60,2 });
	cout << "stl List(int)  : ";
	for (list<int>::iterator it = sl_int.begin(); it != sl_int.end(); ++it) {
		cout << *it << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 60,3 });
	cout << "리스트 크기:" << sl_int.size();

	SetConsoleCursorPosition(hConsole, { 60,4 });
	cout << "stl List(float): ";
	for (list<float>::iterator it = sl_float.begin(); it != sl_float.end(); ++it) {
		cout << *it << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 60,5 });
	cout << "리스트 크기:" << sl_float.size();

	SetConsoleCursorPosition(hConsole, { 60,6 });
	cout << "stl List(char): ";
	for (list<char>::iterator it = sl_char.begin(); it != sl_char.end(); ++it) {
		cout << *it << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 60,7 });
	cout << "리스트 크기:" << sl_char.size();
}

void push_front_AllList() {

	cout << endl << "추가할 id입력" << endl;
	cout << "|>>|";
	cin >> addID_int;
	cin >> addID_float;
	cin >> addID_str;

	ml_int.push_front(addID_int);
	ml_float.push_front(addID_float);
	ml_char.push_front(addID_str);

	sl_int.push_front(addID_int);
	sl_float.push_front(addID_float);
	sl_char.push_front(addID_str);
}

void push_back_AllList() {

	cout << endl << "추가할 id입력" << endl;
	cout << "|>>|";
	cin >> addID_int;
	cin >> addID_float;
	cin >> addID_str;

	ml_int.push_back(addID_int);
	ml_float.push_back(addID_float);
	ml_char.push_back(addID_str);

	sl_int.push_back(addID_int);
	sl_float.push_back(addID_float);
	sl_char.push_back(addID_str);
}

void pop_front_AllList() {
	ml_int.pop_front();
	ml_float.pop_front();
	ml_char.pop_front();

	sl_int.pop_front();
	sl_float.pop_front();
	sl_char.pop_front();
}

void pop_back_AllList() {
	ml_int.pop_back();
	ml_float.pop_back();
	ml_char.pop_back();

	sl_int.pop_back();
	sl_float.pop_back();
	sl_char.pop_back();
}

void clear_AllList() {
	ml_int.clear();
	ml_float.clear();
	ml_char.clear();

	sl_int.clear();
	sl_float.clear();
	sl_char.clear();
}

void insert_AllList() {

	int insertIndex;
	cout << endl << "추가할 id입력" << endl;
	cout << "|>>|";
	cin >> addID_int;
	cin >> addID_float;
	cin >> addID_str;

	cout << endl << "추가할 위치" << endl;
	cout << "|>>|";
	cin >> insertIndex;

	ml_int.insert(insertIndex, addID_int);
	ml_float.insert(insertIndex, addID_float);
	ml_char.insert(insertIndex, addID_str);

	list<int>::iterator intListIter = sl_int.begin();
	list<float>::iterator floatListIter = sl_float.begin();
	list<char>::iterator charListIter = sl_char.begin();
	for (int i = 0; i < insertIndex; i++) {
		++intListIter;
		++floatListIter;
		++charListIter;
	}
	sl_int.insert(intListIter, addID_int);
	sl_float.insert(floatListIter, addID_float);
	sl_char.insert(charListIter, addID_str);
}

void erase_AllList() {

	int eraseIndex;
	cout << endl << "삭제할 위치" << endl;
	cout << "|>>|";
	cin >> eraseIndex;

	ml_int.erase(eraseIndex);
	ml_float.erase(eraseIndex);
	ml_char.erase(eraseIndex);

	list<int>::iterator intListIter = sl_int.begin();
	list<float>::iterator floatListIter = sl_float.begin();
	list<char>::iterator charListIter = sl_char.begin();
	for (int i = 0; i < eraseIndex; i++) {
		++intListIter;
		++floatListIter;
		++charListIter;
	}
	sl_int.erase(intListIter);
	sl_float.erase(floatListIter);
	sl_char.erase(charListIter);
}
