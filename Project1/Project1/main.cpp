#include <iostream>
#include <string>
#include <iomanip>

/* 
didn't comment as much because i felt like this program was 
close to normal standards for classes with nothing exceptional going on
*/

class Population 
{
private:
	int pop;
	double birthRate;
	double deathRate;
	int years;
public:

	Population() { // populate constructor
		pop = 2;
		years = 1;
	}
	void setPop(int pop) { if(pop > 1) this->pop = pop; } // setters checks if valid even though other validation in program
	void setbirthRate(double birthRate) { if(birthRate > 0) this->birthRate = birthRate; } // uses this constant pointer because id rather learn used convecntions
	void setdeathRate(double deathRate) { if(deathRate > 0) this->deathRate = deathRate; }
	void setYears(int years) { if(years > 1)this->years = years; }// uses this constant pointer because id rather learn used convecntions
	int getPop() { return this->pop; }
	double getbirthRate() { return this->birthRate; }
	double getdeathRate() { return this->deathRate; }
	double getyears() { return this->years; }

	void displayPop() { std::cout << pop; }
	void askUserPop() { std::cout << "Please Enter a integer 2 or over for Population :"; }
	void askUserBr() { std::cout << "Please Enter non negative birthrate :"; }
	void askUserDr() { std::cout << "Please enter a non negative deathrate :"; }
	void askUserYear() { std::cout << "Please enter a integer of 1 or more :"
			<< "\n" << "to determine the number of years the model should run for :";
	}
			
	
};

double calPopProject(int pop, double birthRate, double deathrate, int years); // function takes values because problems in function examples
void displayPopS(int pop);												// thought about just sending class objects into calPop
void displayPopE(double pop);

int main()
{
	int userInput = 0;
	double userIBr = 0.0; // for valadiation tests wanted seperate from class data
	double userIDr = 0.0;
	int userIYear = 0;
	double outputPop = 0;
	

	Population pop1;
	

	pop1.askUserPop();
	while (userInput < 2) { // condition 2 or greater for pop
		std::cin >> userInput;
	}
	pop1.setPop(userInput);

	pop1.askUserBr();
	while (userIBr < 0.00001) { // condition none negative
		std::cin >> userIBr;
	}
	pop1.setbirthRate(userIBr);
	

	pop1.askUserDr();
	while (userIDr < 0.00001) { // condition non negative
		std::cin >> userIDr;
	}
	pop1.setdeathRate(userIDr);
	

	pop1.askUserYear();
	while (userIYear < 1) { // condition over 1
		std::cin >> userIYear;
	}
	pop1.setYears(userIYear);
	
	

	displayPopS(pop1.getPop());
	outputPop = calPopProject(pop1.getPop(), pop1.getbirthRate(), pop1.getdeathRate(), pop1.getyears());// realize you can pass instance rather than vars
	displayPopE(outputPop); // the returns from calPopProject
	


	system("pause");
	return 0;
}

double calPopProject(int pop, double birthRate, double deathrate, int years)
{
	double newPop = pop;
	

	for (int index = 0; index < years; index++)
	{
		 newPop = newPop * ((1 + birthRate) * (1 - deathrate));
	}

	
	return newPop;
}

void displayPopS(int pop)
{

	std::cout << " the starting population is: " << pop << std::endl;

}

void displayPopE(double pop)
{
	std::cout << " the ending population is: " << std::fixed << pop << std::endl;
}