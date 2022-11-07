#include <string>
#include <iostream>
#include <windows.h>
#include "Menu.h"

using namespace std;



class AdminMenu {

private:
	TemporaryStorage* storage;

	// Implementation
public:
	AdminMenu(TemporaryStorage* TempStorage) {
		storage = TempStorage;

		for (int i = 0; i < 10; i++) cout << '\n';
	}

	void addSubwayStation() {
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		Menu* tempMenuObj = new Menu(true);

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Add Subway Station", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		cout << endl;

		for (int i = 0; i < Stations.getSize(); i++) {
			tempMenuObj->setTab(5);
			cout << Stations.getItem(i, 0) << " || " << Stations.getItem(i, 1) << endl;
		}
		cout << endl;

		tempMenuObj->setTab(5);
		cout << "1 - Add from the front.\n";
		tempMenuObj->setTab(5);
		cout << "2 - Add from the end.\n";

		string option = getInput("ADD FROM");
		if (option == "1" || option == "2") {
			string StationId = "SID_" + to_string(storage->getCurrentStationId());

			cout << "Station Name (use '_' to replace space):";
			string StationName;
			cin >> StationName;
			bool isFront = option == "1";
			string Distance;
			cout << "Distance(integer, km): ";
			cin >> Distance;
			string Fare;
			cout << "Fare(double, RM): ";
			cin >> Fare;
			string Time;
			cout << "Time(int, min): ";
			cin >> Time;
			string NearbySpots;
			cout << "NearbySpots(use ';' for the end of every spot and use '_' to replace space, if no then enter ';')[e.g. a;b_c;]: ";
			cin >> NearbySpots;

			// Validation needed
			if (Validation().validate(StationName, Validation().SNAME) &&
				Validation().validate(Distance, Validation().SDIST) &&
				Validation().validate(Fare, Validation().SFARE) &&
				Validation().validate(Time, Validation().STIME) &&
				Validation().validate(NearbySpots, Validation().SSPOT)) {
				for (int i = 0; i < StationName.length(); i++) if (StationName[i] == '_') StationName[i] = ' ';
				for (int i = 0; i < NearbySpots.length(); i++) if (NearbySpots[i] == '_') NearbySpots[i] = ' ';

				storage->addStation(StationId, StationName, isFront, Distance, Fare, Time, NearbySpots);
				tempMenuObj->makeTitleBlock("Station Name Successfuly Updated", 6);
			}
			else printError(Error().WRONG_INPUT);
		}
		else {
			printError(Error().WRONG_INPUT);
		}


		cout << endl;
		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		delete tempMenuObj;
	}

	void editSubwayInformation() {	
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		Menu* tempMenuObj = new Menu(true);
		string stationID;
		string temp, temp2;
		for (int i = 0; i < Stations.getSize(); i++) {
			cout << endl;
			cout << "Station ID: " << Stations.getItem(i, 0) << endl;
			cout << "Station Name: " << Stations.getItem(i, 1) << endl;


			tempMenuObj->drawLine('-', MAX_WIDTH);
			cout << endl;

		}


		stationID = getInput("Please enter the station ID to edit it: ");
		cout << endl;
		for (int i = 0; i < stationID.length(); i++) stationID[i] = toupper(stationID[i]);
		for (int i = 0; i < Stations.getSize(); i++) {
			if (stationID == Stations.getItem(i, 0)) {
				cout << "Station ID: " << Stations.getItem(i, 0) << endl;
				cout << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
				string foo = Stations.getItem(i, 8);
				foo = foo.substr(0, 4);
				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
				cout << endl << endl;

				cout << "\tNearby Sightseeing Spots\n";
				temp = Stations.getItem(i, 10);
				tempMenuObj->drawLine('-', MAX_WIDTH);
				cout << endl;
				string option;
				cout << "1- Station Name(type '_' to replace space) \n2- Price\n3- Time\n4- Cancel" << endl;
				option = getInput("Enter the number thing that you want to edit:");
				cout << endl;
				string input;
				for (char ch : option) {
					if (!isdigit(ch)) {
						printError(Error().WRONG_INPUT);
						return;
					}
				}
				switch (stoi(option))
				{
				case 1:
					input = getInput("Enter the new name of the staion : ", false);
					for (char ch : input) {
						if (isdigit(ch) && ch!='_') {
							printError(Error().WRONG_INPUT);
							return;
						}
					}
					for (int i = 0; i < input.length(); i++) if (input[i] == '_') input[i] = ' ';
					Stations.setItem(input, i, 1);
					cout << endl;
					tempMenuObj->drawLine('-', MAX_WIDTH);
					tempMenuObj->makeTitleBlock("Station Name Successfuly Updated", 6);
					cout << endl << endl;
					break;
				case 2:
					input = getInput("Enter the new price:");
					for (char ch : input) {
						if (!isdigit(ch)) {
							printError(Error().WRONG_INPUT);
							return;
						}
					}
					Stations.setItem(input, i, 8);
					tempMenuObj->drawLine('-', MAX_WIDTH);
					tempMenuObj->makeTitleBlock("Price Successfuly Updated", 6);
					cout << endl << endl;
					break;
				case 3:
					input = getInput("Enter the new time:");
					for (char ch : input) {
						if (!isdigit(ch)) {
							printError(Error().WRONG_INPUT);
							return;
						}
					}
					Stations.setItem(input, i, 9);
					tempMenuObj->drawLine('-', MAX_WIDTH);
					tempMenuObj->makeTitleBlock("Time Successfuly Updated", 6);
					cout << endl << endl;
					break;
				case 4:
					tempMenuObj->setTab(6);
					cout << "Editing Cancelled\n";
					return;
				default:
					printError(Error().WRONG_INPUT);
					return;
				}
				cout << "Station ID: " << Stations.getItem(i, 0) << endl;
				cout << "Station Name: " << Stations.getItem(i, 1) << endl;
				cout << "\tDistance\t: " << Stations.getItem(i, 7) << " KM" << endl;
				foo = Stations.getItem(i, 8);
				foo = foo.substr(0, 4);
				cout << "\tPrice\t\t: " << "RM " << foo << endl;
				cout << "\tTime\t\t: " << Stations.getItem(i, 9) << " mins" << endl;
				cout << endl << endl;
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
	}

	void viewPurchaseTransactions() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("View Purchase Transactions", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		cout << endl;
		bool isAvalible = true;
		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			tempMenuObj->makeTitleBlock(purchaseRecord.getItem(i).getTransactionId(), 1);
			cout << endl << endl;
			tempMenuObj->setTab(1);
			cout << "TicketId: " << purchaseRecord.getItem(i).getTicket().TicketID << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Source Station Id: " << purchaseRecord.getItem(i).getTicket().sourceStationId << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Destination Station Id: " << purchaseRecord.getItem(i).getTicket().destinationStationId << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Ticket Amount: " << purchaseRecord.getItem(i).getTicket().ticketAmount << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Ticket Price: " << "RM" << purchaseRecord.getItem(i).getTicket().price << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Departure Time: " << purchaseRecord.getItem(i).getTicket().depatureTime << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Customer ID: " << purchaseRecord.getItem(i).getTicket().customerObj.CustomerID << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Customer Name: " << purchaseRecord.getItem(i).getTicket().customerObj.CustomerName << endl << endl;
			tempMenuObj->setTab(1);
			if (purchaseRecord.getItem(i).getTicket().customerObj.PassportNo == "NULL") {
				cout << "IC: " << purchaseRecord.getItem(i).getTicket().customerObj.IdentityNo << endl << endl;
			}
			else {
				cout << "Passport Number: " << purchaseRecord.getItem(i).getTicket().customerObj.PassportNo << endl << endl;
			}
			tempMenuObj->drawLine('-', MAX_WIDTH);
			cout << endl;
			isAvalible = false;
			cout << endl;
		}

		if (isAvalible) {
			tempMenuObj->drawLine('-', MAX_WIDTH);
			tempMenuObj->setTab(6);
			cout << "No Purchase Transaction Found";
			cout << endl;
			tempMenuObj->drawLine('-', MAX_WIDTH);
			ConsoleColor().setColor(Color.YELLOW);
			ConsoleColor();
		}

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		delete tempMenuObj;
	}


	// no complete
	void sortPurchaseTransactions() {
		DoublyLinkedList<Transaction> Transactions = storage->sortTransaction();


		//DoublyLinkedList<Transaction> Transactions = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);


		for (int i = 0; i < storage->sortTransaction().getSize(); i++) {
			tempMenuObj->makeTitleBlock(Transactions.getItem(i).getTransactionId(), 1);
			cout << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Customer Name: " << Transactions.getItem(i).getTicket().customerObj.CustomerName << endl << endl;
			tempMenuObj->setTab(1);
			cout << "TicketId: " << Transactions.getItem(i).getTicket().TicketID << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Source Station Id: " << Transactions.getItem(i).getTicket().sourceStationId << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Destination Station Id: " << Transactions.getItem(i).getTicket().destinationStationId << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Ticket Amount: " << Transactions.getItem(i).getTicket().ticketAmount << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Ticket Price: " << "RM" << Transactions.getItem(i).getTicket().price << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Departure Time: " << Transactions.getItem(i).getTicket().depatureTime << endl << endl;
			tempMenuObj->setTab(1);
			cout << "Customer ID: " << Transactions.getItem(i).getTicket().customerObj.CustomerID << endl << endl;
			tempMenuObj->setTab(1);
			if (Transactions.getItem(i).getTicket().customerObj.PassportNo == "NULL") {
				cout << "IC: " << Transactions.getItem(i).getTicket().customerObj.IdentityNo << endl << endl;
			}
			else {
				cout << "Passport Number: " << Transactions.getItem(i).getTicket().customerObj.PassportNo << endl << endl;
			}
			tempMenuObj->drawLine('-', MAX_WIDTH);
			cout << endl;
		}
		delete tempMenuObj;
	}


	void searchTicketInformation() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);
		string searchTicketID = "";

		cout << endl;
		tempMenuObj->drawLine('-', MAX_WIDTH);
		cout << endl;

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Search for a Specific Tickect Information", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();

		cout << endl;

		searchTicketID = getInput("Insert the Ticket id to search for ticket:");

		cout << endl << endl;
		for (int i = 0; i < searchTicketID.length(); i++) searchTicketID[i] = toupper(searchTicketID[i]);

		bool isAvalible = false;

		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			if (searchTicketID == purchaseRecord.getItem(i).getTicket().TicketID) {
				isAvalible = true;
				tempMenuObj->setTab(1);
				cout << "TicketId: " << purchaseRecord.getItem(i).getTicket().TicketID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Source Station Id: " << purchaseRecord.getItem(i).getTicket().sourceStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Destination Station Id: " << purchaseRecord.getItem(i).getTicket().destinationStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Amount: " << purchaseRecord.getItem(i).getTicket().ticketAmount << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Price: " << "RM" << purchaseRecord.getItem(i).getTicket().price << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Departure Time: " << purchaseRecord.getItem(i).getTicket().depatureTime << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer ID: " << purchaseRecord.getItem(i).getTicket().customerObj.CustomerID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer Name: " << purchaseRecord.getItem(i).getTicket().customerObj.CustomerName << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Passport Number // IC: " << purchaseRecord.getItem(i).getTicket().customerObj.IdentityNo << purchaseRecord.getItem(i).getTicket().customerObj.PassportNo << endl << endl;
				delete tempMenuObj;
				return;
			}
		}
		if (!isAvalible) {
			isAvalible = true;
			tempMenuObj->drawLine('-', MAX_WIDTH);
			tempMenuObj->setTab(6);
			cout << "Please enter a valid Ticket ID: ";
			cout << endl;
			tempMenuObj->drawLine('-', MAX_WIDTH);
			ConsoleColor().setColor(Color.YELLOW);
			ConsoleColor();
			searchTicketInformation();
		}
		cout << endl;
		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
	}

	void editTicketInformation() {
		DoublyLinkedList<Transaction> Ticket = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);
		string TicketID;
		string temp, temp2;
		for (int i = 0; i < Ticket.getSize(); i++) {
			cout << endl;
			cout << "Customer ID: " << Ticket.getItem(i).getTicket().customerObj.getCustomerID() << endl;
			cout << "Tickect ID " << Ticket.getItem(i).getTicket().TicketID << endl;


			tempMenuObj->drawLine('-', MAX_WIDTH);
			cout << endl;

		}


		TicketID = getInput("Please enter the Ticket ID to edit it:");
		cout << endl;
		for (int i = 0; i < TicketID.length(); i++) TicketID[i] = toupper(TicketID[i]);
		for (int i = 0; i < Ticket.getSize(); i++) {
			if (TicketID == Ticket.getItem(i).getTicket().TicketID) {
				cout << endl << endl;
				tempMenuObj->setTab(1);
				cout << "TicketId: " << Ticket.getItem(i).getTicket().TicketID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Source Station Id: " << Ticket.getItem(i).getTicket().sourceStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Destination Station Id: " << Ticket.getItem(i).getTicket().destinationStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Amount: " << Ticket.getItem(i).getTicket().ticketAmount << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Price: " << "RM" << Ticket.getItem(i).getTicket().price << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Departure Time: " << Ticket.getItem(i).getTicket().depatureTime << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer ID: " << Ticket.getItem(i).getTicket().customerObj.CustomerID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer Name: " << Ticket.getItem(i).getTicket().customerObj.CustomerName << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Passport Number // IC: " << Ticket.getItem(i).getTicket().customerObj.IdentityNo << Ticket.getItem(i).getTicket().customerObj.PassportNo << endl << endl;
				tempMenuObj->drawLine('-', MAX_WIDTH);
				cout << endl;

				string option;
				cout << "1- Source Staion \n2- Destination Station\n3- Ticket Amount" << endl;
				option = getInput("Enter the number thing that you want to edit:");
				cout << endl;
				string input;
				for (char ch : option) {
					if (!isdigit(ch)) {
						printError(Error().WRONG_INPUT);
						return;
					}
				}
				string data;
				switch (stoi(option))
				{
				case 1:
					input = getInput("Enter the new source station ID: ", false);
					for (int i = 0; i < input.length(); i++) input[i] = toupper(input[i]);
					if (storage->setSourceStationId(Ticket.getItem(i).getTicket().TicketID, input)) {
						cout << endl;
						tempMenuObj->drawLine('-', MAX_WIDTH);
						tempMenuObj->makeTitleBlock("Source Station Successfuly Updated", 6);
						cout << endl << endl;
					}
					else printError(Error().NOT_FOUND);
					break;
				case 2:
					input = getInput("Enter the new destination station ID: ", false);
					for (int i = 0; i < input.length(); i++) input[i] = toupper(input[i]);
					if (storage->setDestinationStationId(Ticket.getItem(i).getTicket().TicketID, input)) {
						tempMenuObj->drawLine('-', MAX_WIDTH);
						tempMenuObj->makeTitleBlock("Destination Station Successfuly Updated", 6);
						cout << endl << endl;
					}
					else printError(Error().NOT_FOUND);
					break;
				case 3:
					input = getInput("Enter the new ticket amount: ");
					for (char ch : input) {
						if (!isdigit(ch)) {
							printError(Error().WRONG_INPUT);
							return;
						}
					}
					if (storage->setTicketAmount(Ticket.getItem(i).getTicket().TicketID, stoi(input))) {
						tempMenuObj->drawLine('-', MAX_WIDTH);
						tempMenuObj->makeTitleBlock("Ticket Amount Successfuly Updated", 6);
						cout << endl << endl;
					}else printError(Error().NOT_FOUND);
					break;
				default:
					printError(Error().WRONG_INPUT);
					return;
				}
				cout << endl << endl;
				tempMenuObj->setTab(1);
				cout << "TicketId: " << Ticket.getItem(i).getTicket().TicketID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Source Station Id: " << Ticket.getItem(i).getTicket().sourceStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Destination Station Id: " << Ticket.getItem(i).getTicket().destinationStationId << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Amount: " << Ticket.getItem(i).getTicket().ticketAmount << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Ticket Price: " << "RM" << Ticket.getItem(i).getTicket().price << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Departure Time: " << Ticket.getItem(i).getTicket().depatureTime << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer ID: " << Ticket.getItem(i).getTicket().customerObj.CustomerID << endl << endl;
				tempMenuObj->setTab(1);
				cout << "Customer Name: " << Ticket.getItem(i).getTicket().customerObj.CustomerName << endl << endl;
				tempMenuObj->setTab(1);
				if (Ticket.getItem(i).getTicket().customerObj.PassportNo == "NULL") {
					cout << "IC: " << Ticket.getItem(i).getTicket().customerObj.IdentityNo << endl << endl;
				}
				else {
					cout << "Passport Number: " << Ticket.getItem(i).getTicket().customerObj.PassportNo << endl << endl;
				}
				tempMenuObj->drawLine('-', MAX_WIDTH);
				cout << endl;

				ConsoleColor().setColor(Color.YELLOW);
				tempMenuObj->drawLine('*', MAX_WIDTH);
				ConsoleColor();
			}
		}
	}

	void deleteTransaction() {
		DoublyLinkedList<Transaction> Transactions = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Delete Transaction", 6);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();
		cout << endl;

		if (Transactions.getSize() == 0) {
			tempMenuObj->setTab(4);
			cout << "No Data!";
			cout << endl;
			ConsoleColor().setColor(Color.YELLOW);
			tempMenuObj->drawLine('*', MAX_WIDTH);
			ConsoleColor();
			return;
		}
		for (int i = 0; i < Transactions.getSize(); i++) {
			tempMenuObj->setTab(2);
			cout << "Transaction ID : " << Transactions.getItem(i).getTransactionId() << endl;
			tempMenuObj->setTab(2);
			cout << "Customer ID : " << Transactions.getItem(i).getTicket().getCustomer().getCustomerID() << endl;
			tempMenuObj->setTab(2);
			cout << "Ticket Date and Time :" << Transactions.getItem(i).getTicket().getTicketDateTime() << endl;
		}

		cout << endl;
		string toDeleteID = tempMenuObj->getInput("TRANSACTION ID");
		for (int i = 0; i < toDeleteID.length(); i++) toDeleteID[i] = toupper(toDeleteID[i]);
		bool isFound = false;

		// check record
		for (int i = 0; i < Transactions.getSize(); i++) {
			if (toDeleteID == Transactions.getItem(i).getTransactionId()) {
				isFound = true;
				break;
			}
		}

		if (!isFound) printError(Error().WRONG_INPUT);
		else {
			storage->deleteTransaction(toDeleteID);
		}

		if (isFound) {
			tempMenuObj->setTab(2);
			cout << toDeleteID << " is deleted successfully. " << endl;
			cout << endl;
			ConsoleColor().setColor(Color.YELLOW);
			tempMenuObj->drawLine('*', MAX_WIDTH);
			ConsoleColor();
		}
		delete tempMenuObj;
	}

	bool login() {
		Menu* tempMenuObj = new Menu(true);
		tempMenuObj->drawLine('=', MAX_WIDTH);
		tempMenuObj->setTab(6);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Admin Login\n";
		ConsoleColor().setColor(Color.WHITE);

		tempMenuObj->drawLine('=', MAX_WIDTH);
		cout << '\n';
		tempMenuObj->setTab(4);
		cout << "Please fill in your username and password.\n\n";
		tempMenuObj->drawLine('-', MAX_WIDTH);

		cout << "\n\n";
		string username = getInput("USERNAME");
		cout << "PASSWORD > ";
		string password = tempMenuObj->getPassword();

		// Verification here 
		DoublyLinkedList<string> Details = storage->getAdminDetails();
		string temp = "";
		bool usernameChecked = false, UNcorrect = false, PWcorrect = false, isEnd = false;
		for (int i = 0; i < Details.getSize(); i++) {
			usernameChecked = false;
			UNcorrect = false;
			PWcorrect = false;
			temp = "";
			for (char ch : Details.getItem(i)) {
				if (ch != ';') {
					temp += ch;
				}
				else {
					if (!usernameChecked) {
						usernameChecked = true;
						if (username == temp) UNcorrect = true;
						temp = "";
					}
					else {
						if (password == temp) {
							PWcorrect = true;
							break;
						}
					}
				}
			}
			if (PWcorrect && UNcorrect) {
				return true;
			}

		}
		free(tempMenuObj);
		return false;
	}



	void printError(int errorType) {
		string ErrorStr = "";
		Menu* tempMenu = new Menu(true);

		switch (errorType) {
		case Error().WRONG_INPUT:
			ErrorStr = "Wrong input is given!";
			break;
		case Error().DUPLICATED_DATA:
			ErrorStr = "Duplicated data";
			break;
		case Error().NOT_FOUND:
			ErrorStr = "Not found";
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

	string getInput() {

		bool isTrimmedLeft = false;
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		cout << "ADMIN > ";
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

	string getInput(string type, bool lower = true) {

		bool isTrimmedLeft = false;
		ConsoleColor().setColor(Color.LIGHT_BLUE);
		cout << type + " > ";

		string input, final = "";
		cin >> input;
		ConsoleColor().setColor(Color.WHITE);
		if (lower) {
			// lowercase
			for (char ch : input) {
				if (ch != ' ') isTrimmedLeft = true;
				if (isTrimmedLeft)
					final += tolower(ch);
			}
		}
		else {
			for (char ch : input) {
				if (ch != ' ') isTrimmedLeft = true;
				if (isTrimmedLeft && ch!='\n')
					final += (ch);
			}
		}
		return final;
	}

	TemporaryStorage* outputLatestStorage() {
		return storage;
	}

};