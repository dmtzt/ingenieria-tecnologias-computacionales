/* 
 * Rectangle.cpp
 * 
 *
 * David Alejandro Martinez Tristan
 * 28/01/2019
*/

#include <iostream>
#include "Rectangle.h"

using namespace std;

int main(void)
{
    double width, height, result;
    string color;

    cout << "Width: ";
    cin >> width;
    cout << "Height: ";
    cin >> height;
    cout << "Color: ";
    cin >> color;

    Rectangle rectangle1;
    Rectangle rectangle2(width, height, color);

    result = rectangle1.getArea();
    cout << "Area of R1: " << result << endl;

    result = rectangle2.getArea();
    cout << "Area of R2: " << result << endl;
    
    return 0;
}