/*
 * Credit.h
 * 
 * David Alejandro Martinez Tristan
 * 23/4/2019
 */

#ifndef CREDIT_H
#define CREDIT_H
#include <iostream>
#include "Account.h"

using namespace std;

class Credit : public Account
{
	private:
		double interest, creditLimit;
		int tripPoints;
	public:
		Credit();
		Credit(double, double, int, int, double, string);
		double getInterest();
		double getCreditLimit();
		int getTripPoints();
		void setInterest(double);
		void setCreditLimit(double);
		void setTripPoints(int);
		void toString();
		double applyInterest();
		double incrementCreditLimit(double);
		double deposit(double);
		bool withdraw(double);
};

Credit::Credit()
{
	interest = 0.0;
	creditLimit = 0.0;
	tripPoints = 0;
	type = 'c';
}

Credit::Credit(double interest, double creditLimit, int tripPoints, int accountNum, double balance, string owner)
: Account(accountNum, balance, owner)
{
	this->interest = interest;
	this->creditLimit = creditLimit;
	this->tripPoints = tripPoints;
	type = 'c';
}

double Credit::getInterest()
{
	return interest;
}

double Credit::getCreditLimit()
{
	return creditLimit;
}

int Credit::getTripPoints()
{
	return tripPoints;
}

void Credit::setInterest(double interest)
{
	this->interest = interest;
}

void Credit::setCreditLimit(double creditLimit)
{
	this->creditLimit = creditLimit;
}

void Credit::setTripPoints(int tripPoints)
{
	this->tripPoints = tripPoints;
}

void Credit::toString()
{
	cout << "Type: Credit" << endl;
	cout << "Owner: " << owner << endl;
	cout << "Balance: " << balance << endl;
	cout << "Interest: " << interest << "%" << endl;
	cout << "Credit limit: " << creditLimit << endl;
	cout << "Trip points: " << tripPoints << endl;
}

double Credit::applyInterest()
{
	balance = (balance * interest / 100.0) + (12 * creditLimit * interest / 100.0);
	return balance;
}

double Credit::incrementCreditLimit(double increment)
{
	creditLimit += increment;
	balance -= 1000;
	return creditLimit;
}

double Credit::deposit(double amount)
{
	balance -= amount;
	return balance;
}

bool Credit::withdraw(double amount)
{
	if (balance + amount > creditLimit)
		return false;

	balance += amount;
	return true;
}
#endif