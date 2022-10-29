#include <iostream>

using namespace std;

class Customer {


private:
	int CustomerID = NULL;
	string CustomerName = NULL;
	string IdentityCardNo = "";
	string PassportNo = "";
	bool isLocal; // true -> local ; false -> foreigner



public:
	Customer();

	Customer(int ID, string customerName, string Number, bool local) {

		CustomerID = ID;
		CustomerName = customerName;
		isLocal = local;
		
		if (isLocal) IdentityCardNo = Number;
		else PassportNo = Number;
	}

};