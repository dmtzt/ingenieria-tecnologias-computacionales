/* 
 * Complex.h
 *
 * David Alejandro Martinez Tristan
 * 07/02/2019
*/
#include <iostream>
#include <cstdlib>

using namespace std;

class Complex
{
    private:
        int real, imaginary;
    public:
        Complex();
        Complex(int, int);
        int getReal();
        int getImaginary();
        void setReal(int);
        void setImaginary(int);
        void addComplex(int, int);
        void substractComplex(int, int);
        void toString();
};

Complex::Complex()
{
    real = 1;
    imaginary = 1;
}

Complex::Complex(int real, int imaginary)
{
    this->real = real;
    this->imaginary = imaginary;
}

int Complex::getImaginary()
{
    return imaginary;
}

int Complex::getReal()
{
    return real;
}

void Complex::setReal(int real)
{
    this->real = real;
}

void Complex::setImaginary(int imaginary)
{
    this->imaginary = imaginary;
}

void Complex::addComplex(int real, int imaginary)
{
    this->real += real;
    this->imaginary += imaginary;
}

void Complex::substractComplex(int real, int imaginary)
{
    this->real -= real;
    this->imaginary -= imaginary;
}

void Complex::toString()
{
    if (real > 0)
        cout << "+";
    
    cout << real;

    if (imaginary < 0)
        cout << " - ";
    else
        cout << " + ";

    cout << abs(imaginary) << "i" << endl;
}