#include <Windows.h>

using namespace std;

struct Color {
	const int GREEN = 10;
	const int LIGHT_BLUE = 11;
	const int RED = 12;
	const int PINK = 13;
	const int YELLOW = 14;
	const int WHITE = 15;
} Color;


class ConsoleColor {


private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:

	ConsoleColor() {
		SetConsoleTextAttribute(hConsole, Color.WHITE);
	}

	void setColor(int color) {
		SetConsoleTextAttribute(hConsole, color);
	}
};