// Tut4 - Pointers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

//Task 3
void swap(int* a, int* b) {

	int temp = *a;
	*a = *b;
	*b = temp;
}

//Task 4 
void printPointy(int* a) {

	for (int i = 0; i < 10; i++)
	{
		if ((*a+i) % 2 == 0)
			cout << "Address #" << a+i << " with value " << *a+i << " is even." << endl;
	}
}


int main() {

	//Task 2
	float z = 100;

	float* zA = &z;

	zA += 3;

	//Task 3
	int fi = 1, fo = 2;
	int *hi = &fi, *ho = &fo;

	cout << "Before " << "fi: " << fi << " fo: " << fo << endl;

	swap(hi, ho);

	cout << "After " << "fi: " << fi << " fo: " << fo << endl;

	//Task 4
	int arr[10] = { 1,2,3,4,5,6,7,8,9,10 };

	int* arrPoint = &arr[0];

	printPointy(arrPoint);

	//stuff
	int cont;
	cout << "Enter a number to contiune: \n";
	cin >> cont;

	int a = 100;

	cout << "Value in memory location a is " << a << "\n";

	cout << "Address of (the reference to) memory location a is " << &a << "\n";

	int *b = &a;

	cout << "Value in memory location pointed to by b is " << *b << "\n";


	cout << "Value in memory location b is " << b << "\n";
	cout << b << " should be the same as the memory location for a: " << &a << "\n";
	cout << "b is actually at memory location " << &b << endl;

	int** c;

	c = &b;
	cout << "c is now pointing to what b points to: " << **c << endl;

	cout << "c points to: " << *c << endl;

	cout << "c actually holds the value: " << c << endl;
	cout << c << " is the same value as b's memory location: " << &b << endl;
	cout << "c is actually at memory location " << &c << endl;

	cout << "c is eventually retrieving what is in memory location " << **&c << endl;
	cout << "the value of a is in memory location " << &a << endl;

	int x;
	cout << "Type in a numebr to finish" << "\n";
	cin >> x;

	return 0;
}

/*  Task 1
	Each memory address is designated a number to represent its location in the memory. Just like with integers you can add numbers to it to changes its value, with a pointer pointing to a 
	memory address we could add 1 to it to see the next memory address along. It can't be a double because you can't for example have half a memory location.
*/

/*  Task 2
	As float data types are 4 bytes long when they are given a memory addres, 100 for example, it will take up 4 bytes of memory is succession, 100, 101, 102, 103. 
	If we were to add 3 to the memory address value 100 then it will move 3 sets of 4bytes of memory along to position 112.
*/