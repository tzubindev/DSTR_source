#include <iostream>


using namespace std;

class GlobalAttribute {

private:
	int currentTransactionId = 0;
	int currentCustomerId = 0;

public:
	
	GlobalAttribute();

	int getCurrentTransactionId() {
		currentTransactionId++;
		return currentTransactionId;
	}

	int getCurrentCustomerId() {
		currentCustomerId++;
		return currentCustomerId;
	}
	

};