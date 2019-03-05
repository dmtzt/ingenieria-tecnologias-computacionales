/* 
 * sphere.cpp
 * 
 * Creates 2 spheres with custom and default radius, 
 * calculates their area and volume and indicates
 * which is the smallest of the two.
 *
 * David Alejandro Martinez Tristan
 * 27/02/2019
*/

#include <iostream>
#include "Sphere.h"

using namespace std;

int main(void)
{
    int radius;
    Sphere sphereA;

    cin >> radius;

    Sphere sphereB(radius);

    cout << "Radius A:" << sphereA.getRadius() << " ";
    cout << "Radius B:" << sphereB.getRadius() << endl;
    cout << "Area A:" << sphereA.getArea() << " ";
    cout << "Area B:" << sphereB.getArea() << endl;
    cout << "Volume A:" << sphereA.getVolume() << " ";
    cout << "Volume B:" << sphereB.getVolume() << endl;

    if (sphereA.smallest(sphereB).getRadius() == sphereA.getRadius())
        cout << "The smallest sphere is: A and it has a radius of" 
             << sphereA.getRadius(); 
    else
        cout << "The smallest sphere is: B and it has a radius of" 
             << sphereB.getRadius(); 

    return 0;
}