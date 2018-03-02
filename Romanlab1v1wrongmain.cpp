#include <iostream>
#include <string>
#include "RomanType.h"

using namespace std;


void main() {

	string teststr = "CLIX";

	RomanType rom1;
	rom1.setRoman(teststr); 
	rom1.romanToPostiveinteger();
	rom1.printRoman();
	rom1.printPositiveinteger(); 
	
	

	system("pause");
}
