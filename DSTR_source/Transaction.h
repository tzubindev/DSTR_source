#include <iostream>
#include "Ticket.h"
#include "ResetType.h"

using namespace std;

class Transaction {

private:
	string TransactionID = "";
	Ticket TicketObject;

public:
	Transaction() {}

	Transaction(int transactionId, Ticket ticket) {
		TransactionID = "T_" + to_string(transactionId);
		TicketObject = ticket;
	}

	string getTransactionId() {
		return TransactionID;
	}

	Ticket getTicket() {
		return TicketObject;
	}

	string toString() {
		return 
			TransactionID + ";"
			+ TicketObject.toString();
	}

	void resetTransaction(string replaceStr, int resetType) {

		Ticket newTicket = this->getTicket();
		switch (resetType) {
		case ResetType.RT_SOURCE_ID:
			newTicket.setSourceStationID(replaceStr);
			break;
		case ResetType.RT_DESTINATION_ID:
			newTicket.setDestinationStationID(replaceStr);
			break;
		case ResetType.RT_TICKET_AMOUNT:
			newTicket.setTicketAmount(stoi(replaceStr));
			break;
		case ResetType.RT_PRICE:
			newTicket.setPrice(stod(replaceStr));
			break;
		case ResetType.RT_DEPATURE_TIME:
			newTicket.setDepatureTime(replaceStr);
			break;
		}

		TicketObject = newTicket;


	}

};