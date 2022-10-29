#include <iostream>
#include "doublyLinkedList.h"
#include <string>
#include "Transaction.h"

using namespace std;

class TemporaryStorage {

	// Ticket Purchase Record Data Structure
private:
    // Data members

private:
	// create 
	DoublyLinkedList<Transaction> TransactionList;

public:
	
	void AddTransaction() {

		// Create Transaction object here


	}

	void sortTransaction() {

	}


	// Subway Station Data Structure
private:
	// Data members
	DoublyLinkedList<DoublyLinkedList<string>> SubwayStations;
	DoublyLinkedList<string> Station;
	int StationNumber = 8;

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
			"",
			"",
			"",
			"",
			"",
			"",
			"",
			""
		};
		
		// TimeObject trainArriveTime[40] = { ... }


public:
	
	// Constructor for initialisation.
	TemporaryStorage () {
		
		// Initialise Subway station
		for (int i = 0; i < StationNumber; i++) {

			// Subway ID
			Station.insertAtEnd("SID_" + to_string(i));

			// Cur Station Name
			Station.insertAtEnd(CurrentSubwayStationName[i]);

			
			// Data related to "prev"
			if (i != 0) {
				
				// Prev Station Name
				Station.insertAtEnd(CurrentSubwayStationName[i - 1]);

				// Travel Distance Between Previous Station
				Station.insertAtEnd(to_string(TravelDistance[i - 1]));

				// Travel Fare Between Previous Station
				Station.insertAtEnd(to_string(Fare[i - 1]));

				// Travel Time Between Previous Station
				Station.insertAtEnd(to_string(Time[i - 1]));

			}
			else	Station.insertAtEnd("NULL");

			
			if (i != StationNumber - 1) {

				// Next Station Name
				Station.insertAtEnd(CurrentSubwayStationName[i + 1]);

				// Travel Distance Between Next Station
				Station.insertAtEnd(to_string(TravelDistance[i + 1]));

				// Travel Fare Between Next Station
				Station.insertAtEnd(to_string(Fare[i + 1]));

				// Travel Time Between Next Station
				Station.insertAtEnd(to_string(Time[i + 1]));

			}
			else	Station.insertAtEnd("NULL");

			Station.insertAtEnd(NearbySightseeingSpots[i]);

			// Finish Inserting Data into Station linked list
			// Insert the Station liked list into SubwayStations linked list

			SubwayStations.insertAtEnd(Station);
			
			// Clear the Station linked list
			Station.clear();
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


			Detail of Ticket Puchase:

		*/

	}


	// Output Data Object: Subway Stations
	DoublyLinkedList<DoublyLinkedList<string>> getSubwayStations () {
		return SubwayStations;
	}


	// Output Data Object: Ticket Purchasing
	DoublyLinkedList<DoublyLinkedList<string>> getTicketPurchaseRecord () {
	}

private: 
	int currentTransactionId = 0;
	int currentCustomerId = 0;

public:

	int getCurrentTransactionId() {
		currentTransactionId++;
		return currentTransactionId;
	}

	int getCurrentCustomerId() {
		currentCustomerId++;
		return currentCustomerId;
	}

};