/*
 * Standard
 * One class per .h file to use header resources efficiently
 * in case of needing just one single class and not a whole set
 * 
 * A .cpp file cannot be included in another .cpp file
 * 
 * The perimeters are expressed just as types,
 * the names are defined in the implementation
 *
*/
#include <iostream>
#include <cmath>

using namespace std;

// 1- Class name
class Triangle
{
    // 2- Scope
    private:
        double base;
        double height;
        string color;
    public:
        // 3- Constructor
        // No parameters: default values
        Triangle();
        // Parameters: user input values
        Triangle(double, double, string);
        // Methods
        // Getters
        double getArea();
        double getPerimeter();
        double getBase();
        double getHeight();
        // Setters
        void setBase(double);
        void setHeight(double);
        void setColor(string);
        // To string
        void toString();
};

/*
 * Standard
 * Methods are defined outside the class 
 * to be able to reuse the initial structure
*/
Triangle::Triangle()
{
    base = 1.0;
    height = 2.0;
    color = "Blue";
}

Triangle::Triangle(double b, double h, string c)
{
    base = b;
    height = h;
    color = c;
}

double Triangle::getArea()
{
    return base * height / 2;
}

double Triangle::getBase()
{
    return base;
}

double Triangle::getHeight()
{
    return height;
}

double Triangle::getPerimeter()
{
    return sqrt(pow(base / 2, 2) + pow(height, 2)) * 2 + base;
}

void Triangle::setHeight(double height)
{
    this->height = height;
}

void Triangle::setBase(double base)
{
    this->base = base;
}

void Triangle::setColor(string color)
{
    this->color = color;
}

void Triangle::toString()
{
    cout << "Base: " << base << endl;
    cout << "Height: " << height << endl;
    cout << "Color: " << color << endl;
}