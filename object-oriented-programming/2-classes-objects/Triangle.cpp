/* 
 * Rectangle.cpp
 * 
 *
 * David Alejandro Martinez Tristan
 * 28/01/2019
*/

#include <iostream>
#include "Triangle.h"

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

    Triangle triangle1;
    Triangle triangle2(width, height, color);

    result = triangle1.getArea();
    cout << "Area of R1: " << result << endl;

    result = triangle2.getArea();
    cout << "Area of R2: " << result << endl;
    
    return 0;
}