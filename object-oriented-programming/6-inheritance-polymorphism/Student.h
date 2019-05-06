/*
 * Student.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 1/4/2019
 */

#ifndef STUDENT_H
#define STUDENT_H
#include <iostream>
#include "Person.h"

using namespace std;

// Parent class the child class inherits
class Student : public Person
{
	private:
		string degree;
		int id;
	public:
		Student();
		Student(string, string, int, string, int);
		string getDegree();
		int getId();
		void setDegree(string);
		void setId(int);
		void toString();
};

// The parent default constructor is called automatically
// Methods can be overriden
Student::Student() : Person()
{
	degree = "N/A";
	// Age default value was override
	age = 30;
	id = 0;
}

// The parent constructor is called automatically, specifying the desired arguments
// If the custom constructor is not called, the default one is called
Student::Student(string firstName, string lastName, int age, string degree, int id) : Person(firstName, lastName, age)
{
	this->degree = degree;
	this->id = id;
}

string Student::getDegree()
{
	return degree;
}

int Student::getId()
{
	return id;
}

void Student::setDegree(string degree)
{
	this->degree = degree;
}

void Student::setId(int id)
{
	this->id = id;
}

// When a method is modified, it is overriden
// No new instructions can be added to the already defined ones
void Student::toString()
{
	Person::toString();
	cout << degree << endl;
	cout << id << endl;
}
#endif