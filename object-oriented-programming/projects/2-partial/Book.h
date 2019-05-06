/*
 * Book.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 29/4/2019
 */

#ifndef BOOK_H
#define BOOK_H
#define BOOK_RENTAL_DAYS 10
#include <iostream>
#include "Material.h"

using namespace std;

class Book : public Material
{
	private:
		int numPages;
		string author;
	public:
		Book();
		Book(int, string, int, string);
		int getNumPages();
		string getAuthor();
		void setNumPages(int);
		void setAuthor(string);
		int numDaysRented();
		void toString();
};

Book::Book() : Material()
{
	numPages = 0;
	author = "N/A";
	type = 'B';
}

Book::Book(int id, string title, int numPages, string author) :
Material(id, title)
{
	this->numPages = numPages;
	this->author = author;
}

int Book::getNumPages()
{
	return numPages;
}

string Book::getAuthor()
{
	return author;
}

void Book::setNumPages(int numPages)
{
	this->numPages = numPages;
}

void Book::setAuthor(string author)
{
	this->author = author;
}

int Book::numDaysRented()
{
	return BOOK_RENTAL_DAYS;
}

void Book::toString()
{
	cout << id << " " << title << " " << numPages << " " << author << endl;
}
#endif