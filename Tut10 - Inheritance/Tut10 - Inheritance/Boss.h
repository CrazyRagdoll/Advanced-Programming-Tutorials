#pragma once

#include "ArmedEnemy.h"

class Boss : public ArmedEnemy
{
public:
	Boss(int hps, int ammo, int armour);
	~Boss();

	int get_armour_level();
	void set_armour_level(int armour);

protected:
	int armour_level;
};

