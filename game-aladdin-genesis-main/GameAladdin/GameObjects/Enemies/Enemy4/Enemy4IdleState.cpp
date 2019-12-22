#include "Enemy4IdleState.h"
#include "Enemy4.h"
#include "../../Weapons/EnemiesWeapons/Enemy4Weapon.h"
#include "../../../GameComponents/SceneManager.h"


Enemy4IdleState::Enemy4IdleState()
{
	
	//not use
}

Enemy4IdleState::Enemy4IdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLEnemy4(), "Idle", ResourceManager::GetInstance()->GetTextureEnemies4(), true, 0.7f));
}


Enemy4IdleState::~Enemy4IdleState()
{
}

void Enemy4IdleState::Update(float deltaTime)
{
	EnemyState::Update(deltaTime);

	if (_animation->IsFinish())
	{
		_enemy->SetIsVisible(false);

		Enemy4Weapon* weaponR = new Enemy4Weapon();
		weaponR->SetPosition(_enemy->GetPosition().x, _enemy->GetPosition().y - _enemy->GetHeight() / 2);
		weaponR->SetVelocity(-60, 0);
		SceneManager::GetInstance()->GetCurrentScene()->AddGameObjectToWeaponList(weaponR);

		Enemy4Weapon* weaponL = new Enemy4Weapon();
		weaponL->SetPosition(_enemy->GetPosition().x, _enemy->GetPosition().y - _enemy->GetHeight() / 2);
		
		//set left or right for velocityX
		//weaponL->SetVelocity(_enemy->GetTarget()->GetPosition() - _enemy->GetPosition());
		weaponL->SetVelocity(60,10);
		//add gameobject to update&draw list
		SceneManager::GetInstance()->GetCurrentScene()->AddGameObjectToWeaponList(weaponL);
		
		Enemy4Weapon* weapon3 = new Enemy4Weapon();
		weapon3->SetPosition(_enemy->GetPosition().x, _enemy->GetPosition().y - _enemy->GetHeight() / 2);
		weapon3->SetVelocity(-10, -70);
		SceneManager::GetInstance()->GetCurrentScene()->AddGameObjectToWeaponList(weapon3);

		Enemy4Weapon* weapon4 = new Enemy4Weapon();
		weapon4->SetPosition(_enemy->GetPosition().x, _enemy->GetPosition().y - _enemy->GetHeight() / 2);
		weapon4->SetVelocity(10, -70);
		SceneManager::GetInstance()->GetCurrentScene()->AddGameObjectToWeaponList(weapon4);
		
		//Grid::InsertDynamicObject(weaponR);
		
	}
}
