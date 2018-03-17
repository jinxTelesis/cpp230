#pragma once
#include <iostream>
#include <string>
#include <fstream>
#include "PayRoll.h"
#include <iomanip>
#include <ios>

using namespace std;

int main() 
{
	string storInp;
	string findTemp = " ";
	string dataString1;
	string dataString2;

	double tempHours = 0.0;
	double tempRate = 0.0;
	int fileSize = 0;
	
	string fileName = "C:\\Users\\dremo\\OneDrive\\Desktop\\payroll.dat";
	fstream fileHandle(fileName, ios::in || ios::out);
	
	PayRoll payArray[11]; // hours rate

	if (!fileHandle) { // for size forgot other way, have like 200 saves examples hard to find
		cout << "error no file size" << endl;
	}
	else
	{
		while (!(fileHandle.eof()))
		{
			getline(fileHandle, storInp);
			fileSize++;
		}

		
		
	}
	storInp.clear(); // resets for file opening
	fileHandle.close();
	fileHandle.clear();
	fileHandle.open(fileName, ios::in || ios::out);
	fileHandle.seekg(0, ios::beg);
	// dont think file reset
	ifstream filehand2(fileName);

	for (int index = 0; index < fileSize; index++) // could have just been input as two values, rather break up with string subs
	{

		getline(filehand2, storInp);
		auto found = storInp.find(findTemp); // finds break
		dataString1.append(storInp, 0, found); // uses find to  break at white space
		dataString2.append(storInp, found, (storInp.length())); 

		tempHours = stod(dataString1); // converts back to doubles
		tempRate = stod(dataString2);

		payArray[index].setHoursWeek(tempHours);
		payArray[index].setEmployeePayH(tempRate);
		dataString1.clear();// resets
		dataString2.clear();

		//cout << fixed << setprecision(2) << payArray[index].getHoursWeek() << endl;
		//cout << fixed << setprecision(2) << payArray[index].getEmployeePayH() << endl;

	}

	for (int index = 0; index < fileSize; index++)
	{
		payArray[index].calPayAfterT(); // does calculation
	}

	for (int index = 0; index < fileSize; index++)
	{
		cout << payArray[index].getAfTax() << endl; // displays output
	}

	//payArray[0].setEmployeePayH(10);
	//payArray[1].setEmployeePayH(12);
	//payArray[2].setEmployeePayH(14);

	//cout << fixed << setprecision(2) << payArray[0].getEmployeePayH() << endl;
	//cout << fixed << setprecision(2) << payArray[1].getEmployeePayH() << endl;
	//cout << fixed << setprecision(2) << payArray[2].getEmployeePayH() << endl;


	fileHandle.close();
	system("pause");
	return 0;
}
