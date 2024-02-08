#include "Complex.h"

#include <iostream>
using namespace std;

Complex::Complex()
{
	real = 0;
	imag = 0;
}

Complex::Complex(float r, float i)
{
	SetReal(r);
	SetImag(i);

	cout << "This complex is consturcted --> ";
	Print();
}

void Complex::SetReal(float r)
{
	real = r;
}

void Complex::SetImag(float i)
{
	imag = i;
}

float Complex::GetReal() const
{
	return real;
}

float Complex::GetImage() const
{
	return imag;
}

void Complex::ReadInfo()
{
	float r, i;
	cout << "Enter real: ";
	cin >> r;
	cout << "Enter imag: ";
	cin >> i;

	SetReal(r);
	SetImag(i);
}

void Complex::Print() const
{
	cout << "Complex = " << real << " + (" << imag << ") i" << endl;
}

Complex::~Complex()
{
	cout << "This complex is DESturcted --> ";
	Print();
}
