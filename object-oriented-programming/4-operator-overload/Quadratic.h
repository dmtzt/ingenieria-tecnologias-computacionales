/*
 * Quadratic.h
 * 
 * David Alejandro Martinez Tristan
 * 21/3/2019
 */

#ifndef QUADRATIC_H
#define QUADRATIC_H
#include <iostream>

using namespace std;

class Quadratic
{
	private:
		int a, b, c;
	public:
		Quadratic();
		Quadratic(int, int, int);
		int getA();
		int getB();
		int getC();
		void setA(int);
		void setB(int);
		void setC(int);
		void toString();

		Quadratic operator+(Quadratic);
		Quadratic operator-(Quadratic);
		Quadratic operator +=(Quadratic);
		Quadratic operator -=(Quadratic);

		//friend void operator+=(Quadratic&, Quadratic);
		//friend void operator-=(Quadratic&, Quadratic);
		friend istream& operator>>(istream&, Quadratic&);
		friend ostream& operator<<(ostream&, Quadratic);
		friend bool operator==(Quadratic, Quadratic);
};

Quadratic::Quadratic()
{
	a = 0;
	b = 0;
	c = 0;
}

Quadratic::Quadratic(int a, int b, int c)
{
	this->a = a;
	this->b = b;
	this->c = c;
}

int Quadratic::getA()
{
	return a;
}

int Quadratic::getB()
{
	return b;
}

int Quadratic::getC()
{
	return c;
}

void Quadratic::setA(int a)
{
	this->a = a;
}

void Quadratic::setB(int b)
{
	this->b = b;
}

void Quadratic::setC(int c)
{
	this->c = c;
}

void Quadratic::toString()
{
	cout << a << endl;
	cout << b << endl;
	cout << c << endl;
}


Quadratic Quadratic::operator+(Quadratic quad)
{
	int aR, bR, cR;

	aR = a + quad.a;
	bR = b + quad.b;
	cR = c + quad.c;

	Quadratic result(aR, bR, cR);

	return result;
}

Quadratic Quadratic::operator-(Quadratic quad)
{
	int aR, bR, cR;

	aR = a - quad.a;
	bR = b - quad.b;
	cR = c - quad.c;

	Quadratic result(aR, bR, cR);

	return result;
}

Quadratic Quadratic::operator +=(Quadratic quad)
{
	a += quad.a;
	b += quad.b;
	c += quad.c;

	return *this;
}

Quadratic Quadratic::operator -=(Quadratic quad)
{
	a -= quad.a;
	b -= quad.b;
	c -= quad.c;

	return *this;
}

istream& operator>>(istream& is, Quadratic& quad)
{
	int a, b, c;
	is >> a >> b >> c;
	
	quad.setA(a);
	quad.setB(b);
	quad.setC(c);

	return is;
}

ostream& operator<<(ostream& os, Quadratic quad)
{
	os << quad.a << "x^2";
	
	if (quad.b > 0)
		cout << "+" << quad.b << "x";
	else if (quad.b < 0)
		cout << quad.b << "x";

	if (quad.c > 0)
		cout << "+" << quad.c;
	else if (quad.c < 0)
		cout << quad.c;

	return os;
}

bool operator==(Quadratic quad1, Quadratic quad2)
{
	if (quad1.a == quad2.a && quad1.b == quad2.b && quad1.c == quad2.c)
		return true;
	else
		return false;
}
#endif