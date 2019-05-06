/* 
 * quadratic.cpp
 *
 * David Alejandro Martinez Tristan
 * 21/03/2019
*/

#include <iostream>
#include "Quadratic.h"

using namespace std;

int main(void)
{
    Quadratic quad1;
    cin >> quad1;

    Quadratic quad2(3, 4, 5);
    quad1 += quad2;

    cout << quad1;
    return 0;
}