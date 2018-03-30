#include "SnowDepth.h"
#include <string>
#include <iostream>



SnowDepth::SnowDepth()
{
	dateDay =1;
	dateM =1;
	snowDepth =0.0;
	monName = "Not Set";
	monSet = false;
}

void SnowDepth::setDateDay(int dD) // minor validation
{
	if (dD == 1)
	{
		dD = 1;
		std::cout << "invalid input: setting day to 1" << std::endl;
	}

	this->dateDay = dD;
}

void SnowDepth::setDateM(std::string dB) // prob should have made UML some of these aren't used
{
	if (dB == "0")
	{
		dB = "1";
		std::cout << "invalid input: setting month to 1" << std::endl;
	}
	
	this->dateM = dB;
	monSet = true; // checks if this has been called once for valid call of days in that month
}

void SnowDepth::setSnowDepth(double sD)
{
	if (sD < 0)
	{
		sD = 0.0;
	}

	this->snowDepth = sD;

}

int SnowDepth::getDateDay()
{
	return dateDay;
}

std::string SnowDepth::getDateM()
{
	return dateM;
}

double SnowDepth::getSnowDepth()
{
	return snowDepth;
}

int SnowDepth::getDaysInMonth()
{
	return daysInSetMonth;
}

std::string SnowDepth::getMonName()
{
	return monName;
}

void SnowDepth::setDaysInMon() // this limits user input so entire week is entered into system rather than falling on last day of the month
{
	if (!monSet)
	{
		std::cout << "can't set days in month, month is not set" << std::endl;
	}

	switch (std::stoi(dateM))
	{ // this is a string
		case 1:
			daysInSetMonth = 31;
			monName = "January";
			break;
		case 2:
			daysInSetMonth = 28;
			monName = "February";
			break;
		case 3:
			daysInSetMonth = 31; // for validation so user enters a full week // could be designed another way
			monName = "March";
			break;
		case 4:
			daysInSetMonth = 30;
			monName = "April";
			break;
		case 5:
			daysInSetMonth = 31;
			monName = "May";
			break;
		case 6:
			daysInSetMonth = 30; // for validation so user enters a full week // could be designed another way
			monName = "June";
			break;
		case 7:
			daysInSetMonth = 31;
			monName = "July";
			break;
		case 8:
			daysInSetMonth = 31;
			monName = "August";
			break;
		case 9:
			daysInSetMonth = 30;
			monName = "September";
			break;
		case 10:
			daysInSetMonth = 31;
			monName = "October";
			break;
		case 11:
			daysInSetMonth = 30;
			monName = "November";
			break;
		case 12:
			daysInSetMonth = 31;
			monName = "December";
			break;
	}
}
