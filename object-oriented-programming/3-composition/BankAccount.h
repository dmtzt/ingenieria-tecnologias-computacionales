/* 
 * BankAccount.h
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 21/02/2019
*/
#include <iostream>
#include "Person.h"
#ifndef BANKACCOUNT_H
#define BANKACCOUNT_H

using namespace std;

class BankAccount
{
    private:
        Person user;
        double balance;
        int id;
    public:
        BankAccount(Person, double, int);
        BankAccount(Person, int);
        void setUser(Person);
        void setBalance(double);
        void setId(string);
        Person getUser();
        double getBalance();
        int getId();
        void toString();
        double deposit(double);
        bool withdraw(double);
};

BankAccount::BankAccount(Person user, double balance, int id)
{
    this->user = user;
    this->balance = balance;
    this->id = id;
    balance = 0;
}

BankAccount::BankAccount(Person user, int id)
{
    this->user = user;
    this->id = id;
    balance = 0;
}

void BankAccount::setUser(Person user)
{
    this->user = user;
}
        
void BankAccount::setBalance(double)
{
    this->balance = balance;
}

void BankAccount::setId(string)
{
    this->id = id;
}

Person BankAccount::getUser()
{
    return user;
}

double BankAccount::getBalance()
{
    return balance;
}

int BankAccount::getId()
{
    return id;
}

void BankAccount::toString()
{
    user.toString();
    cout << balance << endl;
    cout << id << endl;
}

double BankAccount::deposit(double amount)
{
    if (amount > 0)
        balance += amount;

    return balance;
}

bool BankAccount::withdraw(double amount)
{
    if (balance - amount < 0)
        return false;
    else
        balance -= amount;
    
    return true;
}
#endif