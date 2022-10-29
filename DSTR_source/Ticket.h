#include <iostream>
#include "Customer.h"
#include <ctime>

using namespace std;

class Ticket {

private:
	string TicketID = "TKID_";
	string sourceStation = "";
	string destinationStation = "";
	string currentDateTime = "";
	int ticketAmount = NULL;
	double price = NULL;
	string depatureTime = "";
	Customer customerObj;


	time_t rawtime;
	struct tm* timeinfo;
	char buffer[80];




	// Define datetime and depatureTime
	void autofill() {
		
		// Set current date time
		time(&rawtime);
		timeinfo = localtime(&rawtime);

		strftime(buffer, sizeof(buffer), "%d-%m-%Y %H:%M:%S", timeinfo);
		std::string str(buffer);
		currentDateTime = str;


		// accumulate travel time between two stations 


		// train arrive time + accumulated travel time
	
	}


public:

	Ticket() {}

	Ticket(int ID, string Source, string Destination, int Amount, string DepatureTime, Customer customer) {
		TicketID += ID;
		sourceStation = Source;
		destinationStation = Destination;
		ticketAmount = Amount;
		depatureTime = DepatureTime;
		customerObj = customer;

		autofill();
	}




};