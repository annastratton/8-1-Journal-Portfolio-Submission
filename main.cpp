//main.cpp
#include <string>
#include <cctype>
#include "InterestPlan.h"
using namespace std;
//Used in functions main and dataInput.
bool continueLoop(string prompt);
//Takes input, performs checks
void dataInput(InterestPlan* plan);
int main() {
	cout << "Welcome to the Airgead Banking App" << endl;
	cout << endl;
	system("pause"); //halts program until user pushes any key
	cout << endl;
	InterestPlan* plan = new InterestPlan;
	bool keepGoing = true;
	while (keepGoing) {
		dataInput(plan);
		plan->ShowHeader1(); //Header for when monthly deposits are counted
		plan->CalculateInterest();
		plan->ShowResult();
		plan->SetDeposit(0); //Sets monthly deposit in the InterestPlan object, plan, to 0
			plan->ShowHeader2(); //Header for when monthly deposits are not counted
			plan->CalculateInterest();
		plan->ShowResult();
		keepGoing = continueLoop("Exit? (y for yes) ");
	}
	return 0;
}
bool continueLoop(string prompt) {
	bool keepGoing = true;
	string user_continue;
	cout << prompt;
	cin >> user_continue;
	if (tolower(user_continue.at(0)) == 'y') {
		keepGoing = false;
	}
	cout << endl;
	return keepGoing;
}
void dataInput(InterestPlan* plan) {
	int numYears;
	double annualInterest;
	double startingAmount;
	double deposit;
	bool keepGoing = true;
	string user_continue;
	while (keepGoing) {
		try {
			cout << "Initial Investment Amount: " << flush;
			cin >> startingAmount;
			if (startingAmount < 0) {
				throw runtime_error("Starting Amount must greater than 0.");
			}
			cout << "Monthly Deposit: " << flush;
			cin >> deposit;
			if (deposit < 0) {
				throw runtime_error("Monthly Deposit must be greater than 0");
			}
			cout << "Annual Interest (%): " << flush;
			cin >> annualInterest;
			if (annualInterest < 0) {
				throw runtime_error("Annual Interest must be greater than 0");
			}
			cout << "Number of years: " << flush;
			cin >> numYears;
			if (numYears < 1) {
				throw runtime_error("Number of Years must be 1 or greater.");
			}
			keepGoing = continueLoop("Continue? (y for yes) ");
		}
		catch (runtime_error& error) {
			cout << "ERROR: " << error.what() << endl;
			cout << endl;
		}
	}
	//Setting up the fields of IntterestPlan object, plan, using a pointer
	plan->SetData(numYears, annualInterest, startingAmount, deposit);
}
