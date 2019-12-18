#pragma once

#include "../Weapon.h"

class Enemy4Weapon : public Weapon
{
public:
	Enemy4Weapon(int damage = 10);
	~Enemy4Weapon();

	void OnCollision(GameObject *target, GameCollision::SideCollisions side);
};

