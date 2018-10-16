#pragma once

#include "Enemy.h"

class ArmedEnemy : public Enemy {
public:
	static const int default_ammo = 8;
	ArmedEnemy() :Enemy(), ammo_level(default_ammo) {}
	ArmedEnemy(int hps, int ammo) :Enemy(hps), ammo_level(ammo) {}
	ArmedEnemy(const ArmedEnemy& src);
	//ArmedEnemy& operator=(const ArmedEnemy& rhs);
	virtual ~ArmedEnemy() {}
	virtual void set_score(const int new_score);
	virtual void shoot();
	int get_ammo() { return ammo_level; }

protected:
	int ammo_level;
};
