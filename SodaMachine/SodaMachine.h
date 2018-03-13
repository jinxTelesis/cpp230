#pragma once
#include <string>
#include <Windows.h>
#include <iostream>


struct SoftDrink
{
	std::string softDrinkN = ""; //softDrinkN, drinkPrice, SodaLeft
	double drinkPrice = 0;
	int SodaSLeft = 0;
	int sodaChoice = 0;
};

class SodaMachine
{
private:
	SoftDrink cola = { "Cola ", 1.00, 20, 0 }; // changed value to test
	SoftDrink rootBeer = { " Root beer ", 1.00, 1, 1 }; // only one for testing reasons
	SoftDrink orangeSoda = { " Orange soda ",1.00, 20, 2 };
	SoftDrink grapeSoda = { " Grape soda ", 1.00, 20, 3 };
	SoftDrink BottledWater = { " Bottled Water ", 1.50, 20, 4 };
	double dailyProfit = 0; // passed to destructor

	std::string textExit = ""; // maybe just remove
	void dailyReport();
	double inputMoney(std::string TextExit); // only used internally
	int selectDrink(std::string textExit); // validation on drink selection //** you moved this

public:
	int baseX = 0; // to shift entire program
	int baseY = 0; // to shift entire program


	HANDLE screen = GetStdHandle(STD_OUTPUT_HANDLE); // this prob should be in another header cpp
	const int SOFT_DR_ARR_SI = 5;
	SoftDrink SoDRarr[5] = { cola, rootBeer,orangeSoda,grapeSoda,BottledWater };
	SodaMachine();
	
	int buyDrink(std::string textExit, std::string coinage); // primary driver of program
	
	void invalidChoice(); // just a display menu
	void displayChoice(); // main menu
	void displayOut(int index, double change); // these values change indexes over array
	void displayPur(int index, double change); // these values change indexes over array
	void placeCursor(int row, int col); //was thinking of overloading this to cout prob would have saved time
	void invalidCoins(); // just a menu
	~SodaMachine(); // destructor calls dailyReport

	//friend std::ostream &operator<<(std::ostream &out,SodaMachine &SodaMachine); // thought about overloading cout with placecursor
	
	

};
/*
std::ostream &operator<<(std::ostream& out,SodaMachine &SodaMachine) { // 

	SodaMachine.placeCursor(100, 100);
	out << "blah";
	return out;
}
*/
