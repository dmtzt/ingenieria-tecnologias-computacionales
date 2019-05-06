/* 
 * templates.cpp
 *
 * David Alejandro Martinez Tristan
 * 25/04/2019
*/

#include <iostream>

template<class T>
T sum(T num1, T num2)
{
    return num1 + num2;
}

using namespace std;

int main(void)
{
    cout << sum(1, 2);
    return 0;
}

