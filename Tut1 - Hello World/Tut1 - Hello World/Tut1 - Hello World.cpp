// Tut1 - Hello World.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include "pch.h"

#include <iostream>
#include <string>

using namespace std;

int main() {

	cout << "Hello" << ' ' << "World" << "\n";
	std::cout << "What is 7 + 2?" << "\n";
	int x;
	cin >> x;

	//Task 2
	char myChar = 'a';
	bool myBool = true;
	double myDub = 12.34;

	cout << "My char: " << myChar << "\nMy boolean: " << myBool << "\nMy double: " << myDub << "\n";

	//Task 3
	int y, z;

	cout << "Please enter a #";
	cin >> y;
	cout << "Please enter a #";
	cin >> z;

	cout << "The sum of " << y << " + " << z << " = " << y + z << "\n";
	cout << "The product of " << y << " * " << z << " = " << y * z << "\n";

	//Task 4
	string name;

	cout << "Please enter your name: ";
	cin >> name;

	cout << "Hello " << name << "!\n";


	return 0;
}

/*	Task 1
	An unsigned integer can only hold positive integers e.g 1,2,3,10 where as a signed integer can have positive and negative. Both unsigned and signed integers are assigned the same amount
	of memory when declared, but as the unsigned does not have to include negative numbers its maximum value is almost double that of the signed int.
	Unsigned 0 to 65535
	Signed -32768 to 32767

	Unsigned ints are useful for values that can not go bellow 0 such as height or weight.
*/

