#include <iostream>
#include <cmath>

double getPrinciple() 
{
	double principle{};

	while (true) 
	{
		std::cout << "Enter principle: ";
		if (std::cin >> principle) 
		{
			return principle;
		}

		std::cout << "Invalid input, ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
}

double getInterestRate() 
{
	double interestRate{};
	while (true) 
	{
		std::cout << "Enter interest rate: ";
		if (std::cin >> interestRate) 
		{
			return interestRate /= 100;
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

	while (answer != "a" && answer != "b") 
	{
		std::cout << "Invalid input, try again: ";
		std::cin >> answer;
	}

	if (answer == "a") 
	{
		return true;
	}
	else 
	{
		return false;
	}
}

int getTermLength() 
{
	double years{};
	
	while (true) 
	{
		std::cout << "Enter the term of the loan in years: ";

		if (std::cin >> years) 
		{
			return years;
		}

		std::cout << "Invalid input, ";
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}
	
	
}

double getMonthlyPayment(double principle, double interestRate, bool loanType, int termLength) 
{

	int P = principle;
	int r = interestRate / 12;
	int n = termLength * 12;

	if (loanType = true) 
	{
		double M = ((r * pow((1 + r), n)) / (pow((1 + r), n) - 1));
		return M;
	}
	else
	{
		double M = (P * (r));
		return M;
	}
}
