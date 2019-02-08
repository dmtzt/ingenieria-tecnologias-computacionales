/* 
 * Fraction.h
 *
 * David Alejandro Martinez Tristan
 * 31/01/2019
*/
#include <iostream>

using namespace std;

class Fraction
{
    private:
        int numerator, denominator;
    public:
        Fraction();
        Fraction(int, int);
        int getNumerator();
        int getDenominator();
        void setNumerator(int);
        void setDenominator(int);
        void toString();
        void addFraction(int, int);
        void substractFraction(int, int);
        void divideFraction(int, int);
};

Fraction::Fraction()
{
    numerator = 1;
    denominator = 2;
}

Fraction::Fraction(int numerator, int denominator)
{
    this->numerator = numerator;
    this->denominator = denominator;
}

int Fraction::getNumerator()
{
    return numerator;
}

int Fraction::getDenominator()
{
    return denominator;
}

void Fraction::setNumerator(int numerator)
{
    this->numerator = numerator;
}

void Fraction::setDenominator(int denominator)
{
    this->denominator=denominator;
}

void Fraction::toString()
{
    cout << numerator << "/" << denominator << endl;
}

void Fraction::addFraction(int numerator, int denominator)
{
    this->numerator = this->numerator * denominator + numerator * this->denominator;
    this->denominator *= denominator;
}

void Fraction::substractFraction(int numerator, int denominator)
{
    this->numerator = this->numerator * denominator - numerator * this->denominator;
    this->denominator *= denominator;
}

void Fraction::divideFraction(int numerator, int denominator)
{
    this->numerator *= denominator;
    this->denominator *= numerator;
}