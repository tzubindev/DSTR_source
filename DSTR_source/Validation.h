#include <iostream>
#include <regex>

using namespace std;


class Validation {

public:
	static const int NAME = 0;
	static const int PASSPORT = 1;
	static const int IC = 2;

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

		}
		else
			return true;


	}


};