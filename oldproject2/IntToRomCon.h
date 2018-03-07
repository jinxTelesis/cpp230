#pragma once
#include <string>

class IntToRomCon
{
private:
	int tempint = 0;
	int remainingNumber = 0;
	int placeNumber = 0;

	std::string romanString; // stringthat actually holds the value
	std::string romThousandArr[11] = { "","M","MM","MMM","MT","T","TM","TMM","TMMM","unsupported Number","unsupporte Number" }; //I V X L C D M T
	std::string romHundredArr[11] = { "", "C", "CC","CCC","CD","D","DC","DCC","DCCC", "CM","M" };
	std::string romTenArr[11] = { "", "X", "XX","XXX","XL","L","LX","LXX","LXXX", "XC","C" };
	std::string romSingleArr[11] = { "", "I","II","III","IV","V","VI","VII","VIII","IX", "X" };
public:
	IntToRomCon();
	std::string intToRoman(int value); // brute if statement solution // worst thing ive ever coded
	std::string intToRomanVer2(int value); // string array soltuion still about 30 lines longer than it needs to be
	void printRoman();
};
