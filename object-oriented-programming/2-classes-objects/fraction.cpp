/* 
 * fraction.cpp
 *
 * David Alejandro Martinez Tristan
 * 07/02/2019
*/

#include <iostream>
#include "Fraction.h"

using namespace std;

int main(void)
{
    Fraction frac1();
    Fraction frac2(2, 3);

    frac2.addFraction(1, 3);
    cout << frac2.getNumerator() << "/" << frac2.getDenominator() << endl;
    frac2.substractFraction(4,8);
    cout << frac2.getNumerator() << "/" << frac2.getDenominator() << endl;
    frac2.divideFraction(1,2);
    cout << frac2.getNumerator() << "/" << frac2.getDenominator() << endl;

    return 0;
}
