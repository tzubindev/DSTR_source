#include <iostream>
#include "doublyLinkedList.h"
#include <string>
#include "Transaction.h"
#include "LinkedList.h"
#include "Validation.h"

using namespace std;

class TemporaryStorage {

	// Subway Station Data Structure
private:
	// Data members
	DoublyLinkedList<string> SubwayStations; 
	DoublyLinkedList<Transaction> PurchaseRecord; 
	LinkedList<string> AdminAccounts;
	LinkedList<Customer> PassangerAccounts;
	int StationNumber = 8;
	int currentTransactionId = 0;
	int currentCustomerId = 0;
	int currentTicketId = 0;

	//// INITIALISATION SUPPORT ARRAYS
		// Subway ID will be generated in constructor
		
		// Current Subway Station Name
		string CurrentSubwayStationName[8] = { "Titiwangsa", "PWTC", "Sultan Ismail", "Majlis Jamek", "Plaza Rakyat", "Hang Tuah", "Pudu", "Chan Sow Lin"};

		// PreviousStationName & NextStationName will be generated in constructor
		
		// Travel Distance Between Previous Station & Travel Distance Between Next Station will be generated based on TravelDistance array
		int TravelDistance[7] = { 4 , 8 , 8 , 6 , 10 , 5 , 5 };

		//Travel Fare Between Previous Station & Trave Fare Between Next Station
		double Fare[7] = { 0.4 , 0.8 , 0.8 , 0.6 , 1.0 , 0.5 , 0.5 };

		//Travel Time Between Previous Station & Travel Time Between Next Station
		int Time[7] = { 3 , 7 , 7 , 5 , 9 , 4 , 4 };
		
		//Nearby Sightseeing Spots.
		string NearbySightseeingSpots[8] = {
			"a;b;",
			"c;",
			"d;",
			"e;",
			"f;",
			"g;",
			"h;",
			"i;"
		};
		
		// TimeObject trainArriveTime[40] = { ... }
		string trainDepatureTime[37] = { "06:00", "06:30", "07:00", "07:30",
										"08:00", "08:30", "09:00", "09:30",
										"10:00", "10:30", "11:00", "12:30",
										"13:00", "13:30", "14:00", "14:30",
										"15:00", "15:30", "16:00", "16:30",
										"17:00", "17:30", "18:00", "18:30",
										"19:00", "19:30", "20:00", "20:30",
										"21:00", "21:30", "22:00", "22:30",
										"23:00", "23:30", "00:00", "00:30",  "01:00" 
		};

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


public:
	
	// Constructor for initialisation.
	TemporaryStorage () {

		// Initial subway stations height
		SubwayStations.setHeight(11);

		// Initialise Subway station
		for (int i = 0; i < StationNumber; i++) {

			// Subway ID
			SubwayStations.insertAtEnd("SID_" + to_string(i));
			
			// Cur Station Name
			SubwayStations.insertVerticallyAt(CurrentSubwayStationName[i], i);
			
			// Data related to "prev"
			if (i != 0) {
				
				// Prev Station Name
				SubwayStations.insertVerticallyAt(CurrentSubwayStationName[i-1], i);

				// Travel Distance Between Previous Station
				SubwayStations.insertVerticallyAt(to_string(TravelDistance[i-1]), i);

				// Travel Fare Between Previous Station
				SubwayStations.insertVerticallyAt(to_string(Fare[i-1]), i);

				// Travel Time Between Previous Station
				SubwayStations.insertVerticallyAt(to_string(Time[i-1]), i);

			}
			else {
				for(int j = 0;j<4;j++) SubwayStations.insertVerticallyAt("NULL", i);
			}
			
			// Except 7
			if (i != StationNumber - 1) {

				// Next Station Name
				SubwayStations.insertVerticallyAt(CurrentSubwayStationName[i + 1], i);

				// Travel Distance Between Next Station
				SubwayStations.insertVerticallyAt(to_string(TravelDistance[i]), i);

				// Travel Fare Between Next Station
				SubwayStations.insertVerticallyAt(to_string(Fare[i]), i);

				// Travel Time Between Next Station
				SubwayStations.insertVerticallyAt(to_string(Time[i]), i);

			}
			else { 
				for(int j = 0;j < 4; j++) SubwayStations.insertVerticallyAt("NULL", i);
			}

			SubwayStations.insertVerticallyAt(NearbySightseeingSpots[i], i);

			// Finish Inserting Data into Station linked list
		}

		/* 
			Detail of Stations:
			+---------+
			| SUMMARY |
			+---------+
			1) Subway ID
			2) Cur Station Name
			3) Prev Station Name
			4) Travel Distance Between Previous Station
			5) Travel Fare Between Previous Station
			6) Travel Time Between Previous Station
			7) Next Station Name
			8) Travel Distance Between Next Station
			9) Travel Fare Between Next Station
			10) Travel Time Between Next Station
			11) Nearby Sightseeing Spots


			Detail of Ticket Puchase:
			+---------+
			| SUMMARY |
			+---------+
			1) Transaction ID
			2) Ticket ID
			3) Prev Station Name
			4) Name of the Source Station
			5) Name of the Target Station
			6) Total Ticket Amount
			7) Transaction Date and Time
			8) Departure Time
			9) Customer ID
			10) Customer Name
			11) Customer Identity Card / Passport Details

		*/


		// Initialise Ticket Pruchasing records
		int ticketAmount = 1;
		Customer newCustomerObj = Customer(getCurrentCustomerId(), "passanger1", "010203040506","123456", true);
		Ticket newTicketObj = Ticket(getCurrentTicketId(), "SID_1", "SID_2", ticketAmount, 0.4, "12:00", newCustomerObj);
		Transaction newTransactionObj = Transaction(getCurrentTransactionId(), newTicketObj);
		PurchaseRecord.insertAtEnd(newTransactionObj);

		ticketAmount = 4;


		// Initialise Admin accounts 
		AdminAccounts.insertAtEnd("admin1;123456;");
		AdminAccounts.insertAtEnd("admin2;aab3456;");

		// Initialise Passanger accounts 
		PassangerAccounts.insertAtEnd(newCustomerObj);


	}

