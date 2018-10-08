#include "stdafx.h"
#include "Battleship.h"

#include <iostream>
using namespace std;


Battleship::Battleship() :
	hitPoints(3), score(0), guesses(0), misses(0) {
	generateShips();
}


Battleship::~Battleship()
{
}

void Battleship::generateShips() {
	//Hard coded ship for now
	grid[3][1] = true;
	grid[3][2] = true;
	grid[3][3] = true;

}

void Battleship::inputGuess() {
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

bool Battleship::processGuess(int xCoord, int yCoord) {
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

bool Battleship::checkGrid() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[i][j] == true) { return true; }
		}
	}
	cout << "You win! It took a total of " << guesses << " gueses! With " << misses << " misses!";
	return false;
}

void Battleship::printGrid() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[j][i] == true) { cout << "X "; }
			else { cout << "O "; }
		}
		cout << endl;
	}
}