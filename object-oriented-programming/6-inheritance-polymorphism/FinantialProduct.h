/*
 * FinantialProduct.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 8/4/2019
 */

#ifndef FINANTIALPRODUCT_H
#define FINANTIALPRODUCT_H
#include <iostream>

using namespace std;

class FinantialProduct
{
	protected:
		double value;
		string owner;
	public:
		FinantialProduct();
		FinantialProduct(double, string);
		double getValue();
		string getOwner();
		void setValue(double);
		void setOwner(string);
		double generateTax();
		void toString();
};

FinantialProduct::FinantialProduct()
{
	value = 0.0;
	owner = "N/A";
}

FinantialProduct::FinantialProduct(double value, string owner)
{
	this->value = value;
	this->owner = owner;
}

double FinantialProduct::getValue()
{
	return value;
}

string FinantialProduct::getOwner()
{
	return owner;
}

void FinantialProduct::setValue(double value)
{
	this->value = value;
}

void FinantialProduct::setOwner(string owner)
{
	this->owner = owner;
}

double FinantialProduct::generateTax()
{
	return value * 0.18;
}

void FinantialProduct::toString()
{
	cout << value << endl;
	cout << owner << endl;
}
#endif