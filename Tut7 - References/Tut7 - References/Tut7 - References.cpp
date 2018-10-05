// Tut7 - References.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <array>

using namespace std;

//void swap(int x, int y) {
//	int temp = x;
//	x = y;
//	y = temp;
//}

void swap(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;
}

void swap(int& x, int& y);

void swap_ref(int& x, int& y) {
	int temp = x;
	x = y;
	y = temp;
}

int rando_swap(int& x, int& y) {
	x = y;
	return x;
}

//Task 5
int nums[10] = { 7,3,5,2,1,4,6,9,10,8 };

//Bubble sort
void sortArr(int *arr) {
	for (int j = 0; j < 9; j++) {
		for (int i = 0; i < 9; i++) {
			if (arr[i] > arr[i + 1]) {
				swap_ref(arr[i], arr[i + 1]);
			}
		}
	}
}

const int arrSize = 7;
int numz[arrSize] = { 5, 4, 100, 1, 2, 20, 6 };

//Merge Sort
void mergSortArr(int *arr, int arrSize) {
	//If the array is bigger than 2
	if (arrSize > 1) {
		//init the new array and sizes
		int leftSize = (int)ceil((float)arrSize / 2);
		int rightSize = (int)floor((float)arrSize / 2);
		int *left = new int[leftSize];
		int *right= new int[rightSize];

		//Populate the new arrays
		for (int i = 0; i < arrSize; i++) {
			if (i < leftSize) {
				left[i] = arr[i];
			}
			else {
				right[i - leftSize] = arr[i];
			}
		}

		//If the new arrays are bigger than 2 send them up again
		if (leftSize >= 2) {
			mergSortArr(left, leftSize);
		}
		if (rightSize >= 2) {
			mergSortArr(right, rightSize);
		}

		//Sort em up
		int a = 0, b = 0;
		for (int i = 0; i < arrSize; i++) {
			if (a == leftSize) {
				arr[i] = right[b++];
			}
			else if (b == rightSize) {
				arr[i] = left[a]++;
			}
			else if (left[a] <= right[b]) {
				arr[i] = left[a++];
			} 
			else if (left[a] > right[b]) {
				arr[i] = right[b++];
			}
		}

		//clean up
		delete left;
		delete right;
	}
}

int main() {

	//Task 2
	int x = 3, y = 4;
	int& x_ref = x;
	x_ref = y;

	//Task 4
	int k = 2, j = 5;
	cout << "Before swap: " << k << " " << j << endl;
	swap(k, j);
	cout << "After swap: " << k << " " << j << endl;

	//Task 5
	cout << "Before bubble sort: ";
	for (int i = 0; i < 10; i++) {
		cout << nums[i] << " "; }
	
	sortArr(nums);

	cout << "\nAfter bubble sort: ";
	for (int i = 0; i < 10; i++) {
		cout << nums[i] << " ";	}

	//Task 5 with merge sort
	mergSortArr(numz, arrSize);

	cout << "\nMerg Sort Shizz: ";
	for (int i = 0; i < arrSize; i++) {
		cout << numz[i] << " ";
	}

	int a, b;

	cout << "\nPlease type in a number" << "\n";
	cin >> a;
	cout << "Please type in another number" << "\n";
	cin >> b;

	cout << "before swap, a = " << a << " and b = " << b << "\n";
	swap(a, b);
	cout << "after swap (by value), a = " << a << " and b = " << b << "\n";
	swap(&a, &b);
	cout << "after swap by pointer reference, a = " << a << " and b = " << b << "\n";

	swap_ref(a, b);
	cout << "after swap using references, a = " << a << " and b = " << b << "\n";

	int& a_ref = a;

	return 0;
}

/*	Task 1
	A refrence must always be assigned to some value and when they are initlaised it must point to a variable of the same type.
	int a;
	int& a_ref = a;
*/

/*	Task 2
	1 int x = 3, x = 4;
	2 int& x_ref = x;
	3 x_ref = y;

	On line 1 we initialise x and y to be 3 and 4 respectivly. After that we initialise the reference x_ref to be equal to the integer x. This means it's value and memory address are the
	same as the variable x. After we tell x_ref to be equal to integer y which causes the value to change to 4 but the memory location stays the same.
*/

/*	Task 3
	You never want to reference a local veriable in a function because when that function call ends all of it's local variables will be cleaned up and deleted and the reference will 
	still point to that old memory address which could be changed in the future.
*/

//Task 4
void swap(int& x, int& y) {
	int tmp = x;
	x = y;
	y = tmp;
}