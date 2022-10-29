#include <iostream>

using namespace std;

class Customer {


private:
	int CustomerID = NULL;
	string CustomerName = NULL;
	string IdentityCardNo = "";
	string PassportNo = "";
	bool isLocal = IdentityCardNo != ""; // true -> local ; false -> foreigner



public:
	Customer();

	Customer(int ID, string customerName, string Number, bool isLocal = true) {

		CustomerID = ID;
		CustomerName = customerName;
		
		if (isLocal) IdentityCardNo = Number;
		else PassportNo = Number;
	}

};