#include <iostream>
#include "Customer.h"
#include "DateTime.h"


using namespace std;

class Ticket {

public:
	string TicketID = "";
	string sourceStationId = "";
	string destinationStationId = "";
	string currentDateTime = "";
	int	ticketAmount = NULL;
	double price = NULL;
	string depatureTime = "";
	Customer customerObj;	

private:

	// initialise datetime
	string datetime[6];

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

		// index			:  0    1   2    3		   4       5
		// Current format	: dow  MM  dd  hh:mm:ss  yyyy\n    NULL?
		// dow -> day of week : Mon, Tue ...
		// MM  -> Month : Jan, Feb ... 
		// Transform it to dd/mm/yyyy|hh:mm
		
		string month = switchMonth(datetime[1]);
		string day = datetime[2].length() == 1 ? ("0" + datetime[2]) : datetime[2];
		string year = datetime[4].substr(0,4); // remove \n at the end
		string time = trimTime(datetime[3]);
		currentDateTime = day + '/' + month + '/' + year + " | " + time;

	}

	// Transfrom : Jan, Feb, Mar.....
	// To        :	01, 02, 03
	string switchMonth(string month) {
		if (month == "Jan") return "01";
		if (month == "Feb") return "02";
		if (month == "Mar") return "03";
		if (month == "Apr") return "04";
		if (month == "May") return "05";
		if (month == "Jun") return "06";

		if (month == "Jul") return "07";
		if (month == "Aug") return "08";
		if (month == "Sep") return "09";
		if (month == "Oct") return "10";
		if (month == "Nov") return "11";
		if (month == "Dec") return "12";
	}

	// Transfrom : hh:mm:ss
	// To        : hh:mm
	string trimTime(string time) {
		return time.substr(0, 5);
	}


public:

	Ticket() {}

	Ticket(int ID, string Source, string Destination, int Amount, double Price, string DepatureTime, Customer customer) {
		TicketID = "TKID_" + to_string(ID);
		sourceStationId = Source;
		destinationStationId = Destination;
		ticketAmount = Amount;
		depatureTime = DepatureTime;
		customerObj = customer;
		price = Price;


		autofill();
	}

	Customer getCustomer() {
		return customerObj;
	}

	string toString() {
		return 
			TicketID				+ ";" +
			sourceStationId			+ ";" +
			destinationStationId	+ ";" +
			currentDateTime			+ ";" +
			to_string(ticketAmount) + ";" +
			to_string(price)		+ ";" +
			depatureTime			+ ";" +
			customerObj.toString();
	}

	void setTicketAmount(int TicketAmount) {
		ticketAmount = TicketAmount;
	}

	void setSourceStationID(string id) {
		sourceStationId = id;
	}

	void setDestinationStationID(string id) {
		destinationStationId = id;
	}

	void setPrice(double newPrice)
	{
		price = newPrice;
	}

	double getPrice() {
		return price;
	}

	int getTicketAmount() {
		return ticketAmount;
	}

	void setDepatureTime(string time) {
		depatureTime = time;
	}

	string getTicketDateTime() {
		return currentDateTime;
	}
};