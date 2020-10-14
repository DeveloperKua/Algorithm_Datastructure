#include "MyVector.h"
#include "MyVector.cpp";

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cusorInfo;

MyVector<int> mv_int;
MyVector<float> mv_float;
MyVector<char> mv_char;

vector<int> sv_int;
vector<float> sv_float;
vector<char> sv_char;

void show_MyVectorInfo() {
	SetConsoleTextAttribute(hConsole, 12);
	SetConsoleCursorPosition(hConsole, {0,0});
	cout << "MY Vector" << endl;

	SetConsoleCursorPosition(hConsole, { 0,2 });
	cout << "my Vector(int)  : ";
	for (int i = 0; i < mv_int.GetSize(); i++) {
		cout << mv_int.operator[](i) << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 0,3 });
	cout << "벡터 크기:" << mv_int.GetSize() << " 벡터 용량:" << mv_int.GetCapacity();
	SetConsoleCursorPosition(hConsole, { 0,4 });
	cout << "my Vector(float): ";
	for (int i = 0; i < mv_float.GetSize(); i++) {
		cout << mv_float.operator[](i) << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 0,5 });
	cout << "벡터 크기:" << mv_float.GetSize() << " 벡터 용량:" << mv_float.GetCapacity();
	SetConsoleCursorPosition(hConsole, { 0,6 });
	cout << "my Vector(char): ";
	for (int i = 0; i < mv_char.GetSize(); i++) {
		cout<< mv_char.operator[](i) << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 0,7 });
	cout << "벡터 크기:" << mv_char.GetSize() << " 벡터 용량:" << mv_char.GetCapacity();
}

void show_STLVectorInfo() {
	SetConsoleTextAttribute(hConsole, 11);
	SetConsoleCursorPosition(hConsole, { 60,0 });
	cout << "STL Vector" << endl;

	SetConsoleCursorPosition(hConsole, { 60,2 });
	cout << "stl Vector(int)  : ";
	for (int i = 0; i < sv_int.size(); i++) {
		cout << sv_int.operator[](i) << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 60,3 });
	cout << "벡터 크기:" << sv_int.size() << " 벡터 용량:" << sv_int.capacity();
	SetConsoleCursorPosition(hConsole, { 60,4 });
	cout << "stl Vector(float): ";
	for (int i = 0; i < sv_float.size(); i++) {
		cout << sv_float.operator[](i) << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 60,5 });
	cout << "벡터 크기:" << sv_float.size() << " 벡터 용량:" << sv_float.capacity();
	SetConsoleCursorPosition(hConsole, { 60,6 });
	cout << "stl Vector(char): ";
	for (int i = 0; i < sv_char.size(); i++) {
		cout << sv_char.operator[](i) << ", ";
	}
	SetConsoleCursorPosition(hConsole, { 60,7 });
	cout << "벡터 크기:" << sv_char.size() << " 벡터 용량:" << sv_char.capacity();
}


int main()
{

	int num = 1;
	int type;
	int addID_int;
	float addID_float;
	char addID_str;
	int removeID;

	while (num != 0) {
		system("cls");
		
		show_MyVectorInfo();
		show_STLVectorInfo();
		
		SetConsoleTextAttribute(hConsole, 10);

		SetConsoleCursorPosition(hConsole, { 0,9 });
		cout << "1.벡터 추가 || 2.마지막 벡터 제거 || 3.선택 제거 || 4.전체 제거 || 0.종료" << endl;
		cout << "|>>|";
		cin >> num;

		switch (num)
		{
		case 0:
			num = 0;
			break;
		case 1:
			cout << endl << "추가할 id입력" << endl;
			cout << "|>>|";
			cin >> addID_int;
			cin >> addID_float;
			cin >> addID_str;

			mv_int.Add(addID_int);
			mv_float.Add(addID_float);
			mv_char.Add(addID_str);

			sv_int.push_back(addID_int);
			sv_float.push_back(addID_float);
			sv_char.push_back(addID_str);
			break;
		case 2:
			mv_int.pop_back();
			mv_float.pop_back();
			mv_char.pop_back();

			sv_int.pop_back();
			sv_float.pop_back();
			sv_char.pop_back();
			
			break;
		case 3:
			cout << endl << "제거할 위치 입력(0부터)" << endl;
			cout << "|>>|";
			cin >> removeID;
			if (removeID >= mv_int.GetSize()) {

				cout << endl << "해당 위치에는 벡터 자료가 존재하지 않습니다." << endl;
				Sleep(500);
				break;
			}

			mv_int.erase(removeID);
			mv_float.erase(removeID);
			mv_char.erase(removeID);

			sv_int.erase(sv_int.begin() + (removeID));
			sv_float.erase(sv_float.begin() + (removeID));
			sv_char.erase(sv_char.begin() + (removeID));
			break;

		case 4:

			mv_int.RemoveAll();
			mv_float.RemoveAll();
			mv_char.RemoveAll();

			sv_int.clear();
			sv_float.clear();
			sv_char.clear();
			break;
		}
	}

	system("PAUSE");

	return 0;
}