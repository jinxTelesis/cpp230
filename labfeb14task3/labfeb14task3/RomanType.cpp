#include <string>
#include <iostream>
#include "RomanType.h"

void RomanType::supportRomanToIntFunction(int factor, int & sum, int & previous) {
	sum += factor;
	if (previous < factor)
		sum -= 2 * previous;
	previous = factor;
}

void RomanType::romanToPostiveinteger() {
	int previous = 1000, sum = 0, i, length = romanNum.length();

	for (i = 0; i < length; i++) {
		switch (romanNum[i]) {
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
				supportRomanToIntFunction(5, sum, previous);
				break;
			case 'I':
				supportRomanToIntFunction(1, sum, previous);
				break;

		}
	}
	num = sum;
}

RomanType::RomanType()
{
	romanNum = "";
}

RomanType::RomanType(std::string romanNum)
{
	this->romanNum = romanNum;
}

void RomanType::setRoman(std::string romanNum)
{
	this->romanNum = romanNum;
}

void RomanType::printRoman()
{
	std::cout << romanNum << std::endl;
}

void RomanType::printPositiveinteger()
{
	std::cout << num << std::endl;
}