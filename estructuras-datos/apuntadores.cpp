#include <iostream>

using namespace std;

int main(void)
{
    double one[10];
    //double two[5][5];
    double value = 1.0;
    double* ptr = &value;

    *one = value;
    ptr = one;
    ptr = &one;

    cout << one[0];
}