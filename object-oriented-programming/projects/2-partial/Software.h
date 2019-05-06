/*
 * Software.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 29/4/2019
 */

#ifndef SOFTWARE_H
#define SOFTWARE_H
#define SOFTWARE_RENTAL_DAYS 1
#include <iostream>
#include "Material.h"

using namespace std;

class Software : public Material
{
	private:
		string operatingSystem;
	public:
		Software();
		Software(int, string, string);
		string getOperatingSystem();
		void setOperatingSystem(string);
		int numDaysRented();
		void toString();
};

Software::Software() : Material()
{
	operatingSystem = "N/A";
	type = 'S';
}

Software::Software(int id, string title, string operatingSystem) :
Material(id, title)
{
	this->operatingSystem = operatingSystem;
}

string Software::getOperatingSystem()
{
	return operatingSystem;
}

void Software::setOperatingSystem(string operatingSystem)
{
	this->operatingSystem = operatingSystem;
}

int Software::numDaysRented()
{
	return SOFTWARE_RENTAL_DAYS;
}

void Software::toString()
{
	cout << id << " " << title << " " << operatingSystem << endl;
}
#endif