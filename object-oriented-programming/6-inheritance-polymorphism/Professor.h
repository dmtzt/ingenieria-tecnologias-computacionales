/*
 * Professor.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 1/4/2019
 */

#ifndef PROFESSOR_H
#define PROFESSOR_H
#include <iostream>
#include "Person.h"

using namespace std;

class Professor : public Person
{
	private:
		int id;
		string department;
	public:
		Professor();
		Professor(string, string, int, int, string);
		int getId();
		string getDepartment();
		void setId(int);
		void setDepartment(string);
		void toString();
};

Professor::Professor() : Professor()
{
	id = 0;
	department = "N/A";
}

Professor::Professor(string firstName, string lastName, int age, int id, string department) : Person(firstName, lastName, age)
{
	this->id = id;
	this->department = department;
}

int Professor::getId()
{
	return id;
}

string Professor::getDepartment()
{
	return department;
}

void Professor::setId(int id)
{
	this->id = id;
}

void Professor::setDepartment(string department)
{
	this->department = department;
}

void Professor::toString()
{
	Person::toString();
	cout << id << endl;
	cout << department << endl;
}
#endif