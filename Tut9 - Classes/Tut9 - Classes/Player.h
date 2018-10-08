#pragma once
#include <string>

using namespace std;

class Player
{
public:
	Player(int hps, int score);
	~Player();
	int get_hit_points() const;
	int get_score() const;
	string get_name() const; //Task 2
	void set_hit_points(int new_hit_points);
	void set_score(int new_score);
	void set_name(string new_name); //Task 2

private:
	int hit_points;
	int* score;
	//Task 2
	string* name;
};

