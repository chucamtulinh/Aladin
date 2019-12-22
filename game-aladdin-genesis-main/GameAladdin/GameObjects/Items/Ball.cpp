#include "Ball.h"



Ball::Ball(int type):GameObject(GameObject::GameObjectType::Ball, false)
{
	RECT spikeRect;
	spikeRect.left = 1;
	spikeRect.right = 50;//+49
	spikeRect.top = 1;
	spikeRect.bottom = 36;//+35

	_animationSprite = new Animation(ResourceManager::GetInstance()->GetAnimationXMLBall(), "ani", ResourceManager::GetInstance()->GetTextureBall(), true, 0.3f);
	//dùng type để set index animation
	if (type == 0) _animationSprite->SetCurrentIndex(10);

	_width = _animationSprite->GetWidth();
	_height = _animationSprite->GetHeight();
}


Ball::~Ball()
{
	delete _animationSprite;
}

void Ball::Update(float dt) {
	GameObject::Update(dt);
	_animationSprite->Update(dt);
	//xét index để có va chạm
	if (_animationSprite->GetCurrentIndex() >= 8 && _animationSprite->GetCurrentIndex() <= 20) {
		this->SetIsCollidable(true);
	}
	else this->SetIsCollidable(false);

}

void Ball::Draw(Camera * camera) {
	_animationSprite->SetPosition(_position);
	_animationSprite->Draw(camera);
}

void Ball::OnCollision(Player* target, GameCollision::SideCollisions side) {

}
