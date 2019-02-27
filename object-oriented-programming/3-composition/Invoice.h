/* 
 * Invoice.h
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 25/02/2019
*/
#ifndef INVOICE_H
#define INVOICE_H

#include <iostream>

using namespace std;

class Invoice
{
    private:
        double hourSalary;
        int workedHours;
        string month;
    public:
        Invoice();
        Invoice(double, int, string);
        double getHourSalary();
        int getWorkedHours();
        string getMonth();
        void setHourSalary(double);
        void setWorkedHours(int);
        void setMonth(string);
        void toString();
        double generateMonthlySalary(int);
        double applyBonus(int);
};

Invoice::Invoice()
{
    hourSalary = 0.0;
    workedHours = 0;
    month = "N/A";
}

Invoice::Invoice(double hourSalary, int workedHours, string month)
{
    this->hourSalary = hourSalary;
    this->workedHours = workedHours;
    this->month = month;
}

double Invoice::getHourSalary()
{
    return hourSalary;
}

int Invoice::getWorkedHours()
{
    return workedHours;
}

string Invoice::getMonth()
{
    return month;
}

void Invoice::setHourSalary(double hourSalary)
{
    this->hourSalary = hourSalary;
}

void Invoice::setWorkedHours(int workedHours)
{
    this->workedHours = workedHours;
}

void Invoice::setMonth(string month)
{
    this->month = month;
}

void Invoice::toString()
{
    cout << hourSalary;
    cout << workedHours;
    cout << month;
}

double Invoice::generateMonthlySalary(int percentage)
{
    return hourSalary * workedHours + applyBonus(percentage);
}

double Invoice::applyBonus(int percentage)
{
    double bonus = percentage / 100;
    return (workedHours / 2) * (hourSalary * bonus); 
}
#endif