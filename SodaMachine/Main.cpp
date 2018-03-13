#include <iostream>
#include <string>
#include "SodaMachine.h"


#include <windows.h>

using namespace std;

void placeCursor(HANDLE screen, int row, int col); // remove maybe originally had few placements in main rather than in the class

int main() {
	system("Color 02");
	//HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE);
	
	SodaMachine sMachineOne;

	
	//sMachineOne.displayChoice();
	string textExit_choice; // takes two cin inputs at a time
	string coinage;
	int externalBaseY = 0;// baseY and X to shift all content over used for testing the internal one in the class actually controls
	int externalBaseX = 0;
	int loopConr = 0; // controls flow of program
	// do all validation as strings
	//sMachineOne.displayChoice(); // one time display to start
	//sMachineOne.displayChoice();

	do { // made flow simpler than last program
		
		//sMachineOne.placeCursor(externalBaseY +17, externalBaseX + 62);
		//sMachineOne.~SodaMachine(); //testing destructor
		system("CLS");
		system("Color 34");
		sMachineOne.displayChoice(); // needs to display before prompts // can just call internal one...
		sMachineOne.placeCursor(sMachineOne.baseY + 17, sMachineOne.baseX + 66);
		//placeCursor(sMachineOne.screen, 17, 66); // gets screen from class object thought about implementing outside of class little weird screen handle in it
		cin >> textExit_choice;
		if (textExit_choice == "-1") // exit condition // this moved test
		{
			sMachineOne.~SodaMachine();// needed to put this here or the destructor will never be called, it does work though
			exit(1);
		}
		sMachineOne.placeCursor(sMachineOne.baseY + 19, sMachineOne.baseX + 66);
		//placeCursor(sMachineOne.screen,19,66); 
		cin >> coinage; // 

		if (textExit_choice == "-1") // exit condition
		{
			sMachineOne.~SodaMachine(); // needed to put this here or the destructor will never be called, it does work though
			exit(1); // has to do with stack exit 
		}
		else
		{
			loopConr = sMachineOne.buyDrink(textExit_choice, coinage);
			if (loopConr == -1 || loopConr == -2)
			{
				continue;
			}
		}

		if (loopConr == 0) // was used for debugging when conditions worked
		{
			//cout << "validation worked" << endl;
			Sleep(100);
		}
	
	} while (1);


	system("pause");
	return 0;
}

void placeCursor(HANDLE screen, int row, int col) // few calls had to be outside of the class that used it by default
{
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}


