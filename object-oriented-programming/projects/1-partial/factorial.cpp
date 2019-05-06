/**
 @progName Factorial
 @desc Program that has a function to make the calculus of the factorial of a given number
 @author Alfredo Salazar Velez
 @date August 28, 2018
 */
#include <iostream>
using namespace std;
/**
 @funcName factorial
 @desc Gets the calculus of the factorial of a number
 @param iNum initial number for which the factorial will be calculated. Must be a positive integer
 @return returns the factorial of iNum
 */
int factorial(int iNum)
{
    int iFac = 1;
    // Calculate the factorial with a FOR loop
    for (int iC = 1; iC <= iNum; iC++)
    {
        iFac = iFac * iC;
    }
    return iFac; // This value is returned to caller
}
/**
 @funcName validateInteger
 @desc Function that asks the user a value and validates that it is in between 1 and 10
 @return returns the value that the user typed in between 1 and 10
 */
int validateInteger()
{
    int iNum;
    do
    {
        cout << "Number ";
        cin >> iNum;
    } while (iNum < 1 || iNum > 10);
    return iNum;
}
/**
 @funcName main
 @desc Ask the value to the user, makes the calculus of the factorial and shows it
 */
int main()
{
    int iNumero, iResult;
    iNumero = validateInteger();
    iResult = factorial(iNumero);
    cout << "Factorial = " << iResult << endl;
    return 0;
}
