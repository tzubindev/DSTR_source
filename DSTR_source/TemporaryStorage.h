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

	void addPassengerAccount(Customer newCustomer) {
		PassangerAccounts.insertAtEnd(newCustomer);
	}

	void addTransaction(Transaction newTransaction) {
		PurchaseRecord.insertAtEnd(newTransaction);
	}

	void deleteTransaction(string transactionID) {
		for (int i = 0; i < PurchaseRecord.size; i++) {
			if (transactionID == PurchaseRecord.getItem(i).getTransactionId()) {
				if (i == 0) PurchaseRecord.deleteFirst();
				else if (i == PurchaseRecord.size - 1) PurchaseRecord.deleteLast();
				else PurchaseRecord.deleteItemAt(i);
				break;
			}
		}
	}
};