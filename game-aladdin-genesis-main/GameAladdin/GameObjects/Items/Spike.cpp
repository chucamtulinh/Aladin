#include "Spike.h"
#include "../../GameComponents/Sound.h"



Spike::Spike(int type) : GameObject(GameObject::GameObjectType::Spike, false)
{
	RECT spikeRect;
	spikeRect.left = 1;
	spikeRect.right = 50;//+49
	spikeRect.top = 1;
	spikeRect.bottom = 36;//+35

	_animationSprite = new Animation(ResourceManager::GetInstance()->GetAnimationXMLSpike(), "ani", ResourceManager::GetInstance()->GetTextureSpike(), true, 0.3f);
	//dùng type để set index animation
	if (type == 0) _animationSprite->SetCurrentIndex(10);

	_width = _animationSprite->GetWidth();
	_height = _animationSprite->GetHeight();
}


Spike::~Spike()
{
	delete _animationSprite;
}

void Spike::Update(float dt) {
	GameObject::Update(dt);
	_animationSprite->Update(dt);
	if(_animationSprite->GetCurrentIndex() == 3 && this->_isInCamera)Sound::GetInstance()->Play("Wall_Spikes", 0, 1);
	//xét index để có va chạm
	if (_animationSprite->GetCurrentIndex() >= 2 && _animationSprite->GetCurrentIndex() <= 9) {
		this->SetIsCollidable(true);
	}
	else this->SetIsCollidable(false);

}

void Spike::Draw(Camera * camera) {
	_animationSprite->SetPosition(_position);
	_animationSprite->Draw(camera);
}

void Spike::OnCollision(Player* target, GameCollision::SideCollisions side) {

}
