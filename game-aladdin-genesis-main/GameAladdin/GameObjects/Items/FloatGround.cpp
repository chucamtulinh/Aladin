#include "FloatGround.h"



FloatGround::FloatGround(int type) : GameObject(GameObject::GameObjectType::FloatGround, false)
{
	RECT floatGroundSourceRect;
	floatGroundSourceRect.left = 1;
	floatGroundSourceRect.right = 1; //+40
	floatGroundSourceRect.top = 41;
	floatGroundSourceRect.bottom = 25; //+24

	_animationRubby = new Animation(ResourceManager::GetInstance()->GetAnimationXMLFloatGround(), "Odd", ResourceManager::GetInstance()->GetTextureFloatGround(), true, 0.8f);
	if (type == 1) _animationRubby->SetCurrentIndex(10);
	_width = _animationRubby->GetWidth();
	_height = _animationRubby->GetHeight();
}


FloatGround::~FloatGround()
{
	delete _appleSprite;
	delete _animationSprite, _animationRubby;
}

void FloatGround::Update(float dt)
{
	GameObject::Update(dt);
	_animationRubby->Update(dt);
	if (_animationRubby->GetCurrentIndex() >= 3 && _animationRubby->GetCurrentIndex() <= 11) this->SetIsCollidable(true);
	else this->SetIsCollidable(false);
}

void FloatGround::Draw(Camera * camera)
{
	_animationRubby->SetPosition(_position);
	_animationRubby->Draw(camera);
}

void FloatGround::OnCollision(Player * target, GameCollision::SideCollisions side)
{
}