/* 
 * complex.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 07/02/2019
*/

#include <iostream>
#include <cstdlib>
#include "Complex.h"

using namespace std;

int main(void)
{
    int real, imaginary;

    // Create first complex object with default constructor
    Complex complex1;

    // Read real and imaginary numbers to create another complex object
    cin >> real >> imaginary;

    // Create second complex number
    Complex complex2(real, imaginary);

    // Display values of both objects
    complex1.toString();
    complex2.toString();

    // Read numbers and add them to the previously created objects
    cin >> real >> imaginary;

    complex1.addComplex(real, imaginary);
    complex2.addComplex(real, imaginary);

    // Display both objects using getters with the corresponding format
    if (complex1.getReal() > 0)
        cout << "+";

    cout << complex1.getReal();

    if (complex1.getImaginary() < 0)
        cout << " - ";
    else
        cout << " + ";

    cout << abs(complex1.getImaginary()) << "i" << endl;

    if (complex2.getReal() > 0)
        cout << "+";

    cout << complex2.getReal();

    if (complex2.getImaginary() < 0)
        cout << " - ";
    else
        cout << " + ";

    cout << abs(complex2.getImaginary()) << "i" << endl;

    // Read numbers and update the default object using setters
    cin >> real >> imaginary;

    complex1.setReal(real);
    complex1.setImaginary(real);

    // Read numbers and substract from both objects
    cin >> real >> imaginary;

    complex1.substractComplex(real, imaginary);
    complex2.substractComplex(real, imaginary);

    // Display both objects
    complex1.toString();
    complex2.toString();

    // Success
    return 0;
}
