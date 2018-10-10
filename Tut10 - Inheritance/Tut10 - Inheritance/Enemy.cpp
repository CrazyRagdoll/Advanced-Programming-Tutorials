#include "stdafx.h"
#include "Enemy.h"


// define enemy class

Enemy::Enemy(int hps) :
	hit_points(hps) {
	score = new int(0);
}

Enemy::~Enemy() {
	delete score;
}

int Enemy::get_hit_points() const {
	return hit_points;
}

int Enemy::get_score() const {
	return *score;
}

void Enemy::set_hit_points(const int new_hit_points) {
	hit_points = new_hit_points;
}

void Enemy::set_score(const int new_score) {
	*score = new_score;
}

int Enemy::compare_to(const Comparable& rhs){
	if (this > &rhs) {
		return 1;
	}
	else if (this == &rhs) {
		return 0;
	}
	else {
		return -1;
	}
}