#include <iostream>
#include "Customer.h"
#include "DateTime.h"


using namespace std;

class Ticket {

public:
	string TicketID = "TKID_";
	string sourceStationId = "";
	string destinationStationId = "";
	string currentDateTime = "";
	int ticketAmount = NULL;
	double price = NULL;
	string depatureTime = "";
	Customer customerObj;	

private:

	// initialise datetime
	string datetime[5];

	void autofill() {
		
		// Set current date time
		DateTime* dt = new DateTime;
		string dateTime = dt->getDateTime();
		free(dt);

		string finalresult;
		int curPos = 0;

		finalresult = "";
		for (char ch : dateTime) {
			if (ch == ' ') {
				datetime[curPos] = finalresult;
				finalresult = "";
				curPos++;
			}
			else finalresult += ch;
		}
		datetime[curPos] = finalresult;

	
	}


public:

	Ticket() {}

	Ticket(int ID, string Source, string Destination, int Amount, double Price, string DepatureTime, Customer customer) {
		TicketID += ID;
		sourceStationId = Source;
		destinationStationId = Destination;
		ticketAmount = Amount;
		depatureTime = DepatureTime;
		customerObj = customer;
		price = Price;


		autofill();
	}




};