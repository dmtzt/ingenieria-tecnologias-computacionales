/* 
 * accounts.cpp
 *
 * David Alejandro Martinez Tristan
 * 23/04/2019
*/

#include <cctype>
#include <iostream>
#include <vector>
#include "Credit.h"
#include "Savings.h"
#define EXIT 0
#define ADD_ACCOUNT 1
#define VIEW_INFO 2
#define APPLY_INTEREST_GROWTH_RATE 3
#define INCREMENT_CREDIT_LIMIT 4
#define DEPOSIT 5
#define WITHDRAW 6
#define CREDIT 'c'
#define SAVINGS 's'
using namespace std;

int main(void)
{
    int option, tripPoints, num, growthRate;
    int countAccount = 0;

    double balance, interest, creditLimit, annualPayment, amount;

    char type;

    bool found;

    string owner;

    vector<Account*> accounts;

    cout << "Welcome to the Rotschild Bank" << endl;
    do
    {
        cout << "-----------------------------" << endl;
        cout << "1) Add account" << endl;
        cout << "2) View info" << endl;
        cout << "3) Apply interest/growth rate" << endl;
        cout << "4) Increment credit limit" << endl;
        cout << "5) Deposit" << endl;
        cout << "6) Withdraw" << endl;
        cout << "Please choose an option: ";
        cin >> option;

        found = false;
        switch (option)
        {
            case ADD_ACCOUNT:
                Account* account;

                cout << "Credit (c) or savings (s) account: ";
                cin >> type;
                if (type != CREDIT && type != SAVINGS)
                {
                    cout << "Invalid option" << endl;
                    break;
                }
                cout << "Account number: ";
                cin >> num;
                cout << "Owner: ";
                cin >> owner;
                cout << "Balance: ";
                cin >> balance;
                type = tolower(type);

                if (type == CREDIT)
                {
                    cout << "Interest: ";
                    cin >> interest;
                    cout << "CreditLimit: ";
                    cin >> creditLimit;
                    cout << "Trip points: ";
                    cin >> tripPoints;

                    account = new Credit(interest, creditLimit, tripPoints, num, balance, owner);
                    accounts.push_back(account);

                    cout << "Credit account succesfully added" << endl;
                    countAccount++;
                }
                else if (type == SAVINGS)
                {
                    cout << "Growth rate: ";
                    cin >> growthRate;
                    cout << "Annual payment: ";
                    cin >> annualPayment;

                    account = new Savings(growthRate, annualPayment, num, balance, owner);
                    accounts.push_back(account);

                    cout << "Savings account succesfully added" << endl;
                    countAccount++;
                }
                break;
            case VIEW_INFO:
                cout << "Account number: ";
                cin >> num;

                for (unsigned int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i]->getAccountNum() == num)
                    {
                        accounts[i]->toString();
                        found = true;
                    }
                }

                if (!found)
                    cout << "Account does not exist" << endl;
                break;
            case APPLY_INTEREST_GROWTH_RATE:
                cout << "Account number: ";
                cin >> num;

                for (unsigned int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i]->getAccountNum() == num)
                    {
                        if (accounts[i]->getType() == CREDIT)
                        {
                            Credit* credit = (Credit*) accounts[i];
                            credit->applyInterest();
                            cout << "Interest applied" << endl;
                        }
                        else if (accounts[i]->getType() == SAVINGS)
                        {
                            Savings* savings = (Savings*) accounts[i];
                            savings->applyGrowthRate();
                            cout << "Growth rate applied" << endl;
                        }
                    }
                    found = true;
                }

                if (!found)
                    cout << "Account does not exist" << endl;

                cout << endl;
                break;
            case INCREMENT_CREDIT_LIMIT:
                cout << "Account number: ";
                cin >> num;

                for (unsigned int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i]->getAccountNum() == num)
                    {
                        if (accounts[i]->getType() == CREDIT)
                        {
                            cout << "Amount to increment: " << endl;
                            cin >> amount;

                            Credit* credit = (Credit*) accounts[i];
                            credit->incrementCreditLimit(amount);
                            cout << "Credit limit incremented" << endl;
                        }
                        else
                            cout << "Account is not a credit account" << endl;        

                        found = true;
                    }
                }

                if (!found)
                    cout << "Account was not found" << endl;
                break;
            case DEPOSIT:
                cout << "Account number: ";
                cin >> num;
                cout << "Amount: ";
                cin >> amount;

                for (unsigned int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i]->getAccountNum() == num)
                    {
                        accounts[i]->deposit(amount);
                        cout << "Deposit executed" << endl;
                        found = true;
                    }

                    if (!found)
                        cout << "Account was not found" << endl;  
                }
                break;
            case WITHDRAW:
                cout << "Account number: ";
                cin >> num;
                cout << "Amount: ";
                cin >> amount;

                for (unsigned int i = 0; i < accounts.size(); i++)
                {
                    if (accounts[i]->getAccountNum() == num)
                    {
                        if (accounts[i]->withdraw(amount))
                            cout << amount << " have been withdrawn" << endl;
                        else
                            cout << "Fail: the amount exceeds the available cash" << endl;
                        found = true;
                    }
                }
                if (!found)
                    cout << "Account not found" << endl;
                break;
            default:
                cout << "Please choose a valid option" << endl << endl;
                break;
        }
    } while (option != EXIT);
    
    return 0;
}