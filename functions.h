#pragma once

double getPrinciple();
double getInterestRate();
bool getLoanType();
int getTermLength();
double getMonthlyPayment(double principle, double interestRate, bool loanType, int termLength);
