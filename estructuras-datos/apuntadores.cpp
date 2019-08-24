#include <iostream>

using namespace std;

int main(void)
{
    int *pA, B = 10;
    double *pX, Y = 1.54;
    pA = &B;
    pX = &Y;

    pX = pA;
}