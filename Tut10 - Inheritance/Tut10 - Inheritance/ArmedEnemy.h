#pragma once

#include "Enemy.h"
#include <iostream>

using namespace std;

// declare flying enemy class

class ArmedEnemy : public Enemy
{
public:
	ArmedEnemy(int hps, int ammo);
	virtual ~ArmedEnemy();
	virtual void set_score(const int new_score);
	virtual void shoot();

	friend ostream& operator<<(ostream& ostr, const ArmedEnemy& enm);

protected:
	int ammo_level;
};
