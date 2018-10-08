// Tut8 - Arrays.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
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

void printName(char name[], int len) {
	for (int i = 0; i < len; i++) {
		cout << name[i];
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
			count++;
		} else if (firstName) {
			first[i] = myName[i];
			count++;
		} else {
			last[i - count] = myName[i];
		}
	}
}

//Task 3
bool grid[5][5], shipAlive = true;
int guesses = 0, misses = 0;

//A function to handle the player's input and guess count
void inputGuess();

//Process the player's guess
bool processGuess(int xCoord, int yCoord);

//Some function to allow the player to enter their ship location
void enterShipLocation();

//Check if there is still a ship on the grid
bool checkGrid();

//Print dat grid
void printGrid();

int main(void) {
	
	//Task 1
	printName();

	//Task 2
	addName();
	printName(first, 6);
	printName(last, 5);

	//Task 3
	enterShipLocation();
	while (shipAlive = checkGrid()) {
		inputGuess();
		printGrid();
	 }

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

//Task 3 functions

void inputGuess() {
	bool inBounds = false;
	int x, y;

	cout << "Please enter an x and y value from 0 to 4!\n";
	//Check to make sure they input the correct values
	while (!inBounds) {
		//promt the user to enter a location on the grid
		cout << "x: ";
		cin >> x;
		cout << "y: ";
		cin >> y;
		if ((x < 5 && x >= 0) && (y < 5 && y >= 0)) {
			inBounds = true;
		}
		else {
			cout << "Please enter values inside the play field!\n";
		}
	}

	//increment guesses and process the guess
	guesses++;
	if (!processGuess(x, y)) { misses++; };
	cout << "Guesses: " << guesses << "! Hits: " << guesses - misses << endl;
}

bool processGuess(int xCoord, int yCoord) {
	//Check if the guess is a hit
	if (grid[xCoord][yCoord] == true) {
		grid[xCoord][yCoord] = false;
		cout << "Hit!\n";
		return true;
	}
	else {
		cout << "Miss!\n";
		return false;
	}
}

//Some function to allow the player to enter their ship location
void enterShipLocation() {
	//Hard coded ship for now
	grid[3][1] = true;
	grid[3][2] = true;
	grid[3][3] = true;
	/*Ocean layout, ship is marked with X. 3 'tiles' in size for now
	O O O O O
	O O O X O
	O O O X O
	O O O X O
	O O O O O
	*/
}

//Checks to see if there is still ships on the field
bool checkGrid() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[i][j] == true) { return true; }
		}
	}
	cout << "You win! It took a total of " << guesses << " gueses! With " << misses << " misses!";
	return false;
}

//print where the ships are on the grid
void printGrid() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[j][i] == true) { cout << "X "; }
			else { cout << "O "; }
		}
		cout << endl;
	}
}