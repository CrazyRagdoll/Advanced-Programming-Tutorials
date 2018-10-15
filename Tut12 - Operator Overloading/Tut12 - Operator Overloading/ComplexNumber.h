#pragma once

#include <iostream>

using namespace std;

class ComplexNumber
{
public:
	ComplexNumber(int x = default_real, int y = default_imaginary);
	~ComplexNumber();

	void setVals(int x, int y) { real = x; imaginary = y; }

	friend ostream& operator<<(ostream& ostr, const ComplexNumber& mtx);
	friend ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b);
	friend ComplexNumber& operator+=(const ComplexNumber& rhs, int x);
	friend ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b);
	friend ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b);
	friend bool operator==(const ComplexNumber& a, const ComplexNumber& b);
	friend bool operator!=(const ComplexNumber& a, const ComplexNumber& b);

	const static int default_real = 0;
	const static int default_imaginary = 0;

private:
	int real, imaginary;

};

