/*
 * Savings.h
 * 
 * David Alejandro Martinez Tristan
 * 23/4/2019
 */

#ifndef SAVINGS_H
#define SAVINGS_H
#include <iostream>
#include "Account.h"

using namespace std;

class Savings : public Account
{
	private:
		int growthRate;
		double annualPayment;
	public:
		Savings();
		Savings(int, double, int, double, string);
		int getGrowthRate();
		double getAnnualPayment();
		void setGrowthRate(int);
		void setAnnualPayment(double);
		void toString();
		double deposit(double);
		bool withdraw(double);
		double applyGrowthRate();
};

Savings::Savings()
{
	growthRate = 0;
	annualPayment = 0.0;
	type = 's';
}

Savings::Savings(int growthRate, double annualPayment, int accountNum, double balance, string owner)
: Account(accountNum, balance, owner)
{
	this->growthRate = growthRate;
	this->annualPayment = annualPayment;
	type = 's';
}

int Savings::getGrowthRate()
{
	return growthRate;
}

double Savings::getAnnualPayment()
{
	return annualPayment;
}

void Savings::setGrowthRate(int growthRate)
{
	this->growthRate = growthRate;
}

void Savings::setAnnualPayment(double annualPayment)
{
	this->annualPayment = annualPayment;
}

void Savings::toString()
{
	cout << "Type: Savings" << endl;
	cout << "Owner: " << owner << endl;
	cout << "Balance: " << balance << endl;
	cout << "Growth rate: " << growthRate << endl;
	cout << "Annual payment: " << annualPayment << endl;
}

double Savings::deposit(double amount)
{
	balance += amount;
	return balance;
}

bool Savings::withdraw(double amount)
{
	if (balance - amount < 0)
		return false;

	balance -= amount;
	return true;
}

double Savings::applyGrowthRate()
{
	balance += balance * growthRate / 100.0;
	return balance;
}

#endif