#include <iostream>
#include <iomanip>
#include "functions.h"

int main() 
{
	double principle{ getPrinciple() };
	int interestRate{ getInterestRate() };
	int termLength{ getTermLength() };
	bool loanType{ getLoanType() };
	double monthlyPayment{ getMonthlyPayment(principle, interestRate, loanType, termLength) };

	std::string loanTypeOut{ (loanType) ? "amortizing" : "balloon" };

	if (loanTypeOut == "amortizing")
	{
		std::cout << "Monthly payment for an " << loanTypeOut << " loan is $" << std::fixed << std::setprecision(2) << monthlyPayment << '\n';
	}
	else 
	{
		std::cout << "Monthly payment for a " << loanTypeOut << " loan is $" << std::fixed << std::setprecision(2) << monthlyPayment << '\n';
	}

	return 0;
	
}