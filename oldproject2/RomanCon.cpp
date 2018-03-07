#include <string>
#include <iostream>
#include "RomanCon.h"

void RomanCon::supportRomanToIntFunction(int factor, int & sum, int & previous) {
	sum += factor;
	if (previous < factor)
		sum -= 2 * previous;
	previous = factor;
}

void RomanCon::romanToPostiveinteger() {
	int previous = 5000, sum = 0, i, length = romanNum.length(); // might break it

	for (i = 0; i < length; i++) {
		switch (romanNum[i]) {
		case 'T':
			supportRomanToIntFunction(5000, sum, previous);
			break;
		case 'M':
			supportRomanToIntFunction(1000, sum, previous);
			break;
		case 'D':
			supportRomanToIntFunction(500, sum, previous);
			break;
		case 'C':
			supportRomanToIntFunction(100, sum, previous);
			break;
		case 'L':
			supportRomanToIntFunction(50, sum, previous);
			break;
		case 'X':
			supportRomanToIntFunction(10, sum, previous);
			break;
		case 'V':
			supportRomanToIntFunction(5, sum, previous); //I V X L C D M T
			break;
		case 'I':
			supportRomanToIntFunction(1, sum, previous);
			break;

		}
	}
	num = sum;
}

RomanCon::RomanCon()
{
	romanNum = 'I';
	num = 1;
}

RomanCon::RomanCon(std::string romanNum)
{
	this->romanNum = romanNum;
}

void RomanCon::setRoman(std::string romanNum)
{
	this->romanNum = romanNum;
}

void RomanCon::printRoman()
{
	std::cout << "the roman numeral " << romanNum << std::endl;
}

void RomanCon::printPositiveinteger()
{
	std::cout << "equals " << num << " as an integer " << std::endl;
}
