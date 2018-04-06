#include <iostream>
#include <string>
#include <time.h> 
#include <vector>
#include <stdexcept>
#include <algorithm>

using namespace std;
// ** change this to 1 to change to verbose mode to see internals
int argc = 0;  // ** change this to 1 to change to verbose mode to see internals
char *argv; 
			// global as a fake argc wanted to access real one prior to main not from command line
class Apriori {// this is why i was asking about system(" enter here ");

public:
	Apriori()
	{
		if (::argc == 1) // just example not real implementation
		{
			// *** change this to zero to shut off verbose *** verbose also lets you cheat
			cout << " alternative to passing command line args " << endl;
			::argc = 1; // this is why i was asking about system(" enter here ");
		}
		
		
		// list of settings bundled would go here rather than setting each arg
		// wanted to access the command line list 
	}
};

Apriori one; // could be a list of statics to preset conditions 
			  


int main(int argc, char *argv[]) {
	if (::argc == 1)
	{
		cout << "Verbose mode activated " << endl;
	}
	time_t timeNow;
	time_t* Ptime = &timeNow;
	// i wrote everything above this but not between the comments the source was cplusplus.com
	if (::argc == 1) // added this to make sure i actually properly seeded random without heavy research
	{
		struct tm y2k = { 0 };
		double seconds;

		y2k.tm_hour = 0;   y2k.tm_min = 0; y2k.tm_sec = 0;
		y2k.tm_year = 100; y2k.tm_mon = 0; y2k.tm_mday = 1;

		time(Ptime);  /* get current time; same as: timer = time(NULL)  */

		seconds = difftime(*Ptime, mktime(&y2k));

		printf("%.f seconds since January 1, 2000 in the current timezone", seconds);
	}

	
	// i wrote everything below these comments 
	int ranNumSize =7; // needed to avoid infant loops because vectors size is changing in loops could just store starting size
	int ranInt = 0;
	int tempUin = 0;
	int incTruth = 0;
	string inputStr = ""; // used to prevent invalid character input
	vector<int> ranNumVec(0); // for generated nums
	vector<int> userIntVec(0); // for user nums
	vector<int> winNumVec(0); // extra display copy
	srand(time(Ptime)); // seed hope this is correct

	cout << "Welcome professor Moaath to Andre's lottery program " << endl;
	cout << "Please enter 7 integers between 1-20" << endl;

	for (int index = 0; index < ranNumSize; index++) // used fixed rather than size 
	{	
		ranInt = 0;// will be infinate loop otherwise with push
		ranInt = (rand() % 20) + 1; // generates 1-20 values
		ranNumVec.push_back(ranInt); // puts values in the vector
	}


	if (::argc == 1) // displays only in verbose mode
	{
		for (int index = 0; index < ranNumVec.size(); index++)
			cout << "this is number " << (index+1) << " " << ranNumVec[index] << "\n";
	}
	cout << endl;

	std::sort(ranNumVec.begin(), ranNumVec.end());
	winNumVec = ranNumVec;

	if (::argc == 1) // displays only in verbose mode
	{
		for (int index = 0; index < ranNumVec.size(); index++)
			cout << "this is number after sorting " << (index + 1) << " " << ranNumVec[index] << "\n";
	}
	cout << endl;
	
	rewind: // rewind point, bad form i know
	rewind2: // second rewind point for invalid input


	for (int index = 0; index < ranNumSize; index++) // input validation loop
	{
		try {
			cin >> inputStr; // str catches invalid characters and rewinds
			try {
				tempUin = stoi(inputStr);
			}
			catch (invalid_argument& exception)
			{
				cout << " invalid character please reenter numbers between 1-20 as integers " << endl;
				userIntVec.clear(); // this is the primative clean up
				goto rewind2; // bad flow
			}
			
			if (tempUin < 1 || tempUin > 20) // int catches invalid input and rewinds
			{
				throw invalid_argument("program crashed due to out of bounds numbers"); // this never gets out as is
			}
		}
		catch (invalid_argument& exception)
		{
			cout << " invalid numbers please reenter numbers between 1-20 as integers" << endl;
			userIntVec.clear(); // clean up could just let them enter last also
			goto rewind;
		}
		userIntVec.push_back(tempUin); // puts the number in only if all this validation passed
	}

	if (::argc == 1) // output for verbose mode only
	{
		for (int index = 0; index < userIntVec.size(); index++)
			cout << " this is the players input " << (index + 1) << " " << userIntVec[index] << "\n";
	}
	cout << endl;
	int temp1;
	int temp2;

	for (int index = 0; index < ranNumSize; index++)
	{
		
		temp1 = userIntVec.back(); // 100 ways this could be done pop off the last and test as ints 
		userIntVec.pop_back();
		temp2 = ranNumVec.back();
		ranNumVec.pop_back();

		if (temp1 == temp2) // this increments a counter up each time the numbers are equal
		{
			incTruth++;
		}

		if (::argc == 1)
		{
			cout << "this is the increment truth value " <<  incTruth << endl;
		}
	}


	if (incTruth == 7) // if all 7 conditions were true than it displays congratulation message 
	{
		cout << " Congrats you won the lottery!!!!" << endl;
		cout << " you can collect 1 centavos (1/100 of a paso) from Andre" << endl;
	}
	else
	{
		cout << " Better luck next time!" << endl;
		cout << " the winning numbers were" << endl;
		for (int index = 0; index < ranNumSize; index++)
		{
			cout << winNumVec[index] << endl;
		}

	}

	system("pause");
	return 0;
}
