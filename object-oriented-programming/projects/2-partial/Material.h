/*
 * Material.h
 * 
 * Description
 * 
 * David Alejandro Martinez Tristan
 * 29/4/2019
 */

#ifndef MATERIAL_H
#define MATERIAL_H
#include <iostream>

using namespace std;

class Material
{
	protected:
		int id;
		char type;
		string title;
	public:
		Material();
		Material(int, string);
		int getId();
		char getType();
		string getTitle();
		void setId(int);
		void setType(char);
		void setTitle(string);
		virtual void toString() = 0;
		virtual int numDaysRented() = 0;
};

Material::Material()
{
	id = 0;
	title = "N/A";
}

Material::Material(int id, string title)
{
	this->id = id;
	this->title = title;
}

int Material::getId()
{
	return id;
}

char Material::getType()
{
	return type;
}

string Material::getTitle()
{
	return title;
}

void Material::setId(int id)
{
	this->id = id;
}

void Material::setType(char type)
{
	this->type = type;
}

void Material::setTitle(string title)
{
	this->title = title;
}
#endif