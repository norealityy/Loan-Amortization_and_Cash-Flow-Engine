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
		std::cout << "Enter interest rate without decimal points (e.g enter 75 instead of 7.5%): ";
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
	int years{};
	
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
	double r = interestRate / 12000.0;	// Dividing by 100 to get the yearly percentage rate then dividing again by 12 to get the monthly rate
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

void outputAmortizationTable(double principle, int interestRate, int termLength, bool loanType, double monthlyPayment)
{
	double balance = principle;
	double monthlyRate = interestRate / 12000.0;	// Dividing by 100 to get the yearly percentage rate then dividing again by 12 to get the monthly rate
	int totalPayments = termLength * 12;	// Getting the amount of payments total in the amortization table
	
	std::cout << std::fixed << std::setprecision(2);
	std::cout << std::left << std::setw(10) << "Month" << std::setw(15) << "Payment" << std::setw(15) << "Principle" << std::setw(15) << "Interest" << std::setw(15) << "Balance" << '\n';
	std::cout << std::string(70, '-') << '\n';

	for (int i = 1; i < (totalPayments + 1); i++)
	{
		double interest = balance * monthlyRate;
		double principlePaid = monthlyPayment - interest;

		if (i == totalPayments)
		{
			principlePaid = balance;
			monthlyPayment = principlePaid + interest;
			balance = 0.0;
		}
		else
		{
			balance -= principlePaid;
		}

		std::cout << std::left << std::setw(10) << i
			<< "$" << std::setw(13) << monthlyPayment
			<< "$" << std::setw(13) << principlePaid
			<< "$" << std::setw(13) << interest
			<< "$" << std::setw(13) << balance << '\n';
	}


}
