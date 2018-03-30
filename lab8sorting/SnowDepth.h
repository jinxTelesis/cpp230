#pragma once

#include <string>

class SnowDepth
{
private:
	bool monSet;
	int dateDay;
	int daysInSetMonth;
	
	double snowDepth;
	
	std::string dateM;
	std::string monName;
	

public: // implement if the date is a specific value the day total stored
	SnowDepth();
	void setDateDay(int dB);///
	void setDateM(std::string dM);
	void setDaysInMon();
	void setSnowDepth(double sD);

	int getDaysInMonth();
	int getDateDay();
	std::string getDateM();
	std::string getMonName();
	double getSnowDepth();

	//setSnowDepth()

	
};

