#include <iostream>
#include <string>
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

class Menu;
class AdminMenu;
class PassengerMenu;

const int MAX_WIDTH = 96;

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

			// Set Colour
			ConsoleColor().setColor(Color.YELLOW);
			cout << intro[0];
			ConsoleColor().setColor(Color.WHITE);

			drawLine('=', MAX_WIDTH);
			cout << '\n';
			giveTab(2);
			cout << intro[1];
			drawLine('-', MAX_WIDTH);

			setMenuType();

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
		makeTitleBlock("MENU", 6);
		cout << "\n";
		drawLine('-', MAX_WIDTH, 0);
		cout << '\n';
		giveTab(5);
		cout << "A - Ticket Purchase\n\n";
		giveTab(5);
		cout << "B - Login (Admin)\n\n";
		drawLine('-', MAX_WIDTH, 0);
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
			cout << "ADMIN > ";
		else
			cout << "ANONYMOUS > ";
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