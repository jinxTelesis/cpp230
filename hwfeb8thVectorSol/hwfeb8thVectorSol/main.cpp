#include <iostream>
#include <string>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <vector> 
#include <iterator> 
#include <algorithm> 


using namespace std;
// write a function for printing so you have one function
void printVector(vector<string> &printvec);


int main()
{

	int vectorRowSize = 9; // avoid hard code
	int numOfColumns; // stores number of columns
	char delimiter = ','; // stores delimiter to avoid hard code

	vector<string> rowData; // stores row data internal processing and expasion of results
	vector<string> storeClasses; // stores class data internal processing and expansion of results

	string fileLocation("C:\\Users\\dremo\\OneDrive\\Desktop\\IRIS.csv"); // file locations
	ifstream inputfile(fileLocation);

	istream_iterator<string> start(inputfile), end; // makes a string stream iterator for file
	vector<string> strVec(start, end); // reads file into vector

	vector<string>::iterator it2; // second iterator to finding specific values
	it2 = strVec.begin();
	string firstRow = *it2; // realize you can just derefence without saving to string
	cout << "first line **********\n\n";
	cout << firstRow << endl;
	numOfColumns = count(firstRow.begin(), firstRow.end(), delimiter); // find number of columns by count with delimiter value
	cout << "first line **********\n\n";

	cout << "number of columns is " << numOfColumns + 1 << endl;

	for (vector<string>::iterator it = strVec.begin(); it != strVec.end(); ++it) // breaks up delimted data
	{
		istringstream split(*it);
		string temp;
		for (int index = 0; index < vectorRowSize; index++)// iterates over row, prob should change from hard code
		{
			getline(split, temp, delimiter);
			rowData.push_back(temp); // pushing into another vector after split for the row data
		}

	}

	cout << "there is " << strVec.size() << "lines in this file" << endl;

	for (vector<string>::iterator it = rowData.begin(); it != rowData.end(); ++it) // filters out just classes make function
	{
		//cout << *it << endl;
		string temp;
		temp = *it;
		if (isalpha(temp[0])) // need subscript because it checks char not string // is way to convert strings to chars being lazy
		{
			storeClasses.push_back(temp);
		}
	}

	sort(storeClasses.begin(), storeClasses.end()); // sorts values so unique works properly 
	vector<string>::iterator lastit = unique(storeClasses.begin(), storeClasses.end()); // unique removes second copy of any value
	storeClasses.erase(lastit, storeClasses.end()); // erases undefined values left in vector
	cout << "the number of  unique classes is " << storeClasses.size() << endl;
	cout << "the unique class values are \n";
	printVector(storeClasses);
	cout << "\n";


	inputfile.close();
	system("pause");
	return 0;
}

void printVector(vector<string> &printvec)
{

	for (vector<string>::iterator it = printvec.begin(); it != printvec.end(); ++it) // iterates over vector to print output
	{
		cout << *it << " ";
	}
	cout << endl;
}