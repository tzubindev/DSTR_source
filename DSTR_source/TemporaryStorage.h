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
	DoublyLinkedList<string> AdminAccounts;
	DoublyLinkedList<Customer> PassengerAccounts;
	int StationNumber = 8;
	int currentTransactionId = 0;
	int currentCustomerId = 0;
	int currentTicketId = 0;
	int currentStationId = 7;

	//// INITIALISATION SUPPORT ARRAYS
		// Subway ID will be generated in constructor

		// Current Subway Station Name
	string CurrentSubwayStationName[8] = { "Titiwangsa", "PWTC", "Sultan Ismail", "Majlis Jamek", "Plaza Rakyat", "Hang Tuah", "Pudu", "Chan Sow Lin" };

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
	TemporaryStorage() {

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
				SubwayStations.insertVerticallyAt(CurrentSubwayStationName[i - 1], i);

				// Travel Distance Between Previous Station
				SubwayStations.insertVerticallyAt(to_string(TravelDistance[i - 1]), i);

				// Travel Fare Between Previous Station
				SubwayStations.insertVerticallyAt(to_string(Fare[i - 1]), i);

				// Travel Time Between Previous Station
				SubwayStations.insertVerticallyAt(to_string(Time[i - 1]), i);

			}
			else {
				for (int j = 0; j < 4; j++) SubwayStations.insertVerticallyAt("NULL", i);
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
				for (int j = 0; j < 4; j++) SubwayStations.insertVerticallyAt("NULL", i);
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
		Customer newCustomerObj = Customer(getCurrentCustomerId(), "Sample Name", "010203040506", "123456", true);
		Ticket newTicketObj = Ticket(getCurrentTicketId(), "SID_1", "SID_2", ticketAmount, 0.4, "12:00", newCustomerObj);
		Transaction newTransactionObj = Transaction(getCurrentTransactionId(), newTicketObj);
		PurchaseRecord.insertAtEnd(newTransactionObj);
		PassengerAccounts.insertAtEnd(newCustomerObj);

		ticketAmount = 4;
		newCustomerObj = Customer(getCurrentCustomerId(), "Sample Name Two", "123456789012", "123456", true);
		newTicketObj = Ticket(getCurrentTicketId(), "SID_3", "SID_4", ticketAmount, 0.4, "12:00", newCustomerObj);
		newTransactionObj = Transaction(getCurrentTransactionId(), newTicketObj);
		PurchaseRecord.insertAtEnd(newTransactionObj);
		PassengerAccounts.insertAtEnd(newCustomerObj);

		ticketAmount = 2;
		newCustomerObj = Customer(getCurrentCustomerId(), "Sample Name three", "135798642012", "123456", true);
		newTicketObj = Ticket(getCurrentTicketId(), "SID_0", "SID_5", ticketAmount, 0.4, "12:00", newCustomerObj);
		newTransactionObj = Transaction(getCurrentTransactionId(), newTicketObj);
		PurchaseRecord.insertAtEnd(newTransactionObj);
		PassengerAccounts.insertAtEnd(newCustomerObj);


		// Initialise Admin accounts 
		AdminAccounts.insertAtEnd("admin1;123456;");
		AdminAccounts.insertAtEnd("admin2;aab3456;");
	}

	DoublyLinkedList<string> getAdminDetails() {
		return AdminAccounts;

	}

	DoublyLinkedList<Customer> getPassengerAccounts() {
		return PassengerAccounts;
	}

	// Output Data Object: Subway Stations
	DoublyLinkedList<string> getSubwayStations() {
		return SubwayStations;
	}


	// Output Data Object: Ticket Purchasing
	DoublyLinkedList<Transaction> getTicketPurchaseRecord() {
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

	int getCurrentStationId() {
		currentStationId++;
		return currentStationId;
	}

	void failIncreStationId() {
		currentStationId--;
	}

	void sortTransaction() {

	}

	string datetime[6];
	string getCurrentTime() {
		DateTime* dt = new DateTime;
		string dateTime = dt->getDateTime();
		free(dt);
		return trimTime(dateTime);

	}

	string trimTime(string time) {
		return time.substr(11, 5);
	}

	void addPassengerAccount(Customer newCustomer) {
		PassengerAccounts.insertAtEnd(newCustomer);
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

	bool setSourceStationId(string ticketId, string SourceStationId) {
		for (int i = 0; i < PurchaseRecord.getSize(); i++) {
			if (PurchaseRecord.getItem(i).getTicket().TicketID == ticketId)
			{
				Transaction curTransaction = PurchaseRecord.getItem(i);
				if (
					setNewInfo(
						SourceStationId,
						curTransaction.getTicket().destinationStationId,
						curTransaction.getTicket().getTicketAmount(),
						curTransaction)){
					PurchaseRecord.setItem(curTransaction, i);
					return true;
				}
				else return false;
			}
		}
		return false;
	}

	bool setDestinationStationId(string ticketId, string DestinationStationId) {
		for (int i = 0; i < PurchaseRecord.getSize(); i++) {
			if (PurchaseRecord.getItem(i).getTicket().TicketID == ticketId)
			{
				Transaction curTransaction = PurchaseRecord.getItem(i);
				if(setNewInfo(curTransaction.getTicket().sourceStationId, DestinationStationId, curTransaction.getTicket().getTicketAmount(), curTransaction))
					PurchaseRecord.setItem(curTransaction, i);
				else return false;
				return true;
			}
		}
		return false;
	}

	bool setTicketAmount(string ticketId, int TicketAmount) {
		for (int i = 0; i < PurchaseRecord.getSize(); i++) {
			if (PurchaseRecord.getItem(i).getTicket().TicketID == ticketId)
			{
				Transaction curTransaction = PurchaseRecord.getItem(i);
				if(setNewInfo(curTransaction.getTicket().sourceStationId, curTransaction.getTicket().destinationStationId, TicketAmount, curTransaction))
					PurchaseRecord.setItem(curTransaction, i);
				else return false;
				return true;
			}
		}
		return false;
	}

	bool setNewInfo(string stationA, string stationB, int TicketAmount, Transaction& Transaction) {

		// Validate data
		int distance = 0, time = 0;
		double fare = 0;

		// get two stations ID
		bool AisFound = false;
		bool BisFound = false;
		bool splitID = false;

		// Step 1 get ID and collect data
		for (int i = 0; i < SubwayStations.getSize(); i++) {
			string id = SubwayStations.getItem(i);
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
			if (id == stationA) AisFound = true;
			else if (id == stationB) BisFound = true;

			//cout << temp << ' ' << stationA << ' ' << stationB << endl;

			if (AisFound && BisFound) {
				// case out
				break;
			}
			else if (AisFound || BisFound)
				// A is found or B is Found
				// Start collecting data
			{
				distance += stoi(SubwayStations.getItem(i, 7));
				fare += stod(SubwayStations.getItem(i, 8));
				time += stoi(SubwayStations.getItem(i, 9));
			}
		}

		if (!(AisFound && BisFound)) {
			cout << "\nNot Found\n";
			return false;
		}


		fare *= (double)TicketAmount;
		// Build ticket object
		// Ticket(ticketId, stationAid, stationBid, ticketAmount, (double)ticket, depatureTime, customerobj);
		string depatureTime = "";
		for (int i = 0; i < (sizeof(trainDepatureTime) / sizeof(string)) - 1; i++) {
			if (trainDepatureTime[i] <= getCurrentTime() && getCurrentTime() < trainDepatureTime[i + 1])
				depatureTime = trainDepatureTime[i + 1];
		}

		Transaction.resetTransaction(stationA, ResetType().RT_SOURCE_ID);
		Transaction.resetTransaction(stationB, ResetType().RT_DESTINATION_ID);
		Transaction.resetTransaction(to_string(TicketAmount), ResetType().RT_TICKET_AMOUNT);
		Transaction.resetTransaction(to_string(fare), ResetType().RT_PRICE);
		Transaction.resetTransaction(depatureTime, ResetType().RT_DEPATURE_TIME);
		return true;
	}

	void addStation(string StationId, string StationName, bool isFront, string Distance, string Fare, string Time, string NearbySightseeingSpots) {
		int i = currentStationId;
		if (isFront) i = 0;

		if (isFront)SubwayStations.insertAtBeginning(StationId);
		else SubwayStations.insertAtEnd(StationId);

		// Cur Station Name
		SubwayStations.insertVerticallyAt(StationName, i);

		// if back
		// Data related to "prev"
		if (i != 0) {

			// Prev Station Name
			SubwayStations.insertVerticallyAt(getSubwayStations().getItem(getSubwayStations().getSize() - 2, 1), i);
			SubwayStations.setItem(StationName, getSubwayStations().getSize() - 2, 6);

			// Travel Distance Between Previous Station
			SubwayStations.insertVerticallyAt(Distance, i);
			SubwayStations.setItem(Distance, getSubwayStations().getSize() - 2, 7);

			// Travel Fare Between Previous Station
			SubwayStations.insertVerticallyAt(Fare, i);
			SubwayStations.setItem(Fare, getSubwayStations().getSize() - 2, 8);

			// Travel Time Between Previous Station
			SubwayStations.insertVerticallyAt(Time, i);
			SubwayStations.setItem(Time, getSubwayStations().getSize() - 2, 9);

		}
		else {
			for (int j = 0; j < 4; j++) SubwayStations.insertVerticallyAt("NULL", i);
		}


		if (i != currentStationId) {

			// Next Station Name
			SubwayStations.insertVerticallyAt(getSubwayStations().getItem(1, 1), i);
			SubwayStations.setItem(StationName, 1, 2);

			// Travel Distance Between Next Station
			SubwayStations.insertVerticallyAt(Distance, i);
			SubwayStations.setItem(Distance, 1, 3);
			// Travel Fare Between Next Station
			SubwayStations.insertVerticallyAt(Fare, i);
			SubwayStations.setItem(Fare, 1, 4);
			// Travel Time Between Next Station
			SubwayStations.insertVerticallyAt(Time, i);
			SubwayStations.setItem(Time, 1, 5);

		}
		else {
			for (int j = 0; j < 4; j++) SubwayStations.insertVerticallyAt("NULL", i);
		}

		SubwayStations.insertVerticallyAt(NearbySightseeingSpots, i);
	}
};