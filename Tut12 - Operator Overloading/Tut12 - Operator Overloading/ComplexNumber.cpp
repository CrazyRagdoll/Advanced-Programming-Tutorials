#include "stdafx.h"
#include "ComplexNumber.h"


ComplexNumber::ComplexNumber(int x, int y) :
	real(x),
	imaginary(y)
{
}


ComplexNumber::~ComplexNumber()
{
}

ostream& operator<<(ostream& ostr, const ComplexNumber& cNum) {
	ostr << "(" << cNum.real << "," << cNum.imaginary << "i)";
	return ostr;
}

ComplexNumber operator+(const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber result;
	result.real = a.real + b.real;
	result.imaginary = a.imaginary + b.imaginary;
	return result;
}

ComplexNumber& operator+=(const ComplexNumber& rhs, int x) {

}

ComplexNumber operator-(const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber result;
	result.real = a.real - b.real;
	result.imaginary = a.imaginary - b.imaginary;
	return result;
}

ComplexNumber operator*(const ComplexNumber& a, const ComplexNumber& b) {
	ComplexNumber result;
	result.real = (a.real * b.real) - (a.imaginary * b.imaginary);
	result.imaginary = (a.real * b.imaginary) + (a.imaginary * b.real);
	return result;
}

bool operator==(const ComplexNumber& a, const ComplexNumber& b) {
	if ((a.real == b.real) && (a.imaginary == b.imaginary)) return true;
	return false;
}

bool operator!=(const ComplexNumber& a, const ComplexNumber& b) {
	if ((a.real == b.real) || (a.imaginary == b.imaginary)) return false;
	return true;
}