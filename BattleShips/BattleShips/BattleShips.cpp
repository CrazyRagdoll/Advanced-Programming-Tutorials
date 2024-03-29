#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

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

int main()
{
	//Task 3
	enterShipLocation();

	while (shipAlive = checkGrid()) {
		inputGuess();
		printGrid();
	}
}

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