#pragma once

#include "D:/New folder/Aladin/game-aladdin-genesis-main/GameAladdin/GameObjects/Enemies/Enemy.h"

class Bat : public Enemy
{
private:
	//used to check when injured
	int _prevHealth;
public:
	Bat();
	Bat(GameObject * player);
	~Bat();

	void Update(float deltaTime);
};