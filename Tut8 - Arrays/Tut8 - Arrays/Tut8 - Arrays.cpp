// Tut8 - Arrays.cpp : Defines the entry point for the console application.
//

//#include "stdafx.h"
#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

float calc_avg(const int* arr, const int val) {
	int sum = 0;

	for (int i = 0; i < val; ++i)
		sum += arr[i];

	return (sum / (float)val);
}

float calc_avg(const int* arr, const int val);

//Task 1
int nameLen = 12;
char myName[] = { 'S', 'a', 'm', 'u', 'e', 'l', ' ', 'B', 'o', 'w', 'e', 'n' };

void printName() {
	for (char& e : myName) {
		cout << e;
	}
	cout << endl;
}

//Task 2
char* first = new char[6];
char* last = new char[5];

void addName() {
	int count = 0;
	bool firstName = true;
	for (int i = 0; i < 12; i++) {
		if (myName[i] == ' ') {
			firstName = false;
			count++; break;
		}
		if (firstName) {
			first[i] = myName[i];
		}
		else {
			last[i - count] = myName[i];
		}
		count++;
	}
}

//Task 3
bool ocean[5][5];
int guesses = 0, badGuesses = 0;

//A function to handle the player's input and guess count
void inputGuess() {
	bool inBounds = false;
	string guess;
	int x, y;
	cout << "Guess which tile the ship is on (!!in format x,y!!): ";
	while (!inBounds) {
		cin >> guess;
		x = guess[0]; y = guess[2];
		if ((0 <= x < 5) && (0 <= y < 5)) { inBounds = true; }
		else {
			cout << "Out of bounds! Guess again (x,y): ";
		}
	}
	if (!processGuess(x, y)) { badGuesses++; };
}

//Process the player's guess
bool processGuess(int xCoord, int yCoord) {

	return false;
}


//Some function to allow the player to enter their ship location
void enterShipLocation() {
	//Hard coded ship for now
	ocean[3][1] = true;
	ocean[3][2] = true;
	ocean[3][3] = true;
	/*Ocean layout, ship is marked with X. 3 'tiles' in size for now
		O O O O O
		O O O X O
		O O O X O
		O O O X O
		O O O O O
	*/
}

int main(void) {
	
	//Task 1
	printName();

	//Task 2
	//first[0] = myName[0]; first[1] = myName[1]; first[2] = myName[2]; first[3] = myName[3]; first[4] = myName[4]; first[5] = myName[5];
	//first[7] = myName[7]; first[8] = myName[8]; first[9] = myName[9]; first[10] = myName[10]; first[11] = myName[11];
	addName();
	printName();

	//Task 3
	enterShipLocation();

	inputGuess();







	const int CONST_VALUE = 3;
	float ave;

	// stack based 1-d arrays
	int array_nums[CONST_VALUE] = { 2, 4, 5 };

	// print out the first element
	cout << "value at index 0 is " << array_nums[0] << "\n";

	//stack based 2-d arrays
	char naughts_n_xs[3][3];

	// set the middle square to x
	naughts_n_xs[1][1] = 'X';

	//arrays on the heap 1-d
	int* sum = new int[CONST_VALUE];

	for (int i = 0; i < CONST_VALUE; ++i)
	{
		cout << "enter a value...\n";
		cin >> sum[i];
	}

	ave = calc_avg(sum, CONST_VALUE);

	cout << "the average is " << ave << "\n";

	delete[] sum;

	return 0;
}
