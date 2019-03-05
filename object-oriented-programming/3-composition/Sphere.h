/*
 * Sphere.h
 * 
 * David Alejandro Martinez Tristan 
 * 27/2/2019
 */

#ifndef SPHERE_H
#define SPHERE_H
#define PI 3.1416

#include <cmath>
#include <iostream>

using namespace std;

class Sphere
{
	private:
		double radius;
	public:
		Sphere();
		Sphere(double);
		double getRadius();
		void setRadius(double);
		void toString();
		double getArea();
		double getVolume();
		Sphere smallest(Sphere);
};

Sphere::Sphere()
{
	radius = 5.0;
}

Sphere::Sphere(double radius)
{
	this->radius = radius;
}

double Sphere::getRadius()
{
	return radius;
}

void Sphere::setRadius(double radius)
{
	this->radius = radius;
}

void Sphere::toString()
{
	cout << radius << endl;
}


double Sphere::getArea()
{
	return 4 * PI * pow(radius, 2);
}

double Sphere::getVolume()
{
	return (4.0/3.0) * PI * pow(radius, 3);
}

Sphere Sphere::smallest(Sphere sphere)
{
	if (sphere.getRadius() > radius)
		return *this;
	else
		return sphere;
}
#endif