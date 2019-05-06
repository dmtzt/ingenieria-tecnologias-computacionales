#ifndef SQUARE_H
#define SQUARE_H
#include "Shape.h"

class Square : public Shape
{
    public:
        Square();
        Square(double);
        Square(double, double);
        void toString();
        double generatePerimeter();
        double generateArea();
};

Square::Square()
{
    x = 2.0;
    y = 2.0;
}

Square::Square(double side)
{
    x = side;
    y = side;
}

Square::Square(double x, double y)
{
    this->x = x;
    this->y = y;
}

void Square::toString()
{
    cout << "Side length: " << x << endl;
}
    
double Square::generatePerimeter()
{
    return x * 4;
}

double Square::generateArea()
{
    return x * y;
}