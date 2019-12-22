#include "Enemy3.h"
#include "Enemy3IdleState.h"
#include "Enemy3Dead.h"

Enemy3::Enemy3()
{
	// not use
}

Enemy3::Enemy3(GameObject * player):Enemy(player)
{
	_state = new Enemy3IdleState(this);
	_attackRangeX = 100;
	_entryDead = false;
	_speed = 20;
	_viewRangeX = 170;
	_viewRangeY = 120;
	//_acceleration.y = 80;
}


Enemy3::~Enemy3()
{
}

void Enemy3::Update(float deltaTime)
{
	_animationSprite->Update(deltaTime);

	// calculate distance to target (player)
	_distanceToTarget = _target->GetPosition() - _position;

	//check isDie
	if (_health <= 0)
	{
		_isDead = true;
		//_isVisible = false;
	}

	//face to left or right
	if (_distanceToTarget.x > 0)
		_isRight = true;
	else if (_distanceToTarget.x < 0)
		_isRight = false;

	//move
	if (IsTargetInViewRange())
	{
		if (_distanceToTarget.x - 70 > 0 && _isMovableObject && _allowMoveLeft)
		{
			//move right		
			_velocity.x = _speed;
		}
		else if (_distanceToTarget.x + 70 < 0 && _isMovableObject && _allowMoveRight)
		{
			//move left
			_velocity.x = -1 * _speed;
		}
		else
		{
			//_velocity.x = 0;
		}

		if (_distanceToTarget.y - 50 > 0 && _isMovableObject && _allowMoveRight)
		{
			//move right
			_velocity.y = _speed;
		}
		else if (_distanceToTarget.y + 50 < 0 && _isMovableObject && _allowMoveLeft)
		{
			//move left
			_velocity.y = -1 * _speed;
		}
		else
		{
			//_velocity.y = 0;
		}
	}
	
	GameObject::Update(deltaTime);

	if (_isInCamera || _allowUpdateWhenNotInCamera)
		_state->Update(deltaTime);

	//fix foot posY
	//_position.y = _footPosY - _height / 2;
}

