// Tut3 - Program Flow.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

int add(int x, int y) {
	return x + y;
}

int fac(int x) {

	int facSum = 1;

	for (int count = x; count > 0; count--)
		facSum = facSum * count;

	return facSum;
}

//Task 1
bool isPos(int x) {

	if (x >= 0)
		return true;
	return false;
}

//Task 2
void gimiNeg() {

	int x = 0;
	
	while (isPos(x)) {
		cout << "Enter a number: ";
		cin >> x;
	}

	cout << "Negitive number detected!! Exiting function beep boop. \n";
}

//Task 3
int recursionFac(int x) {

	if (x > 0) {
		return x * recursionFac(x - 1);
	}
	return 1;

}
//Advantages - more intuitive, lets the programmer visualise the problem better and make it more understandable
//Disadvantages - usually much slower due to all the functions calls being stored on the stack to allow them to return back to the caller function

int main() {

	//Task 1
	int y = 0;
	cout << "Enter a number: ";
	cin >> y;

	bool test = isPos(y);
	if (test) cout << y << " is in fact positive! \n";
	else cout << y << " is actually negitive! \n";

	//Task 2
	gimiNeg();

	//Task 3
	int facSum = recursionFac(5);

	int total = 0;

	int x;

	cout << "Please enter numbers, will finish if sum of factorals exceeds 2000" << "\n";

	while (total <= 2000) {
		cin >> x;
		total = add(fac(x), total);
	}

	cout << "The total is " << total << "\n";

	if (total > 3000)
		cout << "you overshot by a lot!" << "\n";
	else {
		cout << "You just went over" << "\n";
		cout << "Only over by " << total - 2000 << "\n";
	}

	cout << "enter a number to exit" << "\n";

	cin >> x;

	return 0;
}
