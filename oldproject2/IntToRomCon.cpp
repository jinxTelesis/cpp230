#include "IntToRomCon.h"
#include <string>
#include <iostream>

using namespace std;


IntToRomCon::IntToRomCon()
{
	tempint =0;
	remainingNumber = 0;
	placeNumber = 0;
	romanString ="";
	
	 // make sure c is 100
	//romTenArr[11] = { "", "X", "XX","XXX","XL","L","LX","LXX","LXXX", "XC","C" };
	//romSingleArr[11] = { "", "I","II","III","IV","V","VI","VII","VIII","IX", "X" };
	//std::string romThousandArr[11] = { "","M","MM","MMM","MT","T","TM","TMM","TMMM","unsupported Number","unsupporte Number" }; //I V X L C D M T
	//std::string romHundredArr[11] = { "", "C", "CC","CCC","CD","D","DC","DCC","DCCC", "CM","M" }; // make sure c is 100
	//std::string romTenArr[11] = { "", "X", "XX","XXX","XL","L","LX","LXX","LXXX", "XC","C" };
	//std::string romSingleArr[11] = { "", "I","II","III","IV","V","VI","VII","VIII","IX", "X" };


}


std::string IntToRomCon::intToRoman(int value) // lab was done with direct array conversion realized the division of array lists
{ // after writting this out // aka place arrays in values of 10s and divide
	
	romanString = ""; // resets between calls
	//****************************************************************************************************************
	/// array solution on line 485 
	/// array solution on line 485
	//*****************************************************************************************************************
	if (value > 1000) 
	{ /**/
		std::cout << "make sure this does not print 1000s" << std::endl;
		remainingNumber = (value % 1000);
		placeNumber = (value / 1000);

		if (placeNumber == 8) // thousandsarr[placeNumber] = { "","M","MM","MMM","MT","M"}
							// hundreds[placeNUmber] = {"C", "CC", "CCC", "CD", };
		{
			romanString == "TMMM";
		}
		if (placeNumber == 7)
		{
			romanString = "TMM";
		}
		if (placeNumber == 6)
		{
			romanString = "TM";
		}
		if (placeNumber == 5)
		{
			romanString = "T";
		}
		if (placeNumber == 4)
		{
			romanString = "MT";
		}
		if (placeNumber == 3)
		{
			romanString = "MMM";
		}
		if (placeNumber == 2)
		{
			romanString = "MM";
		}
		if (placeNumber == 1)
		{
			romanString = "M"; //string romanString = "M" // romanStrnig.append("CM" "MCM"
		}



		placeNumber = (remainingNumber / 100);
		remainingNumber = (remainingNumber % 100);

		
		//I V X L C D M T
		if (placeNumber == 9)
		{
			romanString.append("CM"); // test this one //MTCM
		}
		if (placeNumber == 8)
		{
			romanString.append("DCCC");
		}
		if (placeNumber == 7)
		{
			romanString.append("DCC");
		}
		if (placeNumber == 6)
		{
			romanString.append("DC");
		}
		if (placeNumber == 5)
		{
			romanString.append("D");
		}
		if (placeNumber == 4)
		{
			romanString.append("CD");
		}
		if (placeNumber == 3)
		{
			romanString.append("CCC");
		}
		if (placeNumber == 2)
		{
			romanString.append("CC");
		}
		if (placeNumber == 1)
		{
			romanString.append("C");
		}

		placeNumber = (remainingNumber / 10);
		remainingNumber = (remainingNumber % 10);

		//I V X L C D M T
		if (placeNumber == 9)
		{
			romanString.append("XC"); // //MTCMXC
		}
		if (placeNumber == 8)
		{
			romanString.append("LXXX");
		}
		if (placeNumber == 7)
		{
			romanString.append("LXX");
		}
		if (placeNumber == 6)
		{
			romanString.append("LX");
		}
		if (placeNumber == 5)
		{
			romanString.append("L");
		}
		if (placeNumber == 4)
		{
			romanString.append("XL");
		}
		if (placeNumber == 3)
		{
			romanString.append("XXX");
		}
		if (placeNumber == 2)
		{
			romanString.append("XX");
		}
		if (placeNumber == 1)
		{
			romanString.append("X");
		}

		placeNumber = (remainingNumber / 1); // i just thought this would be really funny to insert
		remainingNumber = (remainingNumber % 1); // just a joke lol
		if (placeNumber == 9) // could be remanining number
		{
			romanString.append("IX");
		}
		if (placeNumber == 8)
		{
			romanString.append("VIII");
		}
		if (placeNumber == 7)
		{
			romanString.append("VII");
		}
		if (placeNumber == 6)
		{
			romanString.append("VI");
		}
		if (placeNumber == 5)
		{
			romanString.append("V");
		}
		if (placeNumber == 4)
		{
			romanString.append("IV");
		}
		if (placeNumber == 3)
		{
			romanString.append("III");
		}
		if (placeNumber == 2)
		{
			romanString.append("II");
		}
		if (placeNumber == 1)
		{
			romanString.append("I");
		}


		std::cout << "second romanString" << romanString << std::endl;


	}
	if (value == 1000)
	{
		romanString.append("M");
	}

	if (value == 1)
	{
		romanString.append("I");
	}

	if (value < 1000 && value > 100)
	{
		std::cout << "see if this prints 100s" << std::endl;
		placeNumber = (value / 100);
		remainingNumber = (value % 100);


		//I V X L C D M T
		if (placeNumber == 9)
		{
			romanString.append("CM"); // test this one //MTCM
		}
		if (placeNumber == 8)
		{
			romanString.append("DCCC");
		}
		if (placeNumber == 7)
		{
			romanString.append("DCC");
		}
		if (placeNumber == 6)
		{
			romanString.append("DC");
		}
		if (placeNumber == 5)
		{
			romanString.append("D");
		}
		if (placeNumber == 4)
		{
			romanString.append("CD");
		}
		if (placeNumber == 3)
		{
			romanString.append("CCC");
		}
		if (placeNumber == 2)
		{
			romanString.append("CC");
		}
		if (placeNumber == 1)
		{
			romanString.append("C");
		}

		placeNumber = (remainingNumber / 10);
		remainingNumber = (remainingNumber % 10);

		//I V X L C D M T
		if (placeNumber == 9)
		{
			romanString.append("XC"); // //MTCMXC
		}
		if (placeNumber == 8)
		{
			romanString.append("LXXX");
		}
		if (placeNumber == 7)
		{
			romanString.append("LXX");
		}
		if (placeNumber == 6)
		{
			romanString.append("LX");
		}
		if (placeNumber == 5)
		{
			romanString.append("L");
		}
		if (placeNumber == 4)
		{
			romanString.append("XL");
		}
		if (placeNumber == 3)
		{
			romanString.append("XXX");
		}
		if (placeNumber == 2)
		{
			romanString.append("XX");
		}
		if (placeNumber == 1)
		{
			romanString.append("X");
		}

		placeNumber = (remainingNumber / 1); // i just thought this would be really funny to insert
		remainingNumber = (remainingNumber % 1); // just a joke lol
		if (placeNumber == 9) // could be remanining number
		{
			romanString.append("IX");
		}
		if (placeNumber == 8)
		{
			romanString.append("VIII");
		}
		if (placeNumber == 7)
		{
			romanString.append("VII");
		}
		if (placeNumber == 6)
		{
			romanString.append("VI");
		}
		if (placeNumber == 5)
		{
			romanString.append("V");
		}
		if (placeNumber == 4)
		{
			romanString.append("IV");
		}
		if (placeNumber == 3)
		{
			romanString.append("III");
		}
		if (placeNumber == 2)
		{
			romanString.append("II");
		}
		if (placeNumber == 1)
		{
			romanString.append("I");
		}


		std::cout << "second romanString" << romanString << std::endl;
	}
	if (value == 100)
	{
		romanString.append("C");
	}


	if (value < 100 && value > 10)
	{
		std::cout << "see if this prints 100s" << std::endl;
		placeNumber = (value / 10);
		remainingNumber = (value % 10);
		if (placeNumber == 9)
		{
			romanString.append("XC"); // //MTCMXC
		}
		if (placeNumber == 8)
		{
			romanString.append("LXXX");
		}
		if (placeNumber == 7)
		{
			romanString.append("LXX");
		}
		if (placeNumber == 6)
		{
			romanString.append("LX");
		}
		if (placeNumber == 5)
		{
			romanString.append("L");
		}
		if (placeNumber == 4)
		{
			romanString.append("XL");
		}
		if (placeNumber == 3)
		{
			romanString.append("XXX");
		}
		if (placeNumber == 2)
		{
			romanString.append("XX");
		}
		if (placeNumber == 1)
		{
			romanString.append("X");
		}

		placeNumber = (remainingNumber / 1); // i just thought this would be really funny to insert
		remainingNumber = (remainingNumber % 1); // just a joke lol
		if (placeNumber == 9) // could be remanining number
		{
			romanString.append("IX");
		}
		if (placeNumber == 8)
		{
			romanString.append("VIII");
		}
		if (placeNumber == 7)
		{
			romanString.append("VII");
		}
		if (placeNumber == 6)
		{
			romanString.append("VI");
		}
		if (placeNumber == 5)
		{
			romanString.append("V");
		}
		if (placeNumber == 4)
		{
			romanString.append("IV");
		}
		if (placeNumber == 3)
		{
			romanString.append("III");
		}
		if (placeNumber == 2)
		{
			romanString.append("II");
		}
		if (placeNumber == 1)
		{
			romanString.append("I");
		}

	}
	if (value == 10)
	{
		romanString.append("X");
	}

	if (value < 10 && value > 1)
	{
		placeNumber = (value / 1); // i just thought this would be really funny to insert
		remainingNumber = (value % 1); // just a joke lol
		if (placeNumber == 9) // could be remanining number
		{
			romanString.append("IX");
		}
		if (placeNumber == 8)
		{
			romanString.append("VIII");
		}
		if (placeNumber == 7)
		{
			romanString.append("VII");
		}
		if (placeNumber == 6)
		{
			romanString.append("VI");
		}
		if (placeNumber == 5)
		{
			romanString.append("V");
		}
		if (placeNumber == 4)
		{
			romanString.append("IV");
		}
		if (placeNumber == 3)
		{
			romanString.append("III");
		}
		if (placeNumber == 2)
		{
			romanString.append("II");
		}
		if (placeNumber == 1)
		{
			romanString.append("I");
		}
	}

	return romanString;
}

void IntToRomCon::printRoman()
{
	std::cout << "this is the roman value " << romanString << std::endl;
}


std::string IntToRomCon::intToRomanVer2(int value)
{
	romanString = "";// resets string
	// write same compare value places than just index that array spot
	std::string blank = "dummy output";
	if (value > 1000)
	{
		//std::cout << "make sure this does not print 1000s" << std::endl;
		remainingNumber = (value % 1000);
		placeNumber = (value / 1000);
		//std::string romThousandArr[11] = { "","M","MM","MMM","MT","T","TM","TMM","TMMM","unsupported Number","unsupporte Number" }; //I V X L C D M T
		//std::string romHundredArr[11] = { "", "C", "CC","CCC","CD","D","DC","DCC","DCCC", "CM","M" }; // make sure c is 100
		//std::string romTenArr[11] = { "", "X", "XX","XXX","XL","L","LX","LXX","LXXX", "XC","C" };
		//std::string romSingleArr[11] = { "", "I","II","III","IV","V","VI","VII","VIII","IX", "X" };
		std::cout << placeNumber << std::endl;
		cout << romThousandArr[4] << endl;
		romanString.append(romThousandArr[placeNumber]); // this could have been rewritten in less lines of code 
														// rather spend time on OpenGL
		placeNumber = (remainingNumber / 100);
		remainingNumber = (remainingNumber % 100);
		romanString.append(romHundredArr[placeNumber]);

		placeNumber = (remainingNumber / 10);
		remainingNumber = (remainingNumber % 10);
		romanString.append(romTenArr[placeNumber]);

		placeNumber = (remainingNumber);
		romanString.append(romSingleArr[placeNumber]);		
	}

	if (value < 1000 && value > 99)
	{
		placeNumber = (value / 100);
		remainingNumber = (value % 100);
		romanString.append(romHundredArr[placeNumber]);

		placeNumber = (remainingNumber / 10);
		remainingNumber = (remainingNumber % 10);
		romanString.append(romTenArr[placeNumber]);

		placeNumber = (remainingNumber);
		romanString.append(romSingleArr[placeNumber]);
	}
	if (value < 100 && value > 9)
	{
		placeNumber = (value / 10);
		remainingNumber = (value % 10);
		romanString.append(romTenArr[placeNumber]);

		placeNumber = (remainingNumber);
		romanString.append(romSingleArr[placeNumber]);
	}
	if (value < 10)
	{
		romanString.append(romSingleArr[value]);
	}

	if (value == 1000)
	{
		romanString = "M";
	}
	if (value == 100)
	{
		romanString = "C";
	}
	if (value == 10)
	{
		romanString = "X";
	}


	//std::cout << romanString << " - intToRomanVer2 output " << std::endl;

	return blank;
}
