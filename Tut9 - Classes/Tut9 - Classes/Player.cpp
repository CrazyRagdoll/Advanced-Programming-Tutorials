#include "stdafx.h"
#include "Player.h"


Player::Player(int hps) :
	hit_points(hps),
	score(new int(0)),
	name(new string("")){
}

Player::~Player() {
	delete score;
	delete name; //Task 2
}

int Player::get_hit_points() const {
	return hit_points;
}

int Player::get_score() const {
	return *score;
}

//Task 2
string Player::get_name() const {
	return *name;
}

void Player::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}

void Player::set_score(const int new_score) {
	*score = new_score;
}

//Task 2
void Player::set_name(string new_name) {
	*name = new_name;
}