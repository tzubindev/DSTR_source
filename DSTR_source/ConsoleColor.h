#include <Windows.h>

using namespace std;

struct Color {
	const int GREEN = 10;
	const int LIGHT_BLUE = 11;
	const int RED = 12;
	const int PINK = 13;
	const int YELLOW = 14;
	const int WHITE = 14;
};


class ConsoleColor {


private:
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

public:
	static const int GREEN = 10;
	static const int LIGHT_BLUE = 11;
	static const int RED = 12;
	static const int PINK = 13;
	static const int YELLOW = 14;
	static const int WHITE = 14;

	ConsoleColor() {
		SetConsoleTextAttribute(hConsole, WHITE);
	}

	static void setColor(int color) {
		privateSetColor(color);
	}

private:
	static int color = ConsoleColor.WHITE;
};