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
	std::cout << "Hello World!\n";

	sl_int.push_front;
	sl_int.push_back;
	sl_int.pop_front;
	sl_int.pop_back;
	sl_int.erase();
	sl_int.clear;
	sl_int.front;
	sl_int.back;
	sl_int.size;

}
