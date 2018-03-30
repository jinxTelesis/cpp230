#include <iostream>
#include <string>
#include "SnowDepth.h"
#include <iomanip>

using namespace std;

void disDepth(SnowDepth[], int size);
void bubSort(SnowDepth[], int size);
void disTest(SnowDepth[], int size); // just for testing
void selSort(SnowDepth[], int size); // wasn't implemented

int main(int argc, char *argv[]) // maybe implement verbose mode
{
	const int ARRAY_SIZE =7;
	string monthStrIn = "0";
	string dayStrIn; // start with int
	string douChValid;
	double snowFInput = 0.0;


	SnowDepth SnowDarr[ARRAY_SIZE]; 

	cout << "Enter the month as an integer between 1-12" << endl;
	do // used strings for simplifcation of validation realize inferior performance // could make this a funciton
	{
	
		cin >> monthStrIn; // uses strings to validate both number and characters at same time
		if (monthStrIn == "1" || monthStrIn == "2" || monthStrIn == "3" || monthStrIn == "4" || monthStrIn == "5" || monthStrIn == "6" ||
			monthStrIn == "7" || monthStrIn == "8" || monthStrIn == "9" || monthStrIn == "10" || monthStrIn == "11" || monthStrIn == "12")
		{
			break;
		}
		else
		{
			cout << "Invalid input please enter a value between 1-12 as an integer " << endl;
		}
	} while (true);
	
	// could make the next two a function also
	for (int i = 0; i < ARRAY_SIZE; i++) // this has to be called before setDayInMon
	{
		SnowDarr[i].setDateM(monthStrIn);
	}

	for (int i = 0; i < ARRAY_SIZE; i++) // this has to be called after setDateM
	{
		SnowDarr[i].setDaysInMon();
	}
	// first validation works


	// gets user input for starting date
	cout << "Please enter a starting date for the month of: " << SnowDarr[0].getMonName() << " as an Integer" << endl;
	cout << "The last starting date for: " << SnowDarr[0].getMonName() << " is " << SnowDarr[0].getDaysInMonth() - 7 << endl;
	do 
	{
		dayStrIn.erase();
		cin >> dayStrIn; // first if validates characters and numbers to a certain extent
		if (dayStrIn == "1" || dayStrIn == "2" || dayStrIn == "3" || dayStrIn == "4" || dayStrIn == "5" ||
			dayStrIn == "6" || dayStrIn == "7" || dayStrIn == "8" || dayStrIn == "9" || dayStrIn == "10" ||
			dayStrIn == "11" || dayStrIn == "12" || dayStrIn == "13" || dayStrIn == "14" || dayStrIn == "15" ||
			dayStrIn == "16" || dayStrIn == "17" || dayStrIn == "18" || dayStrIn == "19" || dayStrIn == "20" ||
			dayStrIn == "21" || dayStrIn == "22" || dayStrIn == "23" || dayStrIn == "24" || dayStrIn == "25" || dayStrIn == "26" ||
			dayStrIn == "27" || dayStrIn == "28" || dayStrIn == "29" || dayStrIn == "30" || dayStrIn == "31")
		{
			if (stoi(dayStrIn) < SnowDarr[0].getDaysInMonth() - 6) // validates by a varying comparison to end date
			{
				cout << "thanks!" << endl;
				break;
			}
			else
			{
				cout << "input too close to end of month pick an earlier date for a full week" << endl;
			}
		}
		else
		{
			cout << "you entered invalid characters please try again " << endl;
		}
	
	} while (true);

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		SnowDarr[i].setDateDay(stoi(dayStrIn) + i);
	}

	//
	cout << "please enter a two decmial point number under 250" << endl;
	int incSn = 0;
	do // consider making a function // validation maybe under record snowfall highest ever was 189 so 250 inches
	{
		CONTROLRETURN: // got lazy // this catches invalid characters
		snowFInput = 0.0;
		douChValid.erase();
		cin >> douChValid; // validate for characters or no???
		
		try {
			if (stod(douChValid))
			{
				snowFInput = stod(douChValid);
			}
		}
		catch (const std::invalid_argument& error) {
			std::cerr << "Invalid characters enter again " << error.what() << '\n';
			goto CONTROLRETURN; // changed method for validation invalid characters caught and user propmted with error
		}

		if (snowFInput >= 0 && snowFInput < 250) // less than 250 inches // ** check this validation
		{
			// implement correct code
			SnowDarr[incSn].setSnowDepth(snowFInput);
			incSn++;
			cout << "Thanks! please Enter the next value " << endl;
		}
		else
		{
			cout << "invalid input please enter a two decmial point number under 250" << endl;
		}
		if (incSn == 7)
		{
			break;
		}

	} while (true);

	// ******************************** after all validation just sort and display values // dont think the lab asks you to restart 
	bubSort(SnowDarr, ARRAY_SIZE);


	//disTest(SnowDarr, ARRAY_SIZE); // was purely for testing
	disDepth(SnowDarr, ARRAY_SIZE);

	system("pause");
	return 0;
};

void disTest(SnowDepth SnObj[], int size) // displays object only in testing
{
	for (int i = 0; i < size; i++)
	{
		cout << fixed << setprecision(2) << SnObj[i].getSnowDepth() << endl;
	}
}

void disDepth(SnowDepth SnObj[], int size) // displays object
{
	cout << "\n\n\n" << endl; 
	cout << "For " << SnObj[0].getMonName() << endl;
	for (int i = 0; i < size; i++)
	{
		cout << "Snow base depth on day: " << SnObj[i].getDateDay() << " is " << SnObj[i].getSnowDepth() <<  endl;
	}
}

void bubSort(SnowDepth SnObj[], int size) // object sorter
{
	SnowDepth SnTempObj;
	bool swap;

	do{
		swap = false;
		for (int i = 0; i < (size - 1); i++)
		{
			if (SnObj[i].getSnowDepth() > SnObj[i + 1].getSnowDepth()) // calls element n compares with element n+1
			{
				SnTempObj = SnObj[i]; // sets to object if greater found
				SnObj[i] = SnObj[i + 1];
				SnObj[i + 1] = SnTempObj;
				swap = true;
			}
		}

	} while (swap);
}



