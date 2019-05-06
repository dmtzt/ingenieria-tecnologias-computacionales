/*
 * Date.h
 * 
 * David Alejandro Martinez Tristan
 * 29/4/2019
 */

#ifndef DATE_H
#define DATE_H
#define JAN 1
#define FEB 2
#define MAR 3
#define APR 4
#define MAY 5
#define JUN 6
#define JUL 7
#define AUG 8
#define SEPT 9
#define OCT 10
#define NOV 11
#define DEC 12
#include <iostream>

using namespace std;

class Date
{
	private:
		int day, month, year;
	public:
		Date();
		Date(int, int, int);
		int getDay();
		int getMonth();
		int getYear();
		void setDay(int);
		void setMonth(int);
		void setYear(int);
		void toString();
		Date operator+(int);
		bool operator>(Date);
		bool operator<(Date);
		bool operator>=(Date);
		bool operator<=(Date);
		bool operator==(Date);
		friend istream& operator<<(istream&, Date&); 
		friend ostream& operator>>(ostream&, Date);
		string monthName();
};

Date::Date()
{
	day = 0;
	month = 0;
	year = 0;
}

Date::Date(int day, int month, int year)
{
	this->day = day;
	this->month = month;
	this->year = year;
}

int Date::getDay()
{
	return day;
}

int Date::getMonth()
{
	return month;
}

int Date::getYear()
{
	return year;
}

void Date::setDay(int day)
{
	this->day = day;
}

void Date::setMonth(int month)
{
	this->month = month;
}

void Date::setYear(int year)
{
	this->year = year;
}

void Date::toString()
{
	cout << day << endl;
	cout << month << endl;
	cout << year << endl;
}

Date Date::operator+(int days)
{
	int newDay = day;
	int newMonth = month;
	int newYear = year;

	switch (newMonth)
	{
	case FEB:
		if (newDay + days > 28)
			newMonth++;
		newDay = (newDay + days) % 28;
		newDay = (newDay == 0) ? 1 : newDay;
		break;
	case DEC:
		if (newDay + days > 31)
		{
			newMonth++;
			newYear++;
		}
		newDay = (newDay + days) % 31;
		newDay = (newDay == 0) ? 1 : newDay;
		break;
	case JAN:
	case MAR:
	case MAY:
	case JUL:
	case AUG:
	case OCT:
		if (newDay + days > 31)
			newMonth++;
		newDay = (newDay + days) % 31;
		newDay = (newDay == 0) ? 1 : newDay;
		break;
	case APR:
	case JUN:
	case SEPT:
	case NOV:
		if (newDay + days > 30)
			newMonth++;
		newDay = (newDay + days) % 30;
		newDay = (newDay == 0) ? 1 : newDay;
		break;
	default:
		break;
	}

	Date newDate(newDay, newMonth, newYear);
	return newDate;
}

bool Date::operator>(Date date)
{
	if (year > date.getYear())
		return true;
	else if (year == date.getYear())
	{
		if (month > date.getMonth())
			return true;
		else if (month == date.getMonth())
		{
			if (day > date.getDay())
				return true;
		}
	}

	return false;
}

bool Date::operator<(Date date)
{
	if (year < date.getYear())
		return true;
	else if (year == date.getYear())
	{
		if (month < date.getMonth())
			return true;
		else if (month == date.getMonth())
		{
			if (day < date.getDay())
				return true;
		}
	}

	return false;
}

bool Date::operator>=(Date date)
{
	if (year > date.getYear())
		return true;
	else if (year == date.getYear())
	{
		if (month > date.getMonth())
			return true;
		else if (month == date.getMonth())
		{
			if (day > date.getDay() || day == date.getDay())
				return true;
		}
	}

	return false;
}

bool Date::operator<=(Date date)
{
	if (year < date.getYear())
		return true;
	else if (year == date.getYear())
	{
		if (month < date.getMonth())
			return true;
		else if (month == date.getMonth())
		{
			if (day < date.getDay() || day == date.getDay())
				return true;
		}
	}

	return false;
}

bool Date::operator==(Date date)
{
	if (day == date.getDay() && month == date.getMonth() && year == date.getYear())
		return true;

	return false;
}

istream& operator>>(istream& is, Date& date)
{
	int day, month, year;
	is >> day >> month >> year;

	date.setDay(day);
	date.setMonth(month);
	date.setYear(year);

	return is;
}

ostream& operator<<(ostream& os, Date date)
{
	os << date.getDay() << " " << date.getMonth() << " " << date.getYear();

	return os;
}

string Date::monthName()
{
	switch (month)
	{
	case JAN:
		return "January";
		break;
	case FEB:
		return "February";
		break;
	case MAR:
		return "March";
		break;
	case APR:
		return "April";
		break;
	case MAY:
		return "May";
		break;
	case JUN:
		return "June";
		break;
	case JUL:
		return "July";
		break;
	case AUG:
		return "August";
		break;
	case SEPT:
		return "September";
		break;
	case OCT:
		return "October";
		break;
	case NOV:
		return "November";
		break;
	case DEC:
		return "December";
		break;
	default:
		return "N/A";
		break;
	}
}
#endif