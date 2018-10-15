#include "stdafx.h"
#include "ArmedEnemy.h"

#include <iostream>
using namespace std;

// define flying enemy class

ArmedEnemy::ArmedEnemy(int hps, int ammo) :
	Enemy(hps),
	ammo_level(ammo) {
}

ArmedEnemy::~ArmedEnemy() {
}

void ArmedEnemy::set_score(const int new_score) {
	*score = new_score;
	cout << "score is now " << *score << "\n";
}

void ArmedEnemy::shoot() {
	if (ammo_level > 0)
	{
		cout << "bang!\n";
		--ammo_level;
	}
	else
	{
		cout << "out of ammo\n";
	}
}

//Tutorial 12 task 1
ostream& operator<<(ostream& ostr, const ArmedEnemy& enm) {
	ostr << "Armed Enemy Reporting!\nI am worth " << enm.get_score() << " points! I have " << enm.get_hit_points() << " hit points & my ammo level is " << enm.ammo_level << "!\n";
	return ostr;
}