// Tut2 - Functions.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int add(int x, int y) {

	return x + y;
}

int minus(int x, int y);

void product(int x, int y); //task 1

double quotient(double x, int y); //task 2

void calc(double x, double y, char op); //task 3

int main() {

	int a, b, c, exit;

	cout << "Please type in a number" << "\n";
	cin >> a;

	cout << "Please type in another number" << "\n";
	cin >> b;

	c = add(a, b);

	cout << a << '+' << b << '=' << c << "\n";

	//Task 1 output
	product(1, 2);

	//Task 2 output
	double quot = quotient(5, 3);

	//Task 3 output
	calc(2, 3, '-');

	cout << "enter another number to exit" << "\n";

	cin >> exit;

	return 0;
}

int minus(int x, int y) {

	return x - y;
}

//Task 1
void product(int x, int y) {
	cout << "Product of " << x << " + " << y << " = " << x + y << endl;
}

//Task 2
double quotient(double x, int y) {
	cout << "The quotient of " << x << " / " << y << " = " << x/y << endl;
	return x/y;
}

//Task 3
void calc(double x, double y, char op) {
	switch (op) {
	case '+': cout << "Product of " << x << " + " << y << " = " << x + y << endl; break;
	case '-': cout << "Product of " << x << " - " << y << " = " << x - y << endl; break;
	case '*': cout << "Product of " << x << " * " << y << " = " << x * y << endl; break;
	case '/': cout << "Product of " << x << " / " << y << " = " << x / y << endl; break;
	default: cout << "Invalid operator" << endl; break;
	}
}
