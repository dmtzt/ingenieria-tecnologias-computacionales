/*
 * Action.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 8/4/2019
 */

#ifndef ACTION_H
#define ACTION_H
#include <iostream>
#include "FinantialProduct.h"

using namespace std;

class Action : FinantialProduct
{
	private:
		double percentage, actionValue;
		string company;
	public:
		Action();
		Action(double, double, string, double, string);
		double getPercentage();
		double getActionValue();
		string getCompany();
		void setPercentage(double);
		void setActionValue(double);
		void setCompany(string);
		double getTotalValue();
		double generateTax();
		void toString();
};

Action::Action() : FinantialProduct()
{
	percentage = 0.0;
	actionValue = 0.0;
	company = "N/A";
}

Action::Action(double percentage, double actionValue, string company, double value, string owner) :
FinantialProduct(value, owner)
{
	this->percentage = percentage;
	this->actionValue = actionValue;
	this->company = company;
}

double Action::getPercentage()
{
	return percentage;
}

double Action::getActionValue()
{
	return actionValue;
}

string Action::getCompany()
{
	return company;
}

void Action::setPercentage(double percentage)
{
	this->percentage = percentage;
}

void Action::setActionValue(double actionValue)
{
	this->actionValue = actionValue;
}

void Action::setCompany(string company)
{
	this->company = company;
}

double Action::getTotalValue()
{
	return percentage * actionValue - value;
}

double Action::generateTax()
{
	return getTotalValue() * 0.18;	
}

void Action::toString()
{
	FinantialProduct::toString();
	cout << percentage << endl;
	cout << actionValue << endl;
	cout << company << endl;
}
#endif