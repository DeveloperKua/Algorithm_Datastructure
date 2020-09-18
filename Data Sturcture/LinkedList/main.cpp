#include "LinkedList.h"

HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
CONSOLE_CURSOR_INFO cusorInfo;

LinkedList<int> ml_int;
LinkedList<float> ml_float;
LinkedList<char> ml_char;

list<int> sl_int;
list<float> sl_float;
list<char> sl_char;

int main()
{
	ml_int.push_back(1);
	ml_int.push_back(2);
	ml_int.push_back(3);
	ml_int.push_back(4);
	ml_int.push_back(5);
	ml_int.push_back(6);
	//cout << ml_int.front();
	//list<int>::iterator iterInsertPos = sl_int.begin();

	//sl_int.push_back(1);
	//sl_int.push_back(2);
	//sl_int.push_back(3);

	//sl_int.insert(iterInsertPos, 1);
	
}
