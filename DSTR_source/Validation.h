#include <iostream>
#include <regex>

using namespace std;


class Validation {

public:
	static const int NAME = 0;
	static const int PASSPORT = 1;
	static const int IC = 2;
	int errorType = -1;

	Validation() {}

	bool validate(string str, int type) {
		
		string regexPattern = "";
		switch (type) {
		case NAME:
			regexPattern = "[a-zA-z. ]";
			break;
		case PASSPORT:
			regexPattern = "^ (? !^ 0 + $)[a - zA - Z0 - 9] {3, 20}$";
			break;
		case IC:
			regexPattern = "[0-9]{12}";
			break;
		}


		regex regexRule(regexPattern);
		if (!regex_match(str, regexRule)) {
			switch (type) {
			case NAME:
				errorType = NAME;
				return false;
			case PASSPORT:
				errorType = PASSPORT;
				return false;
			case IC:
				errorType = IC;
				return false;
			}
		}
		else
			return true;


	}


};