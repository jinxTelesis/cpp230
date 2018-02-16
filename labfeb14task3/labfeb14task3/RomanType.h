#pragma once
#include <string>

class RomanType {
private:
	std::string romanNum;
	int num;

	void supportRomanToIntFunction(int, int &, int &);

public:

	RomanType();
	RomanType(std::string);
	void setRoman(std::string);
	void romanToPostiveinteger();
	void printPositiveinteger();
	void printRoman();
};