/* 
 * math.cpp
 * 
 * Description
 *
 * David Alejandro Martinez Tristan
 * 25/03/2019
*/

#include <iostream>
#include "Math.h"

using namespace std;

int main(void)
{
    double num, result;
    cout << "Give me a number: ";
    cin >> num;

    result = Math::squared(num);

    cout << "Squared" << result << endl;

    return 0;
}
