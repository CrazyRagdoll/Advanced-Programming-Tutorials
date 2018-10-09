#include "stdafx.h"
#include "Boss.h"


Boss::Boss(int hps, int ammo, int armour) :
	ArmedEnemy(hps, ammo),
	armour_level(armour) {
}

Boss::~Boss()
{
}

int Boss::get_armour_level() {
	return armour_level;
}

void Boss::set_armour_level(int armour) {
	armour_level = armour;
}