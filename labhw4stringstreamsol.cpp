#include <string>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <sstream>
#include <vector>
#include <algorithm>
#include <stdio.h> 

using namespace std;

void classTester(char array[], int size); // saves a bunch of memory because flags // vars go out of scope

int main() {

	const int BUF_SIZE = 15000; // no clue how big the file will be, could buffer it in smaller chunks
	string fileLocation = "C:\\Users\\dremo\\OneDrive\\Desktop\\IRIS.csv"; // makes it easier to replace
	ifstream excelFile(fileLocation);
	stringstream ss();
	string oneLine;
	string storeClaVal;
	int columncounter = 0;
	char strssbuffer[BUFSIZ];
	int lineCount = 0;
	int colCount = 0;


	excelFile >> oneLine; //
	colCount = count(oneLine.begin(), oneLine.end(), ','); // this dynamically gets number of columns will work if file size changes
	excelFile.close(); // closes file so it's not missing that one line
	excelFile.clear(); // clears file to repopen
	excelFile.open(fileLocation); // reopens so we can get that one line


	while (!excelFile.eof()) // runs till eof reached
	{
		excelFile.getline(strssbuffer, BUFSIZ, ','); // buffers each value in by delimter if files needed to be extracted by value
		cout << strssbuffer << endl; // displays that the file is being read
		lineCount++; // increments for every value in the buffer
	}
	lineCount = lineCount / colCount; // needs to be divided by the number of columns because it increments per value no per line

	cout << lineCount << endl;
	
	classTester(strssbuffer, BUFSIZ); // passes in the buffer for testing of class values, not truely dynamic needs classes defined
	// vector soltion is truely dynamic it can get proper results without the classes being defined.
	// could be solved with buffer if last columns values extracted and a lexigraphic values were compared and counted for new uniques
	system("pause");

	return 0;
}

void classTester(char array[], int size) // takes in buffer of chars and compared c-string function to the character value of class
{
	bool flag1 = false;// flags needed to it doesn't just increment up multiple values
	bool flag2 = false;
	bool flag3 = false;
	int sumClassesFound = 0;
	char * temp1; // needed to work with strstr, don't think you can test a normal string against an array of chars

	temp1 = strstr(array, "setosa");
	if (temp1) {
		flag1 = true;
	}

	temp1 = strstr(array, "virginica");
	if (temp1) {
		flag2 = true;
	}

	temp1 = strstr(array, "versicolor");
	if (temp1) {
		flag3 = true;
	}

	if (flag1 = true) {
		cout << "found setosa " << endl;
		sumClassesFound++;
	}

	if (flag2 = true) {
		cout << "found virginica" << endl;
		sumClassesFound++;
	}

	if (flag3 = true) { // if class values that didn't exist were tested it will not increment those up // demonstrated in the string solution
		cout << "found versicolor" << endl;
		sumClassesFound++;
	}

	cout << "Total number of classes found " << sumClassesFound << endl;
}