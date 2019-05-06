/* 
 * complex.cpp
 *
 * David Alejandro Martinez Tristan
 * 18/03/2019
*/

#include <iostream>
#include "Complex.h"

using namespace std;

int main(void)
{
    int r1, r2, i1, i2;

    cout << "Please give complex 1: [real] [imaginary]" << endl;
    cin >> r1 >> i1;

    cout << "Please give complex 2: [real] [imaginary]" << endl;
    cin >> r2 >> i2;

    Complex complex1(r1, i1);
    Complex complex2(r2, i2);
    Complex result;

    result = complex1 + complex2;
    cout << "complex1 + complex2 = ";
    result.toString();

    result = complex1 - complex2;
    cout << "complex1 - complex2 = ";
    result.toString();

    result = complex1 * complex2;
    cout << "complex1 * complex2 = ";
    result.toString();

    result = complex1 / complex2;
    cout << "complex1 / complex2 = ";
    result.toString();
    
    cout << "complex1 < complex2 = ";
    if (complex1 < complex2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "complex1 > complex2 = ";
    if (complex1 > complex2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "complex1 <= complex2 = ";
    if (complex1 <= complex2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "complex1 >= complex2 = ";
    if (complex1 >= complex2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "complex1 == complex2 = ";
    if (complex1 == complex2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "complex1 != complex2 = ";
    if (complex1 != complex2)
        cout << "true" << endl;
    else
        cout << "false" << endl;

    cout << "complex1++ = ";
    complex1++;
    complex1.toString();

    cout << "complex2-- = ";
    complex2--;
    complex1.toString();

    cout << "Please give complex to add: [real] [imaginary]" << endl;
    cin >> r1 >> i1;
    Complex complex3(r1, i1);

    cout << "Please give complex to subtract: [real] [imaginary]" << endl;
    cin >> r2 >> i2;
    Complex complex4(r2, i2);
    
    cout << "complex1 += complex3 = ";
    complex1 += complex3;
    complex1.toString();
    
    cout << "complex2 -= complex4 = ";
    complex2 -= complex4;
    complex2.toString();

    return 0;
}