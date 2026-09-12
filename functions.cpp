#include <iostream>
#include <cmath>
#include <iomanip>

double getPrinciple() 
{
	double principle{};

	while (true) 
	{
		std::cout << "Enter principle: ";
		if (std::cin >> principle)	// Verifying Input so user doesnt accidently enter in a string
		{
			return principle;	// Returning Principle for calculations in the dedicated functions in functions.cpp
		}

		std::cout << "Invalid input, ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

int getInterestRate() 
{
	double interestRate{};
	while (true) 
	{
		std::cout << "Enter interest rate: ";
		if (std::cin >> interestRate)	// Verifying Input so user doesnt accidently enter in a string
		{
			return interestRate;	// Returning the raw interest rate percentage without a decimal for percise calculations in the dedicated function in functions.cpp
		}

		std::cout << "Invalid input, ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

bool getLoanType() 
{
	std::cout << "Enter loan type amortizing (a) or balloon (b): ";
	std::string answer{};
	std::cin >> answer;

	while (answer != "a" && answer != "b") // Verifying Input to make sure the user only enters in 'a' for amortizing or 'b' for balloon
	{
		std::cout << "Invalid input, try again: ";
		std::cin >> answer;
	}

	if (answer == "a") 
	{
		return true;	// Returning true for calculations of the amortizing loan
	}
	else 
	{
		return false;	// Returning false for calculations of the balloon loan
	}
}

int getTermLength() 
{
	double years{};
	
	while (true) 
	{
		std::cout << "Enter the term of the loan in years: ";

		if (std::cin >> years)	// Verifying Input so user doesnt accidently enter in a string
		{
			return years;	// Returning the duration of the loan in years
		}

		std::cout << "Invalid input, ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
}

double getMonthlyPayment(double principle, int interestRate, bool loanType, int termLength) 
{

	int P = principle;
	double r = interestRate / 12000.0; // Dividing by 100 to get the yearly percentage rate then dividing again by 12 to get the monthly rate
	int n = termLength * 12;

	if (loanType == true) 
	{
		double M = P * ((r * pow((1 + r), n)) / (pow((1 + r), n) - 1));
		return M;
	}
	else
	{
		double M = (P * (r));
		return M;
	}
}
