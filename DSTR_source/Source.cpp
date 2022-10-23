#include <iostream>
#include <string>
#include "Test.h"
#include <Windows.h>

using namespace std;

bool initialCheck();

int main() {

	// Set size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 800, 600, TRUE); // 600 width, 600 height

	Test();
	return 0;
}

bool initialCheck() {
	// Progressbar: https://www.geeksforgeeks.org/how-to-create-a-command-line-progress-bar-in-c-c/
	return true;
}