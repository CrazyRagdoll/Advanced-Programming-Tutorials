#include "stdafx.h"
#include "ArmedEnemy.h"

void ArmedEnemy::set_score(const int new_score) {
	*score = new_score;
	//cout << "score is now " << *score << "\n";
}

ArmedEnemy::ArmedEnemy(const ArmedEnemy& src) :
	Enemy(src),
	ammo_level(src.ammo_level)
{
}

//ArmedEnemy& ArmedEnemy::operator=(const ArmedEnemy& rhs)
//{
//	if (this == &rhs) {
//		return (*this);
//	}
//	//free old memory
//	delete score;
//
//	//copy new memory
//	ammo_level = rhs.ammo_level;
//
//	return *this;
//}


/**
* shoot method
*/
void ArmedEnemy::shoot() {
	if (ammo_level > 0) {
		cout << "bang!\n";
		--ammo_level;
	}
	else {
		cout << "out of ammo\n";
	}
}