#include <iostream>

using namespace std;

class Customer {

public:
	string CustomerID = "";
	string CustomerName = "";
	string IdentityNo = "";
	string PassportNo = "";
	string Password = "";
	
	Customer() {}

	Customer(int customerId, string name, string number, string pass, bool isLocal) {
		CustomerID = "CID_" + to_string(customerId);
		CustomerName = name;
		Password = pass;
		if (isLocal) {
			IdentityNo += number;
			PassportNo = "NULL";
		}
		else {
			IdentityNo = "NULL";
			PassportNo += number;
		}
	}


	string toString() {
		return
			CustomerID + ";" +
			CustomerName + ";" +
			Password + ";" +
			IdentityNo + ";" +
			PassportNo + ";";
	}

	string getCustomerID() {
		return CustomerID;
	}

	string getIdentityNo() {
		return IdentityNo;
	}

	string getPassportNo() {
		return PassportNo;
	}

};