#include <iostream>
#include <string>
#include "Test.h"
#include <Windows.h>

using namespace std;


int main() {

	// Set size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 800, 600, TRUE); // 600 width, 600 height

	Test();
	return 0;
}