#include <iostream>
#include <string>
#include <windows.h> // for screen control example
#include "romanCon.h"
#include <iomanip>
#include <ctype.h>
#include "IntToRomCon.h"
#include <limits> // for screen control example


using namespace std;


struct RomanToInt
{
	string RomanNumeral1;
	string RomanNumeral2;
	string RomanNumeral3;
};


bool validateMode();
void romToInterMode();
void IntegerToRomMode(); 
void placeCursor(HANDLE, int, int);
void displayPrompts(HANDLE);// taken out of book, understand what they do, modified a bit
void getUserInput(HANDLE, RomanToInt&);
void displayData(HANDLE, RomanToInt);
void screenControlMode();
//***************************************************************************************************************************************


// thoughts on developing this a need a better method of listing integers than in class which was a fixed value of int to roman
// thats not gonna work for 1000-5000 ints // if statements and division should be about 50 lines
// building if statements realized arrays divided into thousands hundrends and tens and singles and just indexing the remainder value
// intentionally used char arrays even though most of the validation could be more easily done with str built in functions
// good pratice of conversions 
// in IntToRomCon you will see two different member functions a in statement solution, intToRoman(int value); , intToRomanVer2(int value).

// helped 2 students for about an hour each comprehending file structure 

//***************************************************************************************************************************************


int main()
{
	bool mode = false; // * false // determines menu used
	//bool firFlag = false;
	//int slowInc = 0; unused was thinking about threading but didn't
	
	//char userChar;
	//RomanCon RomObj; // just test objects
	//RomObj.setRoman("XXV");
	//RomObj.romanToPostiveinteger();
	//RomObj.printPositiveinteger();
	//IntToRomCon IntObj;
	//IntObj.intToRomanVer2(7); // need seperate for lower values in class
	//IntObj.intToRomanVer2(1777);
	//IntObj.printRoman();
	cout << "\n\n\n\n\n" << endl;
	// need to use intToRomanVer2 if you want to test second array type 
	

	std::cout << "Enter * for Roman Numeral to Integer " << endl;
	std::cout << "Enter & for Integer to Roman Numeral " << endl;
	std::cout << "You may enter -1 to exit at any time, except in screen control mode" << endl;

	std::cout << "option -3 is not a full program but a branch with no validation wouldn't normally code with this structure -1 won't work" << endl;
	std::cout << "enter -3 to enter screen control mode will not work after this point !!!!!!" << endl;
	mode = validateMode(); // calls validation function

	do { // only 
		
		//if statement to bring back mode menu // type # for menu
		if (mode == false) // had different plans for most robust menu with forms didn't have time
		{
			romToInterMode(); // so within the two functions romToInterMode and IntegerToRomMode they just call each other
		}

		if (mode == true)
		{
			IntegerToRomMode();
			//bool validateMode();
		}
		
	
	} while(1);

	system("pause");
	return 0;

}

bool validateMode()
{
	bool modeFlag = false;
	char ch[20];
	int chSize =20;
		do {
			cin >> ch;

			if (ch[0] == '-' && ch[1] == '1') // will catch -1 before next valid
			{
				exit(1);
			} // keep at top of all loops with exit

			if (ch[0] == '-' && ch[1] == '3')
			{
				screenControlMode();
			}

			if (!((ch[0] == '*') || (ch[0] == '&'))) // just validates two menu choices then those modes take over, was thinking about more options up here but left out
			{                                       // remains of a menu that might have had screen control forms but left out, still works
				std::cout << "invalid selection please enter again " << endl;
				for (int i = 0; i < chSize; i++)
					ch[i] = 0;
			}
			else
			{
				if (ch[0] == '*')
				{
					modeFlag = false;
				}

				if (ch[0] == '&')
				{
					modeFlag = true;
				}

				break;
			}
		} while (1);

		//std::cout << "got here" << endl;
		return modeFlag;

}
// this works but does not reset increment always and needs to tell you about bad input

void romToInterMode() // testing romToInt not other pull this after test character to get into this *
{
	RomanCon lRomObj1; // local class object for function to use
	//bool modeFlag = false; 
	char ch[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // char to get into * need to change to letters not 0 an 1
	int chSize = 20;
	int incrementTruth = 0; // one of the primary means of validation makes sure characters are correct 
	bool validInput = false;
	string validateCh = "";
	int inputLenhSet = 19; // array size is only one more

	do {
		cout << "\n\n" << endl;
		cout << "please enter a roman numeral to up" << inputLenhSet << "characters in length " << endl;
		cout << "The valid charactes are I, V, X, L, C, D, M, and T. T is for uppercase V or 5000 " << endl;
		cout << " you can enter -1 at any point to exit, also -2 to switch to integer to roman " << endl;
		cout << " \n\n" << endl;
		validateCh = ""; // this and next line are to reset input values
		validInput = false; // resets
		ch[0] = 'a'; /// to reset array buff value
		for (int i = 1; i < chSize; i++)
		{
			ch[i] = 0;
		} // to rest array buff value

		cin >> validateCh; // checks length sets loop back up if invalid
		if (validateCh.length() > inputLenhSet) // changed from 6 to 10
		{
			cout << "invalid input too long";
			validateCh = "";
			continue; // shouldn't be able to get past this with input that is too long
		}

		/////////////////////////////////////////////////////////////////////////
		// need to reput string to char for program to work
		for (int i = 0; i < validateCh.length(); i++)
		{
			ch[i] = validateCh[i]; // sets to chars
		}

		cout << endl;
		//cout << "this is reading char" << endl;
		//for (int i = 0; i < validateCh.length(); i++) // character to get into *
		//	cout << ch[i] << endl;

		//////////////////////////////////////////////////////////////////////
		
		if (ch[0] == '-' && ch[1] == '1') // will catch -1 before next valid
		{
			exit(1);
		} // tests exit conditions
		if (ch[0] == '&') // alternative way to call other mode
		{
			IntegerToRomMode();
		}

		if (ch[0] == '-' && ch[1] == '2') // will catch -2 before next valid
		{
			IntegerToRomMode(); // switches modes
		}

		// need a function or code to check if input is valid charcter strings
		
		// add toupper after // 
		//for (int i = 0; i < chSize; i++)
		//{
		//	ch[i] == toupper(ch[i]);
		//}
		//for (int i = 0; i < chSize; i++)
		//	cout << ch[i] << endl;
		//cout << "that was output right before validator" << endl;

		/* removed the upper case could cause issues with special characters maybe? might only work on alpha didn't risk*/
		// could have been implemented would have had to check 
		for (int i = 0; i < inputLenhSet; i++)//I V X L C D M T // changed from 6 to 10
		{

			if (ch[i] == 'I' || ch[i] == 'V' || ch[i] == 'X' || ch[i] == 'L' || ch[i] == 'C' || // you broke this or the other
				ch[i] == 'D' || ch[i] == 'M' || ch[i] == 'T' || ch[i] == 1 || ch[i] == 0) // 1 and 0 mess up validation
				incrementTruth++; // can be fooled by 0000 etc // can be solved by only useing certain characters if really needed example set default to all 'a'
			if (incrementTruth == inputLenhSet) // *** changed to 10
			{
				cout << "valid input thanks!" << endl; // * char to get into menu
				incrementTruth = 0; // check in other
				validInput = true;
			}
			
		}
		//cout << incrementTruth << " that was increment truth " << endl;

		if (!(validInput))
		{
			cout << "That input was invalid, it contained invalid characters " << endl;
			validInput = false;
			continue;
		}

		lRomObj1.setRoman(ch); 
		lRomObj1.romanToPostiveinteger(); // the actual calls for output and conversion
		lRomObj1.printPositiveinteger();
	
	
		// don't want to pass array otherwise this would be a function
		//ch[0] == 1; // clears array for next iteration of input
		//for (int i = 1; i < chSize; i++)
		//{
		//	ch[i] = 0;
		//}
		///////
	
	} while (1);


}

void IntegerToRomMode() // & to get to
{
	IntToRomCon iTRomLoc; // local class object for int to roman mode

	bool modeFlag = false;
	char ch[20] = { 'a',0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
	char chinput[20] = { 0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0 }; // used for padding validation // realize just using string would be easier
	char one, two, three, four; // for padding unpacking realize string would be easier
	int chSize = 20;
	int incrementTruth = 0; // this value is most of the validation
	int sizeCount = 0;
	string concatinator = "";  ///*************************************************************
	bool validInput = false;  /// practice of conversions make this section overly complex for the amount of validation
	string validateCh = "";   ///************************************************************

	
	// know issue 0000 is valid won't crash but no return
	do {
		cout << "Integer to Roman mode " << endl; // perhaps this should be a seperate display function
		cout << "please enter an integer under 8000" << endl;
		cout << "can type -1 to exit at any time and -2 to switch to Roman to Integer mode" << endl;


		ch[0] = 'a'; /// to reset
		for (int i = 1; i < chSize; i++)// to reset, know extra processing use
		{
			ch[i] = 0;
		}
		validateCh = ""; // reset
		cin >> validateCh; // & to get to

		if (validateCh.length() > 4) // add this to other menu???
		{
			cout << "too many digits please enter an Integer up to 1000 " << endl;
			
			continue;
		}

		for (int i = 0; i < validateCh.length(); i++)
		{
			ch[i] = validateCh[i]; // sets to chars
			sizeCount++;
		}

		for (int i = validateCh.length(); i < (20 - validateCh.length()); i++) // this for loop padds array with 0
		{
			ch[i] = '0';
		}

		if (ch[0] == '-' && ch[1] == '1') // will catch -1 before next valid
		{
			exit(1);
		} 

		if (ch[0] == '*') // alterante way to access other mode
		{
			romToInterMode();
		}

		if (ch[0] == '-' && ch[1] == '2') // returns to previous menu
		{
			romToInterMode();
			//return 1; // shrugs
		}
		
		//for (int i = 0; i < 4; i++) // just outputs condition
		//	cout << ch[i];
		//cout << endl;

		incrementTruth = 0; // primary validation after length
		for (int i = 0; i < 4; i++) // checks if digit
		{
			if (isdigit(ch[i]))
			{
				incrementTruth++;
			}
		}
		//cout << incrementTruth << endl;

		validInput = false;
		if (incrementTruth == 4)
		{
			cout << "valid input thanks!" << endl;
			validInput = true;
		}

		if (!validInput)
		{
			incrementTruth = 0; //needs to be in two places
			continue; // loops back around if invalid
			cout << "you entered invalid input please try again " << endl;
		}

		for (int i =0; i < sizeCount; i++) //unpads
			chinput[i] = ch[i];

		sizeCount = 0;

		one = chinput[0]; // unpacks
		two = chinput[1];
		three = chinput[2];
		four = chinput[3];

		concatinator += one; // converts back to string
		concatinator += two;
		concatinator += three;
		concatinator += four;

		one = '\0'; // this how you null a character can't seem to have emtpy value
		two = '\0';
		three = '\0';
		four = '\0';
		chinput[0] = '\0';
		chinput[1] = '\0';
		chinput[2] = '\0';
		chinput[3] = '\0';
		
		//cout << "this is concatinator's value" << concatinator << endl;
		int i_dec = std::stoi(concatinator); // converts the concatinated string to int


		if (validInput)
		{
			iTRomLoc.intToRoman(i_dec);
			iTRomLoc.printRoman();
		}
		

		ch[0] = 'a'; // resets character array
		for (int i = 0; i < chSize; i++)
		{
			ch[i] == 0;
		}


		concatinator = ""; // resets all of them, would make more sense to put it at the start of this function than end
		sizeCount = 0;
		incrementTruth = 0;
		validInput = false;
	} while (1);

}

void placeCursor(HANDLE screen, int row, int col) // takes x y makes a COORD to passes along with screen handle to update cursor
{
	COORD position; 
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position); // seen in book
}

void displayPrompts(HANDLE screen) // menu based calls to place cursor
{
	placeCursor(screen, 3, 25);
	cout << "******** Enter a three roman numerals to convert to interters (no validation)" << endl;
	placeCursor(screen, 5, 25);
	cout << "Roman Numeral one: " << endl;
	placeCursor(screen, 7, 25);
	cout << "Roman Numeral two:" << endl;
	placeCursor(screen, 9, 25);
	cout << "Roman Numeral three:" << endl;
}

void getUserInput(HANDLE screen, RomanToInt &input)
{
	placeCursor(screen, 5, 43); // input form based on calls to place cursor
	cin >> input.RomanNumeral1;
	placeCursor(screen, 7, 44);
	cin >> input.RomanNumeral2;
	placeCursor(screen, 9, 47);
	cin >> input.RomanNumeral3;

}

void displayData(HANDLE screen, RomanToInt output)
{
	placeCursor(screen, 10, 0);
	cout << "Here is the Roman numerals converted to ints";
	RomanCon romDisplay;
	romDisplay.setRoman(output.RomanNumeral1); // calls to object without validation
	romDisplay.romanToPostiveinteger(); // please don't grade on this other normal modes outside screen control have validation
	romDisplay.printPositiveinteger();
	romDisplay.setRoman(output.RomanNumeral2);
	romDisplay.romanToPostiveinteger();
	romDisplay.printPositiveinteger();
	romDisplay.setRoman(output.RomanNumeral3);
	romDisplay.romanToPostiveinteger();// please don't grade on this other normal modes outside screen control have validation
	romDisplay.printPositiveinteger();
}

void screenControlMode() 
{
	RomanToInt input;


	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	system("CLS");
	// understood this is not good programming structure essentially a second main

	do {
		displayPrompts(screen); // calls to the 3 functions
		getUserInput(screen, input);
		system("CLS"); // understood not proper way to clear screen
		system("pause");
		displayData(screen, input);
		system("pause"); // understood not proper way to clear screen
		system("CLS");
	} while (1);
	
}
