/* 
 * abstract.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 11/04/2019
*/

#include <iostream>
#include "Square.h"

using namespace std;

int main(void)
{
    Shape *shapes[2];

    shapes[0] = new Square(3);
    shapes[1] = new Square(4, 5);
    return 0;
}
