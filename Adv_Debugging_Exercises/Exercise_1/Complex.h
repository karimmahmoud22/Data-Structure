#pragma once
class Complex
{
	float real;
	float imag;

public:
	Complex();

	Complex(float r, float i);

	void SetReal(float r);

	void SetImag(float i);

	float GetReal() const;

	float GetImage() const;

	void ReadInfo();

	void Print() const;
	
	~Complex();
};

