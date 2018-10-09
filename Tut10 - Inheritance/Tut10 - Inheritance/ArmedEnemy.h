#pragma once

#include "Enemy.h"

// declare flying enemy class

class ArmedEnemy : public Enemy
{
public:
	ArmedEnemy(int hps, int ammo);
	virtual ~ArmedEnemy();
	virtual void set_score(const int new_score);
	virtual void shoot();

protected:
	int ammo_level;
};
