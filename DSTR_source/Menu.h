#include <iostream>
#include <string>
#include <windows.h>
#include "ConsoleColor.h"

using namespace std;

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

			if(setMenuType()) {
				break;
			}
		}
	}

	char getUserType() {
		if(isAdminType)
			return 'A';
		else 
			return 'P';
	}
	
	bool getExitStatus() {
		if(isExited)
			printExitMessage();
		return isExited;
	}
	

private:

	void printExitMessage() {

	}

	void drawLine(char target, int N, int tabNum = 0) {
		setTab(tabNum);
		for (int i = 1; i <= N; i++) cout << target;
		cout << '\n';
	}

	void setTab(int tabNum) {
		for (int i = 0; i < tabNum; i++) cout << '\t';
	}

	bool setMenuType() {

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

		// split the input
		string input = getInput();

		if (input == "a" || input == "b") {
			if (input == "a") isAdminType = false;
			else isAdminType = true;

			return true;
		}
		else if (input == "exit_manual") {
			isExited = true;
			return false;
		}
		else {
			drawLine('-', MAX_WIDTH);
			cout << '\n';
			ConsoleColor().setColor(Color.RED);
			setTab(6);
			cout << "Error\n";
			setTab(5);
			cout << "Invalid Input! Your input: " + input + "\n\n";
			ConsoleColor().setColor(Color.WHITE);
			drawLine('-', MAX_WIDTH);
			return false;

		}
	}

	// all returned value will be lowercase
	string getInput() {
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		if (isAdminType)
			cout << "ADMIN > ";
		else
			cout << "ANONYMOUS > ";
		string input, final = "";
		cin >> input;
		cout << '\n';
		ConsoleColor().setColor(Color.WHITE);

		// lowercase
		for (char ch : input)
			final += tolower(ch);

		return final;
	}

	void makeTitleBlock(string Title, int tabNumber) {
		drawLine('-', Title.length()+2, tabNumber);
		setTab(tabNumber);
		cout << "|" << Title << "|\n";
		drawLine('-', Title.length() + 2, tabNumber);
	}


public:

	// Passanger Functionalitites
	void DisplayTravelRoute();
	void chooseAndDisplayTravelRoute();
	void searchStationDetails();
	void viewDetailsBetweenTwoCities();
	bool purchaseSubwayTicket();
	void viewPurchaseTransactionHistory();
	bool deletePurchaseTransaction();


	// Admin Functionalitites
	bool addSubwayStation();
	bool editSubwayInformation();
	void viewPurchaseTransactions();
	void sortPurchaseTransactions();
	void searchTicketInformation();
	bool editTicketInformation();
	bool deleteTicket();



};

class PassengerMenu : Menu {

	// Implementation
public:

	PassengerMenu() {

	}

	void DisplayTravelRoute() {
	
	}

	void chooseAndDisplayTravelRoute() {
		DisplayTravelRoute();

		// Choose Route
		// input
	}

	void searchStationDetails() {

	}

	void viewDetailsBetweenTwoCities() {

	}

	bool purchaseSubwayTicket() {

	}

	void viewPurchaseTransactionHistory() {

	}

	bool deletePurchaseTransaction() {

	}

};

class AdminMenu : Menu {

	// Implementation
public:

	AdminMenu() {

		// identity check
			cout << "A";
	}

	bool addSubwayStation() {
		return true;
	}

	bool editSubwayInformation() {
		return true;
	}

	void viewPurchaseTransactions() {

	}

	void sortPurchaseTransactions() {

	}

	void searchTicketInformation() {

	}

	bool editTicketInformation() {
		return true;
	}

	bool deleteTicket() {
		return true;
	}

};