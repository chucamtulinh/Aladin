#pragma once

#include "D:/New folder/Aladin/game-aladdin-genesis-main/GameAladdin/GameObjects/Enemies//EnemyState.h"

class BatDamageState : public EnemyState
{
public:
	BatDamageState();
	BatDamageState(Enemy* enemy);
	~BatDamageState();

	void Update(float deltaTime);
};
