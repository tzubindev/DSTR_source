#include <iostream>
#include <string>
#include <windows.h>
#include "ConsoleColor.h"
#include "TemporaryStorage.h"

using namespace std;

const int MAX_WIDTH = 96;

class Menu {


private:
	// Data members
	bool isExited = false;
	bool isAdminType = false;
	bool isSelected = false;
	bool isError = false;
	string intro[2] = {"Welcome to Subway Ticket Purchase System (STPS)\n", "This is Kuala Lumpur Light Rail Transit (LRT) ticket purchase system.\n\n"};

	// Common functionalities
public:
	
	// Constructor -> used to receive input
	Menu() {

		string input;

		// Intro
		drawLine('=', MAX_WIDTH);
		setTab(3);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << intro[0];
		ConsoleColor().setColor(Color.WHITE);

		drawLine('=', MAX_WIDTH);
		cout << '\n';
		setTab(2);
		cout << intro[1];
		drawLine('-', MAX_WIDTH);
		//-------------------------------------------------------------------------

		// show menu options
		cout << "\n";
		makeTitleBlock("MENU", 6);
		cout << "\n";
		drawLine('-', MAX_WIDTH, 0);
		cout << '\n';
		setTab(5);
		ConsoleColor().setColor(Color.GREEN);
		cout << "A - Ticket Purchase\n\n";
		setTab(5);
		cout << "B - Login (Admin)\n\n";
		ConsoleColor().setColor(Color.WHITE);
		drawLine('-', MAX_WIDTH, 0);
		cout << "\n";
		//-------------------------------------------------------------------------

		// split the input
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		if (isAdminType)
			cout << "ADMIN > ";
		else
			cout << "ANONYMOUS > ";
		cin >> input;

		input = getInput(input);
		ConsoleColor().setColor(Color.WHITE);

		int returnInput = 0;
		if (input == "a") { returnInput = 1; }
		else if (input == "b") { returnInput = 2; }
		else if (input == "exit") { returnInput = 3; }
		else {
			// Error Displaying
			drawLine('-', MAX_WIDTH);
			cout << '\n';
			ConsoleColor().setColor(Color.RED);
			setTab(6);
			cout << "Error\n";
			setTab(5);
			cout << "Invalid Input! Your input: " + input + "\n\n";
			ConsoleColor().setColor(Color.WHITE);
			drawLine('-', MAX_WIDTH);
			returnInput = -1;
		}

		switch(returnInput) {
		case 1:
			isSelected = true;
			isAdminType = false;
			break;
		case 2:
			isSelected = true;
			isAdminType = true;
			break;
		case 3:
			isExited = true;
			break;
		default:
			isError = true;
			break;
		}
	}

	Menu(bool para) {}

	bool getErrorStatus() {
		return isError;
	}

	char getUserType() {
		if(isAdminType)
			return 'A';
		else 
			return 'P';
	}	

	bool getExitStatus() { return isExited; }

	void drawLine(char target, int N, int tabNum = 0) {
		setTab(tabNum);
		for (int i = 1; i <= N; i++) cout << target;
		cout << '\n';
	}

	void setTab(int tabNum) {
		for (int i = 0; i < tabNum; i++) cout << '\t';
	}

	// all returned value will be lowercase
	string getInput(string input) {
		bool isTrimmedLeft = false;
		string final = "";

		// lowercase
		for (char ch : input) {
			if (ch != ' ') isTrimmedLeft = true;
			if(isTrimmedLeft)
				final += tolower(ch);
		}
		return final;
	}

	void makeTitleBlock(string Title, int tabNumber) {
		drawLine('-', Title.length()+2, tabNumber);
		setTab(tabNumber);
		cout << "|" << Title << "|\n";
		drawLine('-', Title.length() + 2, tabNumber);
	}

};