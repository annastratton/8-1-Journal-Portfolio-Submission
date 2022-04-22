//InterestPlan.h
#ifndef INTERESTPLAN_H
#define INTERESTPLAN_H
#include <vector>
#include <iostream>
#include <iomanip>
using namespace std;
class InterestPlan {
public:
	//Default constroctur is sufficient
	//setData
	void SetData(int, double, double, double);
	void SetDeposit(double);
	void CalculateInterest();
	void ShowHeader1();
	void ShowHeader2();
	void ShowResult();
private:
	void ShowHeader();
	int numYears = 0;
	double annualInterest = 0;
	double startingAmount = 0;
	double deposit = 0;
	vector<double> interestList;
	vector<double> sumList;
};
#endif
