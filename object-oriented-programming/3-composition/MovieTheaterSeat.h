/*
 * MovieTheaterSeat.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 7/3/2019
 */

#ifndef MOVIETHEATERSEAT_H
#define MOVIETHEATERSEAT_H
#include <iostream>

using namespace std;

class MovieTheaterSeat
{
	private:
		bool reserved;
	private:
		string name;
	public:
		MovieTheaterSeat();
		MovieTheaterSeat(bool, string);
		bool getReserved();
		string getName();
		void setReserved(bool);
		void setName(string);
		void toString();
};

MovieTheaterSeat::MovieTheaterSeat()
{
	reserved = false;
	name = "Not reserved";
}

MovieTheaterSeat::MovieTheaterSeat(bool reserved, string name)
{
	this->reserved = reserved;
	this->name = name;
}

bool MovieTheaterSeat::getReserved()
{
	return reserved;
}

string MovieTheaterSeat::getName()
{
	return name;
}

void MovieTheaterSeat::setReserved(bool reserved)
{
	this->reserved = reserved;
}

void MovieTheaterSeat::setName(string name)
{
	this->name = name;
}

void MovieTheaterSeat::toString()
{	
	if (reserved)
		cout << "Reserved" << endl;
	else
		cout << "Available" << endl;
	cout << name << endl;
}
#endif