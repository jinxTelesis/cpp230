#include "PayRoll.h"
#include <iostream>



PayRoll::PayRoll()
{
	employeePayH = 15; // default
	hoursWeek = 40;
	taxRate = 0.20;
	payAfTax = 0;
	payBTax = 0;
}


PayRoll::~PayRoll()
{

}

double PayRoll::getAfTax()
{
	if (payAfTax == 0)
	{
		std::cout << "calPayAfterT not called first restart program" << std::endl;
	}
	return payAfTax;
}

double PayRoll::getBTax()
{
	if (payBTax == 0)
	{
		std::cout << "calPayBeforeT not called first restart program" << std::endl;
	}
	return payBTax;
}

void PayRoll::calPayBeforeT() // could be working on stale data
{
	payBTax = hoursWeek *  employeePayH; // extra
}

void PayRoll::calPayAfterT()
{
	payAfTax = hoursWeek * employeePayH * (1 - taxRate); // tested
}

void PayRoll::setEmployeePayH(double PayH) 
{
	employeePayH = PayH;
}

void PayRoll::setHoursWeek(double hWork) // setters
{
	hoursWeek = hWork;
}

void PayRoll::setTaxRate(double taxRate)
{
	taxRate = taxRate;
}

double PayRoll::getEmployeePayH()
{
	return employeePayH;
}

double PayRoll::getHoursWeek() //getters
{
	return hoursWeek;
}

double PayRoll::getTaxRate()
{
	return taxRate;
}
