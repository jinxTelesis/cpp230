#pragma once
class PayRoll
{
private:
	double employeePayH; // private data members 
	double hoursWeek;
	double taxRate;
	double payBTax;
	double payAfTax;
public:
	PayRoll();
	~PayRoll();

	void setEmployeePayH(double PayH); // sets pay rate
	void setHoursWeek(double hWork); // sets hours per week
	void setTaxRate(double taxRate); // not used but you could set another tax rate
	void calPayBeforeT(); // not used number might be wanted
	void calPayAfterT();

	double getEmployeePayH();
	double getHoursWeek();
	double getTaxRate();
	double getBTax(); // intentional only getter
	double getAfTax(); // intentional only getter

};