	LinkedList<string> getAdminDetails() {
		return AdminAccounts;

	}

	LinkedList<Customer> getPassangerDetails() {
		return PassangerAccounts;

	}

	// Output Data Object: Subway Stations
	DoublyLinkedList<string> getSubwayStations() {
		return SubwayStations;
	}


	// Output Data Object: Ticket Purchasing
	DoublyLinkedList<Transaction> getTicketPurchaseRecord () {
		return PurchaseRecord;
	}

	int getCurrentTransactionId() {
		currentTransactionId++;
		return currentTransactionId;
	}

	int getCurrentCustomerId() {
		currentCustomerId++;
		return currentCustomerId;
	}

	int getCurrentTicketId() {
		currentTicketId++;
		return currentTicketId;
	}

	int AddTransaction() {

		Menu* tempMenuObj = new Menu(true);
		// Create Transaction object here
		string local = tempMenuObj->getInput("LOCAL? (y/n)");
		if (local == "y" || local == "n") {

			// Create customer Object
			string name = tempMenuObj->getInput("NAME (at least 3 characters)");
			string number = "";
			if (local == "y") number = tempMenuObj->getInput("IC");
			else number = tempMenuObj->getInput("PASSPORT NO");
			cout << "PASSWORD (at least 4 characters) > ";
			string password = tempMenuObj->getPassword();
			cout << "CONFIRM PASSWORD > ";
			string cnfPassword = tempMenuObj->getPassword();

			// Validated
			if (Validation().validate(name, Validation().NAME) &&
				(Validation().validate(number, Validation().PASSPORT) || Validation().validate(number, Validation().IC)) &&
				password == cnfPassword && password.length() > 3 && name.length() >= 3) {

				// check duplicated data
				DoublyLinkedList<Transaction> record = getTicketPurchaseRecord();
				for (int i = 0; i < record.getSize() - 1; i++) {
					if (record.getItem(i).getTicket().getCustomer().getPassportNo() == number ||
						record.getItem(i).getTicket().getCustomer().getIdentityNo() == number)
						return Error().DUPLICATED_DATA;
				}
				bool isLocal = (local == "y") ? true : false;
				Customer newCustomer = Customer(getCurrentCustomerId(), name, number, password, isLocal);

				// get two station id
				DoublyLinkedList<string> Stations = SubwayStations;
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
						}
					}
					else { return Error().WRONG_INPUT; }
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
				for (int i = 0; i < (sizeof(trainDepatureTime) / sizeof(string))-1;i++) {
					if (trainDepatureTime[i] <= getCurrentTime() && getCurrentTime() < trainDepatureTime[i + 1])
						depatureTime = trainDepatureTime[i + 1];
				}

				Ticket newTicket = Ticket(getCurrentTicketId(), "SID_"+stationA, "SID_"+stationB, stoi(ticketAmount), fare, depatureTime, newCustomer);
				Transaction newTransaction = Transaction(getCurrentTransactionId(), newTicket);
				PurchaseRecord.insertAtEnd(newTransaction);
				




			}
			else {
				return Error().WRONG_INPUT;
			}
		}
		else {
			return Error().WRONG_INPUT;
		}

		return 1; //  true

	}


	void sortTransaction() {

	}

	string datetime[6];
	string getCurrentTime() {
		DateTime* dt = new DateTime;
		string dateTime = dt->getDateTime();
		free(dt);
		return trimTime(datetime[4]);

	}

	string trimTime(string time) {
		return time.substr(0, 5);
	}
};