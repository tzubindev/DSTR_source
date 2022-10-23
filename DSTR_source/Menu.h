#include <iostream>
#include <string>
#include <windows.h>

using namespace std;

class Menu;
class AdminMenu;
class PassengerMenu;

const int MAX_WIDTH = 96;
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);


class Menu {


private:
	// Data members
	bool isExited = false;
	bool isAdminType = false;
	string intro[2] = {"Welcome to Subway Ticket Purchase System (STPS)\n", "This is Kuala Lumpur Light Rail Transit (LRT) ticket purchase system.\n\n"};

	// Common functionalities
public:
	
	// Constructor -> used to receive input
	Menu() {

		while (!isExited) {

			string input;

			// Intro
			drawLine('=', MAX_WIDTH);
			giveTab(3);
			SetConsoleTextAttribute(hConsole, k);
			cout << intro[0];

			drawLine('=', MAX_WIDTH);
			cout << '\n';
			giveTab(2);
			cout << intro[1];
			drawLine('-', MAX_WIDTH);

			setMenuType();

			cout << isAdminType;
		}


	}
	

private:

	bool identityCheck();
	//TempStorage getData(); // TempStorage is an object of a class

	void drawLine(char target, int N, int tabNum = 0) {
		giveTab(tabNum);
		for (int i = 1; i <= N; i++) cout << target;
		cout << '\n';
	}

	void giveTab(int tabNum) {
		for (int i = 0; i < tabNum; i++) cout << '\t';
	}

	void setMenuType() {

		// show menu options
		cout << "\n";
		makeTitleBlock("MENU", 4);
		cout << "\n";
		drawLine('-', 20, 0);
		cout << "\nA - Ticket Purchase.\n";
		cout << "B - Login (Admin)\n\n";
		drawLine('-', 20, 0);
		cout << "\n";

		// split the input
		string input = getInput();

		if (input == "A") {
			isAdminType = false;
		}
		else if (input == "B"){
			isAdminType = true;
		}
		else if (input == "exit_manual") {
			isExited = true;
		}
	}

	string getInput() {
		if (isAdminType)
			cout << "| STPS | ADM >";
		else
			cout << "| STPS | ANO >";
		string input;
		cin >> input;
		cout << '\n';
		
		return input;
	}

	void makeTitleBlock(string Title, int tabNumber) {
		drawLine('-', Title.length()+2, tabNumber);
		giveTab(tabNumber);
		cout << "|" << Title << "|\n";
		drawLine('-', Title.length() + 2, tabNumber);
	}


	// Passenger functionalities
public:
	void afunction();
	string bfunction();


	// Admin Functionalitites




};

class PassengerMenu : Menu {

	// Implementation
public:

	PassengerMenu() {

	}

	void DisplayTravelRoute() {
	
	}

	void DisplayAndChooseTravelRoute() {
		DisplayTravelRoute();

		// Choose Route
		// input

	}

	string bfunction() {

	}
};

class AdminMenu : Menu {

	// Implementation
public:

	AdminMenu() {

	}



};