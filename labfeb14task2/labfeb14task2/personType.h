#pragma once

#include <string> 
using namespace std;

class personType
{
public:
	void print() const;
	void setName(string first, string last);
	void setNameTest(string first, string last);
	bool testName(string firstT, string lastT);
	bool testName();
	void setNameFir(string first);
	void setNameLas(string last);
	void setNameMid(string middle);
	void setNameFirt(string firstT);
	void setNamelasT(string lastT);
	string getFirstName() const;
	string getLastName() const;
	string getFirstNameT() const;
	string getLastNameT() const;
	personType(string first = "", string last = "");
private:
	string firstName;
	string lastName;
	string middleName;
	string firstNameT;
	string lastNameT;
	bool result = false;
};
