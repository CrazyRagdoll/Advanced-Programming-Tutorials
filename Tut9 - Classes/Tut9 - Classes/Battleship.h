#pragma once

class Battleship
{
public:
	Battleship();
	~Battleship();

	void generateShips();
	void inputGuess();
	bool processGuess(int xCoord, int yCoord);
	bool checkScore();
	bool checkGrid();
	void printGrid();

	//Getters
	int getHP() const { return hitPoints; }
	int getScore() const { return score; }
	int getGuesses() const { return guesses; }

private:
	bool grid[5][5];
	int hitPoints, score, guesses;

};

