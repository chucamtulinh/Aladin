#pragma once

#include "D:/New folder/Aladin/game-aladdin-genesis-main/GameAladdin/GameObjects/Enemies//EnemyState.h"

class BatIdleState : public EnemyState
{
public:
	BatIdleState();
	BatIdleState(Enemy* enemy);
	~BatIdleState();

	void Update(float deltaTime);
};

