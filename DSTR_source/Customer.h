#include <iostream>

using namespace std;

class Customer {

public:
	string CustomerID = "";
	string CustomerName = "";
	string IdentityNo = "";
	string PassportNo = "";
	string Password = "";
	string PhoneNumber = "";
	
	Customer() {}

	Customer(int customerId, string name, string phoneNumber, string number, string pass, bool isLocal) {
		CustomerID = "CID_" + to_string(customerId);
		CustomerName = name;
		Password = pass;
		PhoneNumber = phoneNumber;
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
			PhoneNumber + ";" +
			Password + ";" +
			IdentityNo + ";" +
			PassportNo + ";";
	}


};