/* 
 * bankAccount.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 21/02/2019
*/

#include <iostream>
#include "BankAccount.h"
#include "Person.h"

using namespace std;

int main(void)
{
    string fullName, address, phoneNum;
    int age;

    cout << "Please provide user full name: ";
    getline(cin, fullName);

    cout << "Please provide user address: ";
    getline(cin, address);

    cout << "Please provide user phoneNum: ";
    getline(cin, phoneNum);

    cout << "Please provide user age: ";
    cin >> age;

    Person person(fullName, address, phoneNum, age);

    BankAccount account(Person, 267);

    account.toString();
}