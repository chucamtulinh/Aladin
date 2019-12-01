#pragma once
#include "../GameObjects/Camera.h"
#include "../GameComponents/Animation.h"
#include "../GameComponents/Text.h"
#include "../GameComponents/Scene.h"


class CompleteScene :public Scene
{

	Text* _title;
	Animation *_animationAladdin;
	Animation *_animationMonkey;
	Sprite *_bg;
public:
	CompleteScene();
	~CompleteScene();

	void LoadContent();
	void Update(float deltatime);
	void Draw();
};