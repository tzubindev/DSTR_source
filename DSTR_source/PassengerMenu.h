#include <iostream>
#include <string>
#include "Queue.h"
#include "Error.h"
#include <iomanip>

using namespace std;

class PassengerMenu {

private:
	TemporaryStorage* storage;
	string customerID = "";
	bool registered = NULL;

public:

	PassengerMenu() {}

	PassengerMenu(TemporaryStorage *TempStorage, bool isRegistered) {
		registered = isRegistered;
		storage = TempStorage;
		for (int i = 0; i < 10; i++) cout << '\n';
	}



	// Display Travel Route Format
	/*
	************************************************************************
		Station ID: SID			{2}||		Station Name: Name

		Previous
		Station Name: Name
		Distance	: 0				{need 1 tab}
		Price		: RM 0.4		{need 2 tabs}
		Time		: 3 mins		{need 2 tabs}

		Next
		Station Name: Name
		Distance	: 0				{need 1 tab}
		Price		: RM 0.4		{need 2 tabs}
		Time		: 3 mins		{need 2 tabs}

		NearbySightseeingSpots
		1) a
		2) b
	************************************************************************
	*/


	void DisplayTravelRoute(bool AscOrder) {

		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		Menu* tempMenuObj = new Menu(true);
		string temp = "", temp2 = "";

		cout << endl;
		tempMenuObj->drawLine('-', MAX_WIDTH);
		cout << endl;

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Display Travel Route", 6);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		if (AscOrder) {
			for (int i = 0; i < Stations.getSize(); i++) {
				cout << "\tStation ID: " << Stations.getItem(i, 0) << "\t\t" << "||\t" << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << endl << endl;

				cout << "\tNext\n";
				cout << "\tStation Name: " << Stations.getItem(i, 6) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
				string foo = Stations.getItem(i, 8);
				foo = foo.substr(0, 4);
				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
				cout << endl;

				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);
				int cnt = 0;

				// count
				for (char ch : temp) {
					if (ch == ';') {
						cnt++;
					}
				}

				//Queue here
				Queue<string> q(cnt);

				//push item to queue

				for (char ch : temp) {
					if (ch == ';') {
						q.enqueue(temp2);
						temp2 = "";
					}
					else temp2 += ch;
				}

				int size = q.size();
				for (int j = 1; j <= size; j++) {
					cout << "\t" << j << ") " << q.dequeue() << endl;
				}

				cout << endl;
				ConsoleColor().setColor(Color.YELLOW);
				tempMenuObj->drawLine('*', MAX_WIDTH);
				ConsoleColor();
			}
		}
		else {
			for (int i = Stations.getSize() -1 ; i >= 0; i--) {
				cout << "\tStation ID: " << Stations.getItem(i, 0) << "\t\t" << "||\t" << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << endl << endl;

				cout << "\tNext\n";
				cout << "\tStation Name: " << Stations.getItem(i, 2) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 3) << " KM" << endl;
				string foo = Stations.getItem(i, 4);
				foo = foo.substr(0, 4);

				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 5) << " mins" << endl;
				cout << endl;

				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);
				int cnt = 0;

				// count
				for (char ch : temp) {
					if (ch == ';') {
						cnt++;
					}
				}

				//Queue here
				Queue<string> q(cnt);

				//push item to queue

				for (char ch : temp) {
					if (ch == ';') {
						q.enqueue(temp2);
						temp2 = "";
					}
					else temp2 += ch;
				}

				int size = q.size();
				for (int j = 1; j <= size; j++) {
					cout << "\t" << j << ") " << q.dequeue() << endl;
				}

				cout << endl;
				ConsoleColor().setColor(Color.YELLOW);
				tempMenuObj->drawLine('*', MAX_WIDTH);
				ConsoleColor();
			}
		}
		cout << endl;
	}


	void chooseAndDisplayTravelRoute() {
		string input;
		cout << "1- Titiwangsa --> Chan Sow Lin" << "\n" <<
			"OR" << "\n" <<
			"2- Chan Sow Lin --> Titiwangsa" << "\n" <<
			"Please Select the Travel Route:";
		cin >> input;
		if (input == "1") {
			DisplayTravelRoute(true);
		}
		else if (input == "2") {
			DisplayTravelRoute(false);
		}
		else {
			cout << "Please select the correct travel route:";
		}
	}


	
	void searchStationDetails() {
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		Menu* tempMenuObj = new Menu(true);
		string stationID = "";
		string temp = "", temp2 = "";


		cout << endl;
		tempMenuObj->drawLine('-', MAX_WIDTH);
		cout << endl;

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Search Station Details", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();

		cout << endl;
		for (int i = 0; i < Stations.getSize(); i++) {
			cout << "\t" << i + 1 << "- Station ID : " << Stations.getItem(i, 0) << " || " << "Station Name : " << Stations.getItem(i, 1) << endl;
			cout << endl;
		}
		stationID = getInput("Insert the station ID to search for specific station:");

		cout << endl << endl;

		for (int i = 0; i < Stations.getSize(); i++) {

			for (int i = 0; i < stationID.length(); i++) stationID[i] = toupper(stationID[i]);
			if (stationID == Stations.getItem(i, 0)) {

				cout << "\tStation ID: " << Stations.getItem(i, 0) << "\t\t" << "||\t" << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << endl << endl;

				cout << "\tNext\n";
				cout << "\tStation Name: " << Stations.getItem(i, 6) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
				string foo = Stations.getItem(i, 8);
				foo = foo.substr(0, 4);
				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
				cout << endl;

				cout << "\tPrevious\n";
				cout << "\tStation Name: " << Stations.getItem(i, 2) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 3) << " KM" << endl;
				foo = Stations.getItem(i, 4);
				foo = foo.substr(0, 4);

				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 5) << " mins" << endl;
				cout << endl;

				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);
				int cnt = 0;

				// count
				for (char ch : temp) {
					if (ch == ';') {
						cnt++;
					}
				}

				//Queue here
				Queue<string> q(cnt);

				//push item to queue

				for (char ch : temp) {
					if (ch == ';') {
						q.enqueue(temp2);
						temp2 = "";
					}
					else temp2 += ch;
				}

				int size = q.size();
				for (int j = 1; j <= size; j++) {
					cout << "\t" << j << ") " << q.dequeue() << endl;
				}

				cout << endl;
				ConsoleColor().setColor(Color.YELLOW);
				tempMenuObj->drawLine('*', MAX_WIDTH);
				ConsoleColor();

			}
			else {

			}
		}
	}

	void viewDetailsBetweenTwoCities() {
		// display only station name
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		Menu* tempMenuObj = new Menu(true);
		string stationA = "", stationB = "";

		cout << endl;
		tempMenuObj->drawLine('-', MAX_WIDTH);
		cout << endl;

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("View Detail Between Two Cities", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();

		cout << endl;
		tempMenuObj->setTab(4);
		for (int i = 0; i < Stations.getSize(); i++) {
			cout << "(" << i << ") "<<Stations.getItem(i, 1);
			if (i % 3 != 2) {
				cout << "\t";
				if (Stations.getItem(i, 1).length() <= 10)
					cout << "\t";
			}
			else {
				cout << "\n\n";
				tempMenuObj->setTab(4);
			}
		}
		for (int i = 0; i < 4; i++) cout << endl;


		stationA = tempMenuObj->getInput("CITY A(ENTER NUMBER)");
		stationB = tempMenuObj->getInput("CITY B(ENTER NUMBER)");
		for (int i = 0; i < 2; i++) cout << endl;

		// Validate data
		bool isDigit = true;
		for (char ch : stationA) if (!isdigit(ch)) { isDigit = false; break; }
		if (isDigit) {
			for (char ch : stationB) if (!isdigit(ch)) { isDigit = false; break; }
			if (isDigit) {
				if (0 <= stoi(stationA) && stoi(stationA) <= (Stations.getSize() - 1) &&
					0 <= stoi(stationB) && stoi(stationB) <= (Stations.getSize() - 1))
				{
					// get two stations ID
					bool AisFound = false;
					bool BisFound = false;
					bool splitID = false;
					int distance = 0, time = 0;
					double fare = 0;
					string temp = "";

					// Step 1 get ID and collect data
					for (int i = 0; i < Stations.getSize(); i++) {
						string id = Stations.getItem(i);
						temp = "";
						for (char ch : id) {
							if (splitID) temp += ch;
							if (ch == '_') splitID = true;
						}
						splitID = false;
						// Stations
						/*[0] ID
						// [1] Name
						// [2] Name -> Prev
						// [3] Dist
						// [4] Fare
						// [5] Time
						// [6] Name -> Next
						// [7] Dist
						// [8] Fare
						// [9] Time
						// [10] Nearby Spots */


						// Step 1.1 compare chosen and current id
						if (temp == stationA) AisFound = true;
						if (temp == stationB) BisFound = true;

						//cout << temp << ' ' << stationA << ' ' << stationB << endl;

						if (AisFound && BisFound) {
							// case out
							break;
						}
						else if (AisFound || BisFound)
							// A is found or B is Found
							// Start collecting data
						{
							distance += stoi(Stations.getItem(i, 7));
							fare += stod(Stations.getItem(i, 8));
							time += stoi(Stations.getItem(i, 9));
						}
					}

					// Step 2 get station name and display added data
					tempMenuObj->makeTitleBlock(Stations.getItem(stoi(stationA), 1) + " -> " + Stations.getItem(stoi(stationB), 1), 5);
					cout << endl << endl;

					tempMenuObj->setTab(5);
					cout << "Distance: " << distance << " KM" << endl << endl;
					tempMenuObj->setTab(5);
					cout << "Fare\t: " << "RM " << fixed << setprecision(2) << fare << endl << endl;
					tempMenuObj->setTab(5);
					cout << "Time\t: " << time << " Mins" << endl << endl;
					delete tempMenuObj;
				}
				else printError(Error().WRONG_INPUT);
			}
			else printError(Error().WRONG_INPUT);
		}
		else printError(Error().WRONG_INPUT);

		cout << endl;
		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
	}

	void printError(int errorType) {
		string ErrorStr = "";
		Menu* tempMenu = new Menu(true);

		switch (errorType) {
		case Error().WRONG_INPUT:
			ErrorStr = "Wrong input is given!";
			break;
		}

		// Error Displaying
		tempMenu->drawLine('-', MAX_WIDTH);
		cout << '\n';
		ConsoleColor().setColor(Color.RED);
		tempMenu->setTab(6);
		cout << ErrorStr << "\n\n";
		ConsoleColor().setColor(Color.WHITE);
		tempMenu->drawLine('-', MAX_WIDTH);
	}

	void purchaseSubwayTicket() {

		int result = -1;
		if (registered) {
			result = storage->AddTransaction(currentCustomerObj);
		}
		else {
			result = storage->AddTransaction();
		}


		switch(result){
		case Error().WRONG_INPUT:
			cout << "something" << endl;
			return;
		}	
	}

	//Not done yet, please format the output beatifully
	void viewPurchaseTransactionHistory() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();

		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			if (customerID == purchaseRecord.getItem(i).getTicket().getCustomer().getCustomerID()) {
				cout << purchaseRecord.getItem(i).toString() << endl;
			}
			else
			{
				cout << "Nothing to show";
			}
		}
	}

	void deletePurchaseTransaction();

	bool login() {
		Menu* tempMenuObj = new Menu(true);
		tempMenuObj->drawLine('=', MAX_WIDTH);
		tempMenuObj->setTab(5);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Passanger Login\n";
		ConsoleColor().setColor(Color.WHITE);

		tempMenuObj->drawLine('=', MAX_WIDTH);
		cout << '\n';
		tempMenuObj->setTab(3);
		cout << "Please fill in your username and password.\n\n";
		tempMenuObj->drawLine('-', MAX_WIDTH);

		cout << "\n\n";
		string icOrPassportNo = getInput("PASSPORT NO // IC");
		string password = getInput("PASSWORD");

		LinkedList<Customer> Details = storage->getPassangerDetails();
		bool usernameChecked = false, UNcorrect = false, PWcorrect = false, isEnd = false;
		for (int i = 0; i < Details.getSize(); i++) {
			usernameChecked = false;
			UNcorrect = false;
			PWcorrect = false;
			for (auto detail : Details.getItem(i).toString()) {
				if (usernameChecked) {
					if (password == Details.getItem(i).Password) PWcorrect = true;
					customerID = Details.getItem(i).CustomerID;
					isEnd = true;
				}
				else {
					if (icOrPassportNo == Details.getItem(i).PassportNo || icOrPassportNo == Details.getItem(i).IdentityNo) UNcorrect = true;
					usernameChecked = true;
				}
				if (isEnd) break;
			}
			if (PWcorrect && UNcorrect) return true;
		}
		free(tempMenuObj);
		return false;
	}

private:

	string getInput() {

		bool isTrimmedLeft = false;
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		cout << "Passanger > ";
		string input, final = "";
		cin >> input;
		ConsoleColor().setColor(Color.WHITE);

		// lowercase
		for (char ch : input) {
			if (ch != ' ') isTrimmedLeft = true;
			if (isTrimmedLeft)
				final += tolower(ch);
		}
		return final;
	}

	string getInput(string type) {

		bool isTrimmedLeft = false;
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		cout << type + " > ";

		string input, final = "";
		cin >> input;
		ConsoleColor().setColor(Color.WHITE);

		// lowercase
		for (char ch : input) {
			if (ch != ' ') isTrimmedLeft = true;
			if (isTrimmedLeft)
				final += tolower(ch);
		}
		return final;
	}

};
