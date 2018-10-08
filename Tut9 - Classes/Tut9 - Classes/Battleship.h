#pragma once

class Battleship
{
public:
	Battleship();
	~Battleship();

	void generateShips();
	void inputGuess();
	bool processGuess(int xCoord, int yCoord);
	bool checkGrid();
	void printGrid();

private:
	bool grid[5][5];
	int hitPoints, score, guesses, misses;

};

