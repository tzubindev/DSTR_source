#include <iostream>
#include <string>
#include <windows.h>
#include <conio.h>
#include "ConsoleColor.h"
#include "TemporaryStorage.h"
#include "Error.h"

using namespace std;

const int MAX_WIDTH = 121;

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
		setTab(4);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << intro[0];
		ConsoleColor().setColor(Color.WHITE);

		drawLine('=', MAX_WIDTH);
		cout << '\n';
		setTab(3);
		cout << intro[1];
		drawLine('-', MAX_WIDTH);
		//-------------------------------------------------------------------------

		// show menu options
		cout << "\n";
		makeTitleBlock("MENU", 7);
		cout << "\n";
		drawLine('-', MAX_WIDTH, 0);
		cout << '\n';
		setTab(6);
		ConsoleColor().setColor(Color.GREEN);
		cout << "A - Ticket Purchase\n\n";
		setTab(6);
		cout << "B - Login (Admin)\n\n";
		ConsoleColor().setColor(Color.WHITE);
		drawLine('-', MAX_WIDTH, 0);
		cout << "\n";
		//-------------------------------------------------------------------------

		// get the input
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		if (isAdminType)
			cout << "ADMIN > ";
		else
			cout << "ANONYMOUS > ";

		input = getInput("");
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
			setTab(7);
			cout << "Error\n";
			setTab(6);
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

	// both true or false will be fine
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
	string getInput(string str) {
		if (str != "") {
			cout << str << " > ";
		}
		string input;
		cin >> input;

		bool isTrimmedLeft = false;
		string final = "";

		// lowercase
		for (char ch : input) {
			if (ch != ' ') isTrimmedLeft = true;
			if (ch == '\n') continue;
			if (isTrimmedLeft)
				final += tolower(ch);
		}
		return final;
	}

	string getPassword()
	{
		string ipt = "";
		char ipt_ch;
		while (true) {
			ipt_ch = _getch();

			// Check whether user enters
			// a special non-printable
			// character
			if (ipt_ch < 32) {
				cout << endl;
				return ipt;
			}
			ipt.push_back(ipt_ch);
		}
	}

	void makeTitleBlock(string Title, int tabNumber) {
		drawLine('-', Title.length()+2, tabNumber);
		setTab(tabNumber);
		cout << "|" << Title << "|\n";
		drawLine('-', Title.length() + 2, tabNumber);
	}



};