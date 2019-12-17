#include "Bat.h"

#include "BatIdleState.h"
#include "BatDamageState.h"

Bat::Bat()
{
	// not use
}

Bat::Bat(GameObject * player) :Enemy(player)
{
	_state = new BatIdleState(this);

	_prevHealth = _health;
}


Bat::~Bat()
{
}

void Bat::Update(float deltaTime)
{
	Enemy::Update(deltaTime);

	if (_health < _prevHealth)
	{
		SetState(new BatDamageState(this));
		
	}
	_prevHealth = _health;
}
