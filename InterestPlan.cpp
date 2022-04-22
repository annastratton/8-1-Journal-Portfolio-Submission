//InterestPlan.cpp
#include "InterestPlan.h"
void InterestPlan::SetData(int numYears, double annualInterest, double startingAmount,
	double deposit) {
	this->numYears = numYears;
	this->annualInterest = annualInterest;
	this->startingAmount = startingAmount;
	this->deposit = deposit;
}
void InterestPlan::SetDeposit(double deposit) {
	this->deposit = deposit;
}
void InterestPlan::CalculateInterest() {
	//variable decleration
	int currentMonth;
	int totalMonths;
	double interestAmount;
	double total;
	double monthlyInterest;
	double monthlyDeposit;
	//variable initialization
	currentMonth = 1; //1 is picked for better consistency in equations
	totalMonths = numYears * 12;
	total = startingAmount; //total is initially the starting amount
	interestAmount = 0;
	monthlyInterest = (annualInterest / 100) / 12;
	monthlyDeposit = deposit;
	interestList.clear(); //removes all elements from the vector
	sumList.clear();
	//loop iterates once for each month
	while (currentMonth <= totalMonths) {
		total += monthlyDeposit; //first we add total to the deposit
			interestAmount = total * monthlyInterest; //calculate interest gained
		interestList.push_back(interestAmount); //save interest at the end of vector list, to be accessed later
			total += interestAmount; //add interest to total for a new total
			sumList.push_back(total); //save total to be accessed later
			currentMonth++;
		//continue to next month
	}
}
void InterestPlan::ShowHeader() {
	cout << setw(10) << left << "Year" << flush;
	cout << setw(20) << left << "Balance" << flush;
	cout << setw(10) << right << "Accumulated Interest" << endl;
}
void InterestPlan::ShowHeader1() {
	cout << "Balance and Interest with additional monthly deposits" << endl;
	this->ShowHeader();
}
void InterestPlan::ShowHeader2() {
	cout << "Balance and Interest without additional monthly deposits" << endl;
	this->ShowHeader();
}
//must be called after InterestPlan::CalculateInterest is called
void InterestPlan::ShowResult() {
	double interestSum = 0;
	for (int i = 1; i <= numYears; i++) {
		cout << setw(10) << left << i << flush;
		cout << setw(20) << left << sumList.at((i * 12) - 1) << flush;
		for (int j = (i - 1) * 12; j <= (i * 12) - 1; j++) {
			interestSum += interestList.at(j);
		}
		cout << setw(10) << left << interestSum << endl;
		cout << endl;
	}
}
