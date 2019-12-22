#include "Enemy4Weapon.h"



Enemy4Weapon::Enemy4Weapon(int damage) : Weapon(Weapon::WeaponType::EnemiesWeapons, damage)
{
	_animation = new Animation(ResourceManager::GetInstance()->GetAnimationXMLEnemy4(), "Attack", ResourceManager::GetInstance()->GetTextureEnemies4(), true, 0.3f);

	_width = _animation->GetWidth();
	_height = _animation->GetHeight();

	_velocity.x = 20;//left or right
	_velocity.y = -20;

	_mass = 25;
	_acceleration.y = _mass;
}

Enemy4Weapon::~Enemy4Weapon()
{
	delete _animation;
}

void Enemy4Weapon::OnCollision(GameObject * target, GameCollision::SideCollisions side)
{
	//prevent collision with PlayerWeapons
	if (target->GetTag() == GameObjectType::Players)
	{
		this->SetIsVisible(false);
	}
/*
	if (target->GetTag() != GameObject::GameObjectType::Enemies
		&& target->GetTag() != GameObject::GameObjectType::Apple)
	{
		_isVisible = false;
		_acceleration.y = 0;
		_velocity.x = _velocity.y = 0;
	}*/
}
