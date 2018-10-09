#include "stdafx.h"
#include "Battleship.h"

#include <iostream>
#include <time.h>
using namespace std;


Battleship::Battleship() :
	hitPoints(3), score(0), guesses(0) {
	generateShips();
}


Battleship::~Battleship()
{
}

//Simple function to make sure the randomly generated ship is inside the grid
int inGrid(int root, int x) {
	if ((root + x) > 4) { return 0; }
	else if ((root + x) < 0) { return 4; }
	else { return root + x; }
}

void Battleship::generateShips() {
	////Hard coded ship for now
	//grid[3][1] = true;
	//grid[3][2] = true;
	//grid[3][3] = true;

	srand(time(NULL));

	//Randomly generate ship position and orientation
	int rootX, rootY, frontX, frontY, backX, backY, ori;
	rootX = rand() % 5; rootY = rand() % 5;

	//Generate which orientation it'll be 
	ori = rand() % 4;

	//depending on which number was generated decide which way to face the ship
	switch (ori) {
	case 0: frontX = inGrid(rootX, +1); frontY = rootY; backX = inGrid(rootX, -1); backY = rootY; break;
	case 1: frontX = rootX; frontY = inGrid(rootY, +1); backX = rootX; backY = inGrid(rootY, -1); break;
	case 2: frontX = inGrid(rootX, +1); frontY = inGrid(rootY, +1); backX = inGrid(rootX, -1); backY = inGrid(rootY, -1); break;
	case 3: frontX = inGrid(rootX, -1); frontY = inGrid(rootY, +1); backX = inGrid(rootX, +1); backY = inGrid(rootY, -1); break;
	}

	//code in the new ship position
	grid[frontX][frontY] = true;
	grid[rootX][rootY] = true;
	grid[backX][backY] = true;
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
	//If it's a hit, increase score
	if (processGuess(x, y)) { score++; }
	cout << "Guesses: " << guesses << "! Hits: " << score << endl;

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

//Simple check to see if the score is equal to the hp (the game is over)
bool Battleship::checkScore() {
	if (score >= hitPoints) {
		cout << "You win! It took a total of " << guesses << " gueses! With " << guesses - score << " misses!";
		return true;
	}
	else {
		return false;
	}
}

//Previous checker to see if there were any ships left
bool Battleship::checkGrid() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[i][j] == true) { return true; }
		}
	}
	cout << "You win! It took a total of " << guesses << " gueses! With " << guesses - score << " misses!";
	return false;
}

//Simple function to print the layout of the grid with ships
void Battleship::printGrid() {
	for (int i = 0; i < 5; i++) {
		for (int j = 0; j < 5; j++) {
			if (grid[j][i] == true) { cout << "X "; }
			else { cout << "O "; }
		}
		cout << endl;
	}
}