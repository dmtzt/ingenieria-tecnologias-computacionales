/*
 * Complex.h
 *
 * David Alejandro Martinez Tristan
 * 18/3/2019
 */

#ifndef COMPLEX_H
#define COMPLEX_H
#include <iostream>

using namespace std;

/*
 * TODO
 * Operator overload: + - * / < > <= >= == != ++ -- += -=
 * Compare real, then imaginary
 * 1i > 0i
 * ++ -- both real and imaginary
 */

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
		void toString();
		Complex operator+(Complex);
		Complex operator-(Complex);
		Complex operator*(Complex);
		Complex operator/(Complex);
		bool operator<(Complex);
		bool operator>(Complex);
		bool operator<=(Complex);
		bool operator>=(Complex);
		bool operator==(Complex);
		bool operator!=(Complex);
		Complex operator++(int);
		Complex operator--(int);
		Complex operator+=(Complex);
		Complex operator-=(Complex);
};

Complex::Complex()
{
	real = 0;
	imaginary = 0;
}

Complex::Complex(int real, int imaginary)
{
	this->real = real;
	this->imaginary = imaginary;
}

int Complex::getReal()
{
	return real;
}

int Complex::getImaginary()
{
	return imaginary;
}

void Complex::setReal(int real)
{
	this->real = real;
}

void Complex::setImaginary(int imaginary)
{
	this->imaginary = imaginary;
}

void Complex::toString()
{
	cout << real << " ";

	if (imaginary >= 0)
		cout << "+ ";

	cout  << imaginary << "i" << endl;
}

Complex Complex::operator+(Complex complex)
{
	int r = real + complex.real;
	int i = imaginary + complex.imaginary;
	Complex result(r, i);
	return result;
}

Complex Complex::operator-(Complex complex)
{
	int r = real - complex.real;
	int i = imaginary - complex.imaginary;
	Complex result(r, i);
	return result;
}

Complex Complex::operator*(Complex complex)
{
	int r = real * complex.real;
	int i = imaginary * complex.imaginary;
	Complex result(r, i);
	return result;
}

Complex Complex::operator/(Complex complex)
{
	int r = real / complex.real;
	int i = imaginary / complex.imaginary;
	Complex result(r, i);
	return result;
}

bool Complex::operator<(Complex complex)
{
	if (real < complex.real)
		return true;
	else if (complex.real < real)
		return false;
	else
	{
		if (imaginary < complex.imaginary)
			return true;
		else
			return false;
	}
}

bool Complex::operator>(Complex complex)
{
	if (real > complex.real)
		return true;
	else if (complex.real > real)
		return false;
	else
	{
		if (imaginary > complex.imaginary)
			return true;
		else
			return false;
	}
}

bool Complex::operator<=(Complex complex)
{
	if (real < complex.real)
		return true;
	else if (complex.real < real)
		return false;
	else
	{
		if (imaginary < complex.imaginary)
			return true;
		else if (imaginary == complex.imaginary)
			return true;
		else
			return false;
	}
}

bool Complex::operator>=(Complex complex)
{
	if (real > complex.real)
		return true;
	else if (complex.real > real)
		return false;
	else
	{
		if (imaginary > complex.imaginary)
			return true;
		else if (imaginary == complex.imaginary)
			return true;
		else
			return false;
	}
}

bool Complex::operator==(Complex complex)
{
	if (real == complex.real && imaginary == complex.imaginary)
		return true;
	else
		return false;
}

bool Complex::operator!=(Complex complex)
{
	if (real != complex.real || imaginary != complex.imaginary)
		return true;
	else
		return false;
}

Complex Complex::operator++(int)
{
	Complex result(real, imaginary);
	real++;
	imaginary++;
	return result;
}

Complex Complex::operator--(int)
{
	Complex result(real, imaginary);
	real--;
	imaginary--;
	return result;
}

Complex Complex::operator+=(Complex complex)
{
	real += complex.real;
	imaginary += complex.imaginary;
	return *this;
}

Complex Complex::operator-=(Complex complex)
{
	real -= complex.real;
	imaginary -= complex.imaginary;
	return *this;
}
#endif