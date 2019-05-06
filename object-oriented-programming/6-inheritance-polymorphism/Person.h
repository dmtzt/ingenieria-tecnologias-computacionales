/*
 * Person.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 1/4/2019
 */

#ifndef PERSON_H
#define PERSON_H
#include <iostream>

using namespace std;

class Person
{
	protected:
		string firstName, lastName;
		int age;
	public:
		Person();
		Person(string, string, int);
		string getFirstName();
		string getLastName();
		int getAge();
		void setFirstName(string);
		void setLastName(string);
		void setAge(int);
		// virtual: funcion declarada en la clase base y redefinida en las clases derivadas
		virtual void toString();
};

Person::Person()
{
	firstName = "N/A";
	lastName = "N/A";
	age = 0;
}

Person::Person(string firstName, string lastName, int age)
{
	this->firstName = firstName;
	this->lastName = lastName;
	this->age = age;
}

string Person::getFirstName()
{
	return firstName;
}

string Person::getLastName()
{
	return lastName;
}

int Person::getAge()
{
	return age;
}

void Person::setFirstName(string firstName)
{
	this->firstName = firstName;
}

void Person::setLastName(string lastName)
{
	this->lastName = lastName;
}

void Person::setAge(int age)
{
	this->age = age;
}

void Person::toString()
{
	cout << firstName << endl;
	cout << lastName << endl;
	cout << age << endl;
}
#endif