/*
 * CD.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 29/4/2019
 */

#ifndef CD_H
#define CD_H
#define CD_RENTAL_DAYS 3
#include <iostream>
#include "Material.h"

using namespace std;

class CD : public Material
{
	private:
		int duration;
	public:
		CD();
		CD(int, string, int);
		int getDuration();
		void setDuration(int);
		int numDaysRented();
		void toString();
};

CD::CD() : Material()
{
	duration = 0;
	type = 'C';
}

CD::CD(int id, string title, int duration) :
Material(id, title)
{
	this->duration = duration;
}

int CD::getDuration()
{
	return duration;
}

void CD::setDuration(int duration)
{
	this->duration = duration;
}

int CD::numDaysRented()
{
	return CD_RENTAL_DAYS;
}

void CD::toString()
{
	cout << id << " " << title << " " << duration << endl;
}
#endif