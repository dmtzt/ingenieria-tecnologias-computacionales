/* 
 * Fraction.h
 *
 * David Alejandro Martinez Tristan
 * 31/01/2019
*/
#include <iostream>
// Create flags if they have not been created already
// These directives are used to avoid including a class twice in the main program
#ifndef Fraction_h
#define Fraction_h

using namespace std;

class Fraction
{
    private:
        int numerator, denominator;
    public:
        Fraction();
        Fraction(int, int);
        Fraction add(Fraction);
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

/*
 * Composition
 * 
*/
Fraction Fraction::add(Fraction fraction)
{
    Fraction result;
    result.setNumerator(numerator * fraction.getDenominator() 
                        + fraction.getNumerator * denominator);
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

#endif