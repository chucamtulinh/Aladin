#pragma once

#include "../GameObject.h"
#include "../Player/Player.h"
#include "../../GameComponents/Sprite.h"
#include "../../GameComponents/Animation.h"

class Ball : public GameObject
{
private:
	Sprite * _spikeSprite;
	Animation *_animationSprite;
public:
	Ball(int type);
	~Ball();

	void Draw(Camera* camera);
	void Update(float dt);

	void OnCollision(Player *target, GameCollision::SideCollisions side);
};

