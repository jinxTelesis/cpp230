//Implementation file

#include <iostream> 
#include <string>
#include "personType.h"

using namespace std;

void personType::print() const {
	cout << firstName << " " << lastName;
}

void personType::setName(string first, string last) {
	firstName = first;
	lastName = last;
}

void personType::setNameTest(string first, string last)
{
	firstNameT = first;
	lastNameT = last;
}

bool personType::testName(string firstT, string lastT)
{
	result = false;
	if (firstT.find(firstName) != string::npos)
	{
		if (lastT.find(lastName) != string::npos)
			result = true;
	}
	return result;
}

bool personType::testName()
{
	result = false;

	if (firstNameT == "")
	{
		cout << "No first name to test" << endl;
	}

	if (lastNameT == "")
	{
		cout << "No last name to test" << endl;
	}

	if (firstNameT.find(firstName) != string::npos)
	{
		if (lastNameT.find(lastName) != string::npos)
			result = true;
	}
	return result;

	
}

void personType::setNameFir(string first) {
	firstName = first;
}

void personType::setNameLas(string last)
{
	lastName = last;
}

void personType::setNameMid(string middle)
{
	middleName = middle;
}

string personType::getFirstName() const {
	return firstName;
}

string personType::getLastName() const {
	return lastName;
}

string personType::getFirstNameT() const {
	return firstNameT;
}

string personType::getLastNameT() const {
	return lastNameT;
}

void personType::setNameFirt(string firstT) {
	string firstNameT = firstT;
}

void personType::setNamelasT(string lastT)
{
	string lastNameT = lastT;
}

//constructor 
personType::personType(string first, string last) {
	firstName = first;
	lastName = last;
}