/*
 * Fraction.h
 *
 * David Alejandro Martinez Tristan
 * 11/3/2019
 */

#ifndef FRACTION_H
#define FRACTION_H
#include <iostream>

using namespace std;

class Fraction
{
	private:
		int num, denom;
	public:
		Fraction();
		Fraction(int, int);
		int getNum();
		int getDenom();
		void setNum(int);
		void setDenom(int);
		void toString();
		Fraction add(Fraction);
		// 1/2 Operator overload
		Fraction operator+(Fraction);
		// 2/2 Operator overload
		friend Fraction operator-(Fraction, Fraction);

		friend istream& operator>>(istream&, Fraction&);

		friend ostream& operator<<(ostream&, Fraction);

		bool operator==(Fraction);
};

Fraction::Fraction()
{
	num = 0;
	denom = 0;
}

Fraction::Fraction(int num, int denom)
{
	this->num = num;
	this->denom = denom;
}

int Fraction::getNum()
{
	return num;
}

int Fraction::getDenom()
{
	return denom;
}

void Fraction::setNum(int num)
{
	this->num = num;
}

void Fraction::setDenom(int denom)
{
	this->denom = denom;
}

void Fraction::toString()
{
	cout << num << endl;
	cout << denom << endl;
}

Fraction Fraction::add(Fraction fraction)
{
	int num, denom;
	num = fraction.getNum() * this->denom + fraction.getDenom() * this->num;
	denom = fraction.getDenom() * this->denom;
	Fraction result(num, denom);
	return result;
}

// This implementation allows direct access to argument private attributes	
Fraction Fraction::operator+(Fraction fraction)
{
	int num, denom;
	num = fraction.num * this->denom + fraction.denom * this->num;
	denom = fraction.denom * this->denom;
	Fraction result(num, denom);
	return result;
}

// The class name and "friend" keyword are not written
// Direct access to argument private attributes
Fraction operator-(Fraction fraction1, Fraction fraction2)
{
	int n, d;
	n = fraction1.num * fraction2.denom - fraction2.num * fraction1.denom;
	d = fraction1.denom * fraction2.denom;
	Fraction result(n, d);
	return result;
}

bool Fraction::operator==(Fraction fraction)
{
	double div1 = (double) num / denom;
	double div2 = (double) fraction.num / fraction.denom;
	
	if (div1 == div2)
		return true;
	else
		return false;
}

istream& operator>>(istream &is, Fraction &frac)
{
	int num, denom;

	cout << "Please give me a fraction:" << endl;

	is >> num;
	cout << "/" << endl;
	is >> denom;

	frac.num = num;
	frac.denom = denom;

	return is;
}

ostream& operator<<(ostream &os, Fraction frac)
{
	os << frac.num << "/" << frac.denom;
	return os;
}

#endif