#pragma once
#include <string>

class RomanCon {
private:
	std::string romanNum;
	int num;

	void supportRomanToIntFunction(int, int &, int &);

public:

	RomanCon();
	RomanCon(std::string); // my slighty different version of the blurred code you hinted at 2-3 weeks ago
	void setRoman(std::string);
	void romanToPostiveinteger(); // my version of the code you blurred out does not call print internally, have to call seperatly 
	void printPositiveinteger(); 
	void printRoman(); 
};


