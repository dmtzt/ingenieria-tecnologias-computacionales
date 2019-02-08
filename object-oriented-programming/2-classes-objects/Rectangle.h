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
#ifndef Rectangle_h
#define Rectangle
#include <iostream>

using namespace std;

// 1- Class name
class Rectangle
{
    // 2- Scope
    private:
        double width;
        double height;
        string color;
    public:
        // 3- Constructor
        // No parameters: default values
        Rectangle();
        // Parameters: user input values
        Rectangle(double, double, string);
        // Methods
        // Getters
        double getArea();
        double getPerimeter();
        double getWidth();
        double getHeight();
        // Setters
        void setWidth(double);
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
Rectangle::Rectangle()
{
    width = 1.0;
    height = 1.0;
    color = "White";
}

Rectangle::Rectangle(double w, double h, string c)
{
    width = w;
    height = h;
    color = c;
}

double Rectangle::getArea()
{
    return width * height;
}

double Rectangle::getWidth()
{
    return width;
}

double Rectangle::getHeight()
{
    return height;
}

double Rectangle::getPerimeter()
{
    return width * 2 + height * 2;
}

void Rectangle::setHeight(double height)
{
    this->height = height;
}

void Rectangle::setWidth(double width)
{
    this->width = width;
}

void Rectangle::setColor(string color)
{
    this->color = color;
}

void Rectangle::toString()
{
    cout << "Width: " << width << endl;
    cout << "Height: " << height << endl;
    cout << "Color: " << color << endl;
}

#endif