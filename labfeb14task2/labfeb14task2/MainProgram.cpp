
#include <iostream>
#include <string>
#include "personType.h"
using namespace std;

int main()
{
	string fstr;
	string lstr;
	string firstName = "Bob";
	string lastName = "Barker";
	bool result = false;
	personType student("Moaath", "Alrajab");
	// email him to figure out what he means by test name against value. within a member function 
	// or does he mean in the main
	
	//result = student.testName("Moaath", "Alrajab");

	

	do {
		cout << "Enter a first and a last name seperated by one space";
		cin >> fstr;
		cin.get();
		cin >> lstr;

	} while (lstr == "");
	
	result = student.testName(fstr, lstr);
	if (result)
	{
		cout << "it is the same name" << endl;
	}

	student.print();
	cout << endl;

	system("pause");
	return 0;
}