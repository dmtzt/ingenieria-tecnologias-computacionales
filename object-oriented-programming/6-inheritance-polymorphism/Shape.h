/*
 * Shape.h
 * 
 * David Alejandro Martinez Tristan
 * 11/4/2019
 */

#ifndef SHAPE_H
#define SHAPE_H
#include <iostream>

using namespace std;

// Abstract class
class Shape
{
	protected:
		double x, y;
	public:
		// Constructors can be defined
		Shape();
		Shape(double, double);
		// All methods of abstract classes must be pure virtual functions
		// A pure virtual function is declared by using a pure specifier (= 0)
		virtual double generatePerimeter() = 0;
		virtual double generateArea() = 0;
		void toString();
};

Shape::Shape()
{
	x = 1.0;
	y = 1.0;
}

Shape::Shape(double x, double y)
{
	this->x = x;
	this->y = y;
}

double Shape::getX()
{
	return x;
}

double Shape::getY()
{
	return y;
}

void Shape::setX(double x)
{
	this->x = x;
}

void Shape::setY(double y)
{
	this->y = y;
}

void Shape::toString()
{
	cout << x << endl;
	cout << y << endl;
}
#endif