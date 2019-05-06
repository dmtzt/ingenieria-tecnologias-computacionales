/*
 * Account.h
 * 
 * David Alejandro Martinez Tristan
 * 23/4/2019
 */

#ifndef ACCOUNT_H
#define ACCOUNT_H
#include <iostream>

using namespace std;

class Account
{
	protected:
		int accountNum;
		double balance;
		char type;
		string owner;
	public:
		Account();
		Account(int, double, string);
		int getAccountNum();
		double getBalance();
		string getOwner();
		char getType();
		void setAccountNum(int);
		void setBalance(double);
		void setType(char);
		void setOwner(string);
		virtual void toString() = 0;
		virtual double deposit(double) = 0;
		virtual bool withdraw(double) = 0;
};

Account::Account()
{
	accountNum = 0;
	balance = 0.0;
	owner = "N/A";
	type = 's';
}

Account::Account(int accountNum, double balance, string owner)
{
	this->accountNum = accountNum;
	this->balance = balance;
	this->owner = owner;
	type = 's';
}

int Account::getAccountNum()
{
	return accountNum;
}

double Account::getBalance()
{
	return balance;
}

char Account::getType()
{
	return type;
}

string Account::getOwner()
{
	return owner;
}

void Account::setAccountNum(int accountNum)
{
	this->accountNum = accountNum;
}

void Account::setBalance(double balance)
{
	this->balance = balance;
}

void Account::setType(char type)
{
	this->type = type;
}

void Account::setOwner(string owner)
{
	this->owner = owner;
}
#endif