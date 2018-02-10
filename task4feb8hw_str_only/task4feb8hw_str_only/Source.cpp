/***************************************************
this solution intentionally has no Vectors arrays or string streams
****************************************************/

#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>

using namespace std;

void printFunction(int numOfcolumns, int numOfRows, int uniClaNum); // function takes values and sets up pretty print

int main()
{
	string fileLocation = "C:\\Users\\dremo\\OneDrive\\Desktop\\IRIS.csv"; // makes it easier to replace
	fstream excelfile(fileLocation); // file stream
	string totalFile; // stores entire file
	string getOneLine; // stores one line for row calculations
	string compareStr; // string value getline tested against a list of classes

	string class1, class2, class3, class4, class5;
	class1 = "setosa"; // list of possible classes in file
	class2 = "virginica"; // can't think of a way to do it with strings without knowing ahead of time
	class3 = "versicolor"; // vector // array // string streams char arrays can all filter out other data and define changes to get without preset classes
	class4 = "toad"; // maybe filter out alpha numeric but that has to be characters // could just test first value
	class5 = "virtual";
	string teststr = "setosa";
	int uniClaNum = 0;

	bool flag1, flag2, flag3, flag4, flag5; // need a true false flag because don't want to increment each time value is found just first
	flag1 = false, flag2 = false, flag3 = false, flag4 = false, flag5 = false;

	int rowCounter = 0;
	int columnCounter = 0;

	while (!excelfile.eof()) //reads till end of file
	{
		cout << totalFile << endl;
		excelfile >> totalFile;



		if (rowCounter == 5)
		{
			excelfile >> getOneLine;
		}

		rowCounter++;// increments rows while the while loop runs
	}
	//cout << "number or rows in file is " << rowCounter << endl;
	//cout << getOneLine << endl;
	columnCounter = count(getOneLine.begin(), getOneLine.end(), ','); // counds string begining and end 
	columnCounter++; // this is because there will be one more value than the splitting delimiter aka first value 1,2 etc
					 //cout << "number of coumnsin file is " << columnCounter << endl;
	excelfile.close();
	excelfile.clear();
	ifstream excelfile2(fileLocation); // was getting ambigous type issues when calling function passing file streams
									   // when i passed file streams in other test programs it worked fine, had issues in this one shrugs


	for (int index = 0; index < rowCounter * columnCounter; index++) // index over every value
	{
		getline(excelfile2, compareStr, ','); // gets next value to delimiter
											 
											 

		int found1 = compareStr.find(class1); // checks each value against the class value
		if (found1 != string::npos) // if not not found sets flag to true so value counted once rather than multiple times
		{
			flag1 = true;
		}

		int found2 = compareStr.find(class2); // works
		if (found2 != string::npos)
		{
			flag2 = true;
		}

		int found3 = compareStr.find(class3);
		if (found3 != string::npos)
		{
			flag3 = true;
		}

		int found4 = compareStr.find(class4);
		if (found4 != string::npos)
		{
			flag4 = true;
		}

		int found5 = compareStr.find(class5);
		if (found5 != string::npos)
		{
			flag5 = true;
		}
	}

	if (flag1) // increments up if a flag was set to true aka the value was found 
		uniClaNum++;
	if (flag2)
		uniClaNum++;
	if (flag3)
		uniClaNum++;
	if (flag4)
		uniClaNum++;
	if (flag5)
		uniClaNum++;


	//cout << "The number of unique classes is " << uniClaNum << " " << endl;
	printFunction(columnCounter, rowCounter, uniClaNum); // call to a nicely formatted function call
														 //excelfile.close(); // this file was closed somewhere else
	excelfile2.close();
	system("pause");

	return 0;
}

void printFunction(int numberOfColumns, int numOfRows, int uniClaNum) // function prints the values
{
	cout << endl << "\n\n\n\n\n" << endl;
	cout << left << setw(40) << "The number of rows  " << setw(5) << numberOfColumns << endl;
	cout << left << setw(40) << "The number of columns" << setw(5) << numOfRows << endl;
	cout << left << setw(40) << "The number of unique classes" << setw(5) << uniClaNum << endl;
	cout << "\n\n\n" << endl;
}