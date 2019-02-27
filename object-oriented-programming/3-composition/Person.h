/* 
 * Person.h
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 21/02/2019
*/
#include <iostream>
#ifndef PERSON_H
#define PERSON_H

using namespace std;

class Person
{
    private:
        string fullName, address, phoneNum;
        int age;
    public:
        Person();
        Person(string, string, string, int);
        void setFullName(string);
        void setAddress(string);
        void setPhoneNum(string);
        void setAge(int);
        string getFullName();
        string getAddress();
        string getPhoneNum();
        int getAge();
        void toString();
};

Person::Person()
{
    fullName = "N/A";
    address = "N/A";
    phoneNum = "N/A";
    age = -1;
}

Person::Person(string fullName, string address, string phoneNum, int age)
{
    this->fullName = fullName;
    this->address = address;
    this->phoneNum = phoneNum;
    this->age = age;
}

void Person::setFullName(string fullName)
{
    this->fullName = fullName;
}
        
void Person::setAddress(string)
{
    this->address = address;
}

void Person::setPhoneNum(string)
{
    this->phoneNum = phoneNum;
}

void Person::setAge(int)
{
    this->age = age;
}

string Person::getFullName()
{
    return fullName;
}

string Person::getAddress()
{
    return address;
}

string Person::getPhoneNum()
{
    return phoneNum;
}

int Person::getAge()
{
    return age;
}

void Person::toString()
{
    cout << fullName << endl;
    cout << address << endl;
    cout << phoneNum << endl;
    cout << age << endl;
}
#endif