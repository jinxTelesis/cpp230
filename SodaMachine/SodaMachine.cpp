#include "SodaMachine.h"
#include <iostream>
#include <string>
#include <iomanip>


//cola, rootBeer, orangeSoda, grapeSoda, BottledWater
SodaMachine::SodaMachine()
{
	
}


SodaMachine::~SodaMachine()
{
	system("CLS");
	dailyReport(); // calls a report while exiting 
	system("pause"); // tested this destructor artifically at start
}

void SodaMachine::displayChoice() // Y inverted , X normal
{
	system("CLS"); // just a menu with some ascii graphics
	system("Color 00");
	int moveCursorX = 0;
	placeCursor(baseY + 1, baseX + 0 + (moveCursorX));
	for (int i = 0; i < 150; i++)
	{
		moveCursorX += 1;
		std::cout << "*"<< std::endl;
		placeCursor(baseY + 1, baseX + 0 + (moveCursorX));
		Sleep(5);
	}
	moveCursorX = 0;
	placeCursor(baseY + 1, baseX + 0 + (moveCursorX));
	for (int i = 0; i < 75; i++)
	{
		moveCursorX = moveCursorX + 2;
		std::cout << "-" << std::endl;
		placeCursor(baseY + 1, baseX + 0 + (moveCursorX));
		Sleep(5);
	}
	moveCursorX = 0;
	placeCursor(baseY + 3, baseX + 2);
	std::cout << "< Enter -1 to quit >" << std::endl;
	//softDrinkN, drinkPrice, SodaLeft
	placeCursor(baseY +3 , baseX + 28);
	std::cout << "^^^^^^^^^^^^^*********welcome to Andre's Soda Machine of Wonder ******^^^^^^^^^" << std::endl;
	placeCursor(baseY +5, baseX + 28);
	std::cout << "***********************" << "here are the soft drinks to pick from" << "********************" << std::endl;
	placeCursor(baseY +7, baseX + 28);
	for (int i = 0; i < 5; i++)
	{
		moveCursorX += 16;
		std::cout << SoDRarr[i].softDrinkN << std::endl;
		placeCursor(baseY + 7, baseX + 28 + (moveCursorX));
	}
	moveCursorX = 0;// resets
	std::cout << std::endl;
	placeCursor(baseY + 9, baseX + 13);
	std::cout << "Soda Price: " << std::endl; // thought about overloading cout, prob would have saved time with placeCursor
	for (int i = 0; i < 5; i++)
	{
		moveCursorX += 18;
		placeCursor(baseY + 9, baseX + 12 + (moveCursorX - i));
		std::cout << SoDRarr[i].drinkPrice;
		
	}
	std::cout << std::endl;
	moveCursorX = 0;
	placeCursor(baseY + 11, baseX + 8);
	std::cout << "Enter choice for: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		moveCursorX += 16;
		placeCursor(baseY + 11, baseX + 12 + (moveCursorX));
		std::cout << "choice:  " << SoDRarr[i].sodaChoice;
	}
	placeCursor(baseY + 15, baseX + 30);
	std::cout << "Enter your choice for soda below " << std::endl;
	placeCursor(baseY + 17, baseX + 20);
	std::cout << "Enter 1-5 for soda, hit enter" << std::endl;
	placeCursor(baseY + 19, baseX + 20);
	std::cout << "Enter dollar amount under 10 in decimal form" << std::endl;
	placeCursor(baseY + 17, baseX + 62);
	moveCursorX = 0;
	placeCursor(baseY + 23, baseX + 0 + (moveCursorX));
	for (int i = 0; i < 150; i++)
	{
		moveCursorX += 1;
		std::cout << "*" << std::endl;
		placeCursor(baseY + 23, baseX + 0 + (moveCursorX));
		Sleep(5);
	}
	moveCursorX = 0;
	placeCursor(baseY + 1, baseX + 0 + (moveCursorX));
	for (int i = 0; i < 75; i++)
	{
		moveCursorX = moveCursorX + 2;
		std::cout << "-" << std::endl;
		placeCursor(baseY + 23, baseX + 0 + (moveCursorX));
		Sleep(5);
	}
	moveCursorX = 0;
	placeCursor(baseY + 25, baseX + 0); 
	std::cout << R"(   _____              .___            /\                          .___           _____                .__    .__               
  /  _  \   ____    __| _/______   ___)/  ______   __________   __| _/____      /     \ _____    ____ |  |__ |__| ____   ____  
 /  /_\  \ /    \  / __ |\_  __ \_/ __ \ /  ___/  /  ___/  _ \ / __ |\__  \    /  \ /  \\__  \ _/ ___\|  |  \|  |/    \_/ __ \ 
/    |    \   |  \/ /_/ | |  | \/\  ___/ \___ \   \___ (  <_> ) /_/ | / __ \_ /    Y    \/ __ \\  \___|   Y  \  |   |  \  ___/ 
\____|__  /___|  /\____ | |__|    \___  >____  > /____  >____/\____ |(____  / \____|__  (____  /\___  >___|  /__|___|  /\___  >
        \/     \/      \/             \/     \/       \/           \/     \/          \/     \/     \/     \/        \/     \/)" << std::endl;

}

void SodaMachine::placeCursor(int row, int col) // this maybe should be in seperate header cpp
{
	COORD position;
	position.Y = row;
	position.X = col;
	SetConsoleCursorPosition(screen, position);
}

int SodaMachine::selectDrink(std::string TextExit) // one of two validators
{

	int selection = 0;
	if (TextExit == "-1")
	{
		exit(1);
	}

	if (TextExit.length() > 1)
	{
		invalidChoice(); //needs to be invalid choice
		return -1;
	}
	if (TextExit[isdigit(0)] == '0' || TextExit[isdigit(0)] == '1' || TextExit[isdigit(0)] == '2' || TextExit[isdigit(0)] == '3' ||
		TextExit[isdigit(0)] == '4')
	{
		selection = stoi(TextExit); // where you left off // duplicate but whatever
	}
	else
	{
		return -1;
	}
	// validation needs work  
	selection = stoi(TextExit);
	return selection;
}


double SodaMachine::inputMoney(std::string TextExit) // validates and calls invalid input
{
	int doesN = 0;
	if (TextExit == "-1")
	{
		exit(1);
	}
	// have to reset TextExit somewhere.
	//this->textExit = TextExit;
	double cash = 0.0;
	int strValidationSize = 4;
	placeCursor(baseY + 35, baseX + 50);
	if (TextExit.length() > strValidationSize)
	{
		invalidCoins();
		return -1; // invalid
	}

	//if (TextExit.length() == 1) // maybe pad maybe not
	//{
	//	TextExit.append()
	//}

	for (int i = 0; i < strValidationSize; i++)
	{
		if (TextExit[isdigit(i)] == '0' || TextExit[isdigit(i)] == '1' || TextExit[isdigit(i)] == '2' || TextExit[isdigit(i)] == '3' ||
			TextExit[isdigit(i)] == '4' || TextExit[isdigit(i)] == '5' || TextExit[isdigit(i)] == '6' || TextExit[isdigit(i)] == '7' ||
			TextExit[isdigit(i)] == '8' || TextExit[isdigit(i)] == '9' || (TextExit[i] == '.')) // validation needs work  
		{ // take this out once validation done // take out of loop
			//system("CLS");
			//displayChoice();// take this out of loop
			//placeCursor(baseY + 50, baseX + 75);
			//std::cout << "passed validation in input money" << std::endl; // take this out once validation done
			doesN++;
		}
		else
		{
			invalidCoins();
			//this->textExit = "";
			return -1;
		}
	}

	cash = stod(TextExit);
	// 
	
	//std::cout << "this got here" << std::endl;
	//this->textExit = ""; // resets var
	//std::cout << TextExit << std::endl;


	return cash;
}

