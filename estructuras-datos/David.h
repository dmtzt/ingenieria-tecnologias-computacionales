/*
 * David.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 1/12/2019
 */

#ifndef DAVID_H
#define DAVID_H
#include <iostream>

using namespace std;

class David
{
	private:
		int edad, xd, foo, bar;
		float hola, mundo;
	public:
		David();
		David(int, int, int, int, float, float);
		int getEdad();
		int getXd();
		int getFoo();
		int getBar();
		float getHola();
		float getMundo();
		void setEdad(int);
		void setXd(int);
		void setFoo(int);
		void setBar(int);
		void setHola(float);
		void setMundo(float);
		void toString();
};

David::David()
{
	edad = 0;
	xd = 0;
	foo = 0;
	bar = 0;
	hola = 0.0;
	mundo = 0.0;
}

David::David(int edad, int xd, int foo, int bar, float hola, float mundo)
{
	this->edad = edad;
	this->xd = xd;
	this->foo = foo;
	this->bar = bar;
	this->hola = hola;
	this->mundo = mundo;
}

int David::getEdad()
{
	return edad;
}

int David::getXd()
{
	return xd;
}

int David::getFoo()
{
	return foo;
}

int David::getBar()
{
	return bar;
}

float David::getHola()
{
	return hola;
}

float David::getMundo()
{
	return mundo;
}

void David::setEdad(int edad)
{
	this->edad = edad;
}

void David::setXd(int xd)
{
	this->xd = xd;
}

void David::setFoo(int foo)
{
	this->foo = foo;
}

void David::setBar(int bar)
{
	this->bar = bar;
}

void David::setHola(float hola)
{
	this->hola = hola;
}

void David::setMundo(float mundo)
{
	this->mundo = mundo;
}

void David::toString()
{
	cout << edad << endl;
	cout << xd << endl;
	cout << foo << endl;
	cout << bar << endl;
	cout << hola << endl;
	cout << mundo << endl;
}
#endif