#pragma once

#include "../GameObject.h"
#include "../Player/Player.h"
#include "../Player/PlayerFallState.h"
#include "../../GameComponents/Sprite.h"
#include "../../GameComponents/Animation.h"

class FloatGround : public GameObject
{
private:
	Sprite * _appleSprite;
	Animation *_animationSprite;
	Animation *_animationRubby;
public:
	Animation * _animation;
	FloatGround(int type);
	~FloatGround();

	void Draw(Camera* camera);
	void Update(float dt);

	void OnCollision(Player *target, GameCollision::SideCollisions side);
};