int SodaMachine::buyDrink(std::string textExit, std::string coinage) // this does all the calculations
{
	double cash = 0; // dailyprofit // needs selection needs price of selection needs to make change
	int drinkSel = 0; // index for struct soda  values
	double price = 0;
	double change = 0;
	int numSoda = 0;
	int sodaDecTem = 0;

	drinkSel = selectDrink(textExit);// calls menu // the book says structure this in here don't like this structure
	placeCursor(baseY +50, baseX +25);
	//std::cout << "this is drinkSel value: " << drinkSel << std::endl;
	Sleep(100); // for debugging take out
	if (drinkSel == -1) // works as intended
	{
		return -1;
	}
	price = SoDRarr[drinkSel].drinkPrice;
	

	//displayEntMoney(); unnesccary call
	cash = inputMoney(coinage); // quit returns the money

	if (cash < price) // restarts loop after invalid
	{
		invalidCoins();
		return -1;
	}
	// put validation here for amount


	if (cash == -1) // restarts loop after invalid
	{
		return -1;
	}
	


	numSoda = SoDRarr[drinkSel].SodaSLeft;
	
	//std::cout << "num of soda" << numSoda << std::endl;
	//system("pause");
	if (numSoda == 0) // this is the out of that soda caller
	{
		system("CLS");
		placeCursor(baseY + 0, baseX + 0);
		displayOut(drinkSel, cash); // out of soda display
		Sleep(1500);
		return -1;
	}

	// price and change
	price = SoDRarr[drinkSel].drinkPrice;
	change = cash - price;
	placeCursor(baseY + 0, baseX + 0);
	if (change < 0)
	{
		change = 0.0;
	}
	displayPur(drinkSel, change); // this one needs change not cash
	
	// change money we have and lower selection
	dailyProfit += price;
	SoDRarr[drinkSel].SodaSLeft--;

	//std::cout << SoDRarr[drinkSel].SodaSLeft << std::endl;
	// add a sale message 

	return 0;
}

void SodaMachine::dailyReport()
{
	system("Color 25"); // this is what is called by the destructor to report how much cash and sodas left
	int incrCur = 0;
	placeCursor(baseY + 5, baseX + 30);
	std::cout << "this is how much money was collected " << std::fixed << std::setprecision(2) << dailyProfit << std::endl;
	placeCursor(baseY + 7, baseX + 30);
	for (int i = 0; i < SOFT_DR_ARR_SI; i++)
	{
		incrCur += 2;
		placeCursor(baseY + 7 + incrCur, baseX + 30);
		std::cout << "# of " << SoDRarr[i].softDrinkN << SoDRarr[i].SodaSLeft << "   ***  " << std::endl;
	}
	std::cout << std::endl;
	system("pause");
	//std::cout << "called correctly" << std::endl;
}

// add graphics
void SodaMachine::invalidCoins()
{
	system("CLS");
	system("Color 04");
	placeCursor(baseY + 20, baseX + 300);
	std::cout << std::endl;
	placeCursor(baseY + 5, baseX + 35);
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	placeCursor(baseY + 7, baseX + 35);
	std::cout << "*******************************************************" << std::endl;
	placeCursor(baseY + 9, baseX + 35);
	std::cout << "******" << "invalid  payment  enter  again " << "******" << std::endl;
	placeCursor(baseY + 11, baseX + 35);
	std::cout << "******" << "only digits and decimals please" << "******" << std::endl;
	placeCursor(baseY + 13, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 15, baseX + 35);
	std::cout << "********"<< "only up to 4 characters please" <<"**********" << std::endl;
	placeCursor(baseY + 17, baseX + 35);
	std::cout << "*********"<< "we don't take 10s!"<<"*********************" << std::endl;
	placeCursor(baseY + 19, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 21, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 23, baseX +35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 25, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 27, baseX + 35);
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	Sleep(5000);
	//placeCursor(17, 62);
	//system("Color 02");
	//displayChoice();
} 

// add graphics
void SodaMachine::invalidChoice()
{
	system("CLS");
	system("Color 04");
	placeCursor(baseY + 20, baseX + 300);
	std::cout << std::endl;
	placeCursor(baseY + 5, baseX + 35);
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	placeCursor(baseY + 7, baseX + 35);
	std::cout << "*******************************************************" << std::endl;
	placeCursor(baseY + 9, baseX + 35);
	std::cout << "******" << "invalid  choice  enter  again " << "********" << std::endl;
	placeCursor(baseY + 11, baseX + 35);
	std::cout << "******" << "only digits please" << "*********************" << std::endl;
	placeCursor(baseY + 13, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 15, baseX + 35);
	std::cout << "********" << "only up to 1 character please" << "**********" << std::endl;
	placeCursor(baseY + 17, baseX + 35);
	std::cout << "*********" << "thats not a choice dude!" << "**************" << std::endl;
	placeCursor(baseY + 19, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 21, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 23, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 25, baseX + 35);
	std::cout << "********************************************************" << std::endl;
	placeCursor(baseY + 27, baseX + 35);
	std::cout << "^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^^" << std::endl;
	Sleep(4000);
	//placeCursor(17, 62);
	//system("Color 02");
	//displayChoice();
}

void SodaMachine::displayOut(int index, double change)
{
	system("CLS");
	placeCursor(baseY + 13, baseY + 15);
	std::cout << "******************************************************************************" << std::endl;
	placeCursor(baseY + 15, baseX + 15);
	std::cout << "out of " << SoDRarr[index].softDrinkN << "soda sorry" << std::endl;
	placeCursor(baseY + 17, baseX + 15);
	std::cout << "******************************************************************************" << std::endl;
	placeCursor(baseY + 19, baseX + 15);
	std::cout << "This is your change back " << std::fixed << std::setprecision(2) << change << std::endl;
	placeCursor(baseY + 19, baseX + 15);
	std::cout << "******************************************************************************" << std::endl;
}

void SodaMachine::displayPur(int index, double change)
{

	system("CLS");
	switch (index) {
		case 0:
			system("Color 08");
			break;
		case 1:
			system("Color F5");
			break;
		case 2:
			system("Color C7");
			break;
		case 3:
			system("Color 57");
			break;
		case 4:
			system("Color 76");
			break;
	};
	
	placeCursor(baseY + 0, baseX + 50);
	std::cout << R"(
		           __
		       .-"`` _``"-.
		      /'.   '.(##)'\
		      |  `'----'`  |
		      |        ----|
		      |        . .-|
		      | .::::. |_| |
		      |::::''':.-. |
		      |;,,;;;;;|_|_|
		      | ';;;;' . . |
		      |        |_|_|
		      |        .-. |
		      \        |_|_/
		       `.________.'
		)" << std::endl;
	
	placeCursor(baseY + 2, baseX + 45);
	std::cout << "here is your soda " << std::endl;
	placeCursor(baseY + 4, baseX + 45);
	std::cout << "Here is your change back " << std::fixed << std::setprecision(2) << change << std::endl;
	placeCursor(baseY + 6, baseX + 45);
	std::cout << "please take this wondrous " << SoDRarr[index].softDrinkN << std::endl;
	Sleep(4000);
	
}

/*
void SodaMachine::displayEntMoney() // Y inverted , X normal
{
	system("CLS");
	system("Color 03");
	int moveCursorX = 0; // for loop displacement
	placeCursor(baseY + 3, baseX + 2);
	std::cout << "< Enter -1 to quit >" << std::endl;
	//softDrinkN, drinkPrice, SodaLeft
	placeCursor(baseY + 3, baseX + 28);
	std::cout << "^^^^^^^^^^^^^*********welcome to Andre's Soda Machine of Wonder ******^^^^^^^^^" << std::endl;
	placeCursor(baseY + 5, baseX + 28);
	std::cout << "***********************" << "here are the soft drinks to pick from" << "********************" << std::endl;
	placeCursor(baseY + 7, baseX + 28);
	for (int i = 0; i < 5; i++)
	{
		moveCursorX += 16;
		std::cout << SoDRarr[i].softDrinkN << std::endl;
		placeCursor(baseY + 7, baseX + 28 + (moveCursorX));
	}
	moveCursorX = 0;// resets
	std::cout << std::endl;
	placeCursor(baseY + 9, baseX + 13);
	std::cout << "Soda Price: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		moveCursorX += 18;
		placeCursor(baseY + 9, baseX + 12 + (moveCursorX - i));
		std::cout << SoDRarr[i].drinkPrice;

	}
	std::cout << std::endl;
	moveCursorX = 0;
	placeCursor(baseY + 11, baseX + 8);
	std::cout << "Enter choice for: " << std::endl;
	for (int i = 0; i < 5; i++)
	{
		moveCursorX += 16;
		placeCursor(baseY + 11, baseX + 12 + (moveCursorX));
		std::cout << "choice:  " << SoDRarr[i].sodaChoice;
	}
	placeCursor(baseY + 15, baseX + 50);
	std::cout << "Please Enter coins for soda below" << std::endl;
	placeCursor(baseY + 17, baseX + 62);

}
*/

