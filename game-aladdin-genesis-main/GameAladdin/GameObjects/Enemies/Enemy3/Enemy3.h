#pragma once

#include "../Enemy.h"

class Enemy3 : public Enemy
{
private:
	bool _entryDead;
public:
	Enemy3();
	Enemy3(GameObject * player);
	void Update(float deltaTime);
	~Enemy3();

	//void Update(float deltaTime);
};