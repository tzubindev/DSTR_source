#include <iostream>
#include <string>
#include "Test.h"
#include <Windows.h>

using namespace std;

bool initialCheck();
void setSize();

int main() {

	setSize();

	// Implement testing
	Test();

	return 0;
}

bool initialCheck() {
	// Progressbar: https://www.geeksforgeeks.org/how-to-create-a-command-line-progress-bar-in-c-c/
	return true;
}

void setSize() {
	// Set size
	HWND console = GetConsoleWindow();
	RECT r;
	GetWindowRect(console, &r); //stores the console's current dimensions
	MoveWindow(console, r.left, r.top, 1000, 600, TRUE); // 1000 width, 600 height
}