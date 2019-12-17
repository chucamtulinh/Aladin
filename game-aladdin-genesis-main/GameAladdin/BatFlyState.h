#pragma once

#include "D:/New folder/Aladin/game-aladdin-genesis-main/GameAladdin/GameObjects/Enemies//EnemyState.h"

class BatFlyState : public EnemyState
{
public:
	BatFlyState();
	BatFlyState(Enemy* enemy);
	~BatFlyState();

	void Update(float deltaTime);
};

