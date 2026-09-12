#pragma once

double getPrinciple();
int getInterestRate();
bool getLoanType();
int getTermLength();
double getMonthlyPayment(double principle, int interestRate, bool loanType, int termLength);
void outputAmortizationTable(double principle, int interestRate, int termLength, bool loanType, double monthlyPayment);
