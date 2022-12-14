#include <iostream>
#include <string>
#include <iomanip>

using namespace std;

class PassengerMenu {

private:
	TemporaryStorage* storage;
	string customerID = "";
	bool registered = NULL;
	Customer currentCustomerObj = Customer();


public:

	PassengerMenu(TemporaryStorage* TempStorage) {
		storage = TempStorage;
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
			for (int i = Stations.getSize() - 1; i >= 0; i--) {
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
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		string input;
		cout << "\n1- "<< Stations.getItem(0, 1) << " --> "<< Stations.getItem(Stations.getSize()-1, 1) << "\n\n" <<
			"OR" << "\n\n" <<
			"2- " << Stations.getItem(Stations.getSize() - 1, 1)  <<" --> " << Stations.getItem(0,1) << "\n" << endl;
		input = getInput("Please Select the Travel Route:");
		for (char ch : input) {
			if (!isdigit(ch)) {
				printError(Error().WRONG_INPUT);
				return;
			}
		}
		switch (stoi(input)) {
		case 1:
			DisplayTravelRoute(true);
			break;
		case 2:
			DisplayTravelRoute(false);
			break;
		default:
			printError(Error().WRONG_INPUT);
			return;
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

		bool isAvalible = false;

		for (int i = 0; i < Stations.getSize(); i++) {

			for (int i = 0; i < stationID.length(); i++) stationID[i] = toupper(stationID[i]);
			if (stationID == Stations.getItem(i, 0)) {
				isAvalible = true;

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
				return;
			}

		}
		if (!isAvalible) {
			isAvalible = true;
			tempMenuObj->drawLine('-', MAX_WIDTH);
			tempMenuObj->setTab(6);
			cout << "Please enter a valid Station ID: ";
			cout << endl;
			tempMenuObj->drawLine('-', MAX_WIDTH);
			ConsoleColor().setColor(Color.YELLOW);
			ConsoleColor();
			searchStationDetails();
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
			cout << "(" << i << ") " << Stations.getItem(i, 1);
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
		case Error().DUPLICATED_DATA:
			ErrorStr = "IC or Passport NO has been used to register!";
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
		Menu* tempMenuObj = new Menu(true);

		// get two station id
		DoublyLinkedList<string> Stations = storage->getSubwayStations();
		string stationA = "", stationB = "";
		cout << endl;
		tempMenuObj->setTab(4);
		for (int i = 0; i < Stations.getSize(); i++) {
			cout << "(" << i << ") " << Stations.getItem(i, 1);
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

		if (stationA == stationB) {
			printError(Error().WRONG_INPUT);
			return;
		}

		// Validate data
		int distance = 0, time = 0;
		double fare = 0;
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
						else if (temp == stationB) BisFound = true;

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
				}
			}
			else { result = Error().WRONG_INPUT; }
		}

		// Build ticket object
		// Ticket(ticketId, stationAid, stationBid, ticketAmount, (double)ticket, depatureTime, customerobj);
		isDigit = true;
		string ticketAmount = tempMenuObj->getInput("TICKET AMOUNT");
		for (char ch : ticketAmount) {
			if (!isdigit(ch)) {
				isDigit = false;
				break;
			}
		}

		string depatureTime = "";
		for (int i = 0; i < (sizeof(storage->trainDepatureTime) / sizeof(string)) - 1; i++) {
			if (storage->trainDepatureTime[i] <= storage->getCurrentTime() && storage->getCurrentTime() < storage->trainDepatureTime[i + 1])
				depatureTime = storage->trainDepatureTime[i + 1];
		}

		fare *= stod(ticketAmount);
		Ticket newTicket = Ticket(storage->getCurrentTicketId(), "SID_" + stationA, "SID_" + stationB, stoi(ticketAmount), fare, depatureTime, currentCustomerObj);
		Transaction newTransaction = Transaction(storage->getCurrentTransactionId(), newTicket);
		storage->addTransaction(newTransaction);

		result = 1;



		switch (result) {
		case Error().WRONG_INPUT:
			printError(Error().WRONG_INPUT);
			return;
		default:
			tempMenuObj->makeTitleBlock("Ticket has been Successfuly Purchaced", 4);
		}
	}

	void registerPassenger() {
		Menu* tempMenuObj = new Menu(true);
		DoublyLinkedList<Customer> Customers = storage->getPassengerAccounts();

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("Register", 7);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();

		tempMenuObj->setTab(3);
		string local = tempMenuObj->getInput("LOCAL? (y/n)");
		cout << endl;
		if (local == "y" || local == "n") {
			// Create customer Object
			string name = tempMenuObj->getInput("NAME (at least 3 characters, with no space)");
			string number = "";
			if (local == "y")
				number = tempMenuObj->getInput("IC (only digit)");
			else
				number = tempMenuObj->getInput("PASSPORT NO");
			cout << "PASSWORD (at least 4 characters) > ";
			string password = tempMenuObj->getPassword();
			cout << "CONFIRM PASSWORD > ";
			string cnfPassword = tempMenuObj->getPassword();

			if (Validation().validate(name, Validation().NAME) &&
				password == cnfPassword && password.length() > 3) {

				if (local == "y") {
					if (!Validation().validate(number, Validation().IC)) {
						printError(Error().WRONG_INPUT);
						return;
					}
				}
				else {
					if (!Validation().validate(number, Validation().PASSPORT)) {
						printError(Error().WRONG_INPUT);
						return;
					}
				}
				// check duplication
				for (int i = 0; i < Customers.getSize(); i++) {
					if (Customers.getItem(i).getIdentityNo() == number || Customers.getItem(i).getPassportNo() == number) {
						printError(Error().DUPLICATED_DATA);
						return;
					}
				}
				bool isLocal = (local == "y");
				Customer newCustomer = Customer(storage->getCurrentCustomerId(), name, number, password, isLocal);
				storage->addPassengerAccount(newCustomer);
				cout << "Account is registered!" << endl;
				return;
			}
			else printError(Error().WRONG_INPUT);

		}
		else {
			printError(Error().WRONG_INPUT);
		}
		return;
	}

	void viewPurchaseTransactionHistory() {
		DoublyLinkedList<Transaction> purchaseRecord = storage->getTicketPurchaseRecord();
		Menu* tempMenuObj = new Menu(true);

		cout << endl;
		tempMenuObj->drawLine('-', MAX_WIDTH);
		cout << endl;

		ConsoleColor().setColor(Color.YELLOW);
		tempMenuObj->drawLine('*', MAX_WIDTH);
		tempMenuObj->makeTitleBlock("View Purchase Transaction History", 5);
		cout << endl;
		tempMenuObj->drawLine('*', MAX_WIDTH);
		ConsoleColor();

		cout << endl;

		bool isAvalible = true;

		for (int i = 0; i < purchaseRecord.getSize(); i++) {
			if (customerID == purchaseRecord.getItem(i).getTicket().getCustomer().getCustomerID()) {
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

	void deletePurchaseTransaction() {
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
			if (customerID == Transactions.getItem(i).getTicket().customerObj.getCustomerID()) {
				tempMenuObj->setTab(2);
				cout << "Transaction ID : " << Transactions.getItem(i).getTransactionId() << endl;
				tempMenuObj->setTab(2);
				cout << "Customer ID : " << Transactions.getItem(i).getTicket().getCustomer().getCustomerID() << endl;
				tempMenuObj->setTab(2);
				cout << "Ticket Date and Time :" << Transactions.getItem(i).getTicket().getTicketDateTime() << endl;
			}
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
			for (int i = 0; i < Transactions.getSize(); i++) {
				if (customerID == Transactions.getItem(i).getTicket().customerObj.getCustomerID()) {
					storage->deleteTransaction(toDeleteID);
					break;
				}
			}
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
		tempMenuObj->setTab(5);

		// Set Colour
		ConsoleColor().setColor(Color.YELLOW);
		cout << "Passenger Login\n";
		ConsoleColor().setColor(Color.WHITE);

		tempMenuObj->drawLine('=', MAX_WIDTH);
		cout << '\n';
		tempMenuObj->setTab(3);
		cout << "Please fill in your username and password.\n\n";
		tempMenuObj->drawLine('-', MAX_WIDTH);

		cout << "\n\n";
		string icOrPassportNo = getInput("PASSPORT NO // IC");
		cout << "PASSWORD > ";
		string password = tempMenuObj->getPassword();

		DoublyLinkedList<Customer> Details = storage->getPassengerAccounts();
		bool UNcorrect = false, PWcorrect = false;
		for (int i = 0; i < Details.getSize(); i++) {
			UNcorrect = false;
			PWcorrect = false;
			for (int i = 0; i < Details.getSize(); i++) {

				if (icOrPassportNo == Details.getItem(i).PassportNo ||
					icOrPassportNo == Details.getItem(i).IdentityNo)
					UNcorrect = true;

				if (UNcorrect) {
					if (password == Details.getItem(i).Password) {
						PWcorrect = true;
						customerID = Details.getItem(i).CustomerID;
					}
					break;
				}
			}
			if (PWcorrect && UNcorrect) {

				// use customerID to find customer object 
				// do for loop to check every object in the passanger accounts
				// if ic or passport no == to item.passportno || ic or passport no == to item.identity
				// currentcustomerobj = item 
				for (int i = 0; i < Details.getSize(); i++) {
					if (customerID == Details.getItem(i).CustomerID) {
						if (icOrPassportNo == Details.getItem(i).PassportNo || icOrPassportNo == Details.getItem(i).IdentityNo)
							currentCustomerObj = Details.getItem(i);
					}
				}
				cout << "Login successful!!" << endl;
				return true;
			}
		}
		free(tempMenuObj);
		return false;
	}

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

	TemporaryStorage* outputLatestStorage() {
		return storage;
	}
};
