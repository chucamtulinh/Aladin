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
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLEnemy4(), "Idle", ResourceManager::GetInstance()->GetTextureEnemies4(), true, 0.5f));
}


Enemy4IdleState::~Enemy4IdleState()
{
}

void Enemy4IdleState::Update(float deltaTime)
{
	EnemyState::Update(deltaTime);

	if (_animation->IsFinish())
	{


		Enemy4Weapon* weaponL = new Enemy4Weapon();
		weaponL->SetPosition(_enemy->GetPosition().x, _enemy->GetPosition().y - _enemy->GetHeight() / 2);
		
		//set left or right for velocityX
		weaponL->SetVelocity(_enemy->GetTarget()->GetPosition() - _enemy->GetPosition());
	
		//add gameobject to update&draw list
		SceneManager::GetInstance()->GetCurrentScene()->AddGameObjectToWeaponList(weaponL);
		
		//add appleWeapon to QuadTree
		QuadTree::InsertDynamicObject(weaponL);
		
		//_enemy->~Enemy();

		//Enemy4Weapon* weaponR = weaponL;
		//weaponR->SetVelocity(_enemy->GetPosition() - _enemy->GetTarget()->GetPosition());
		//SceneManager::GetInstance()->GetCurrentScene()->AddGameObjectToWeaponList(weaponR);
		//QuadTree::InsertDynamicObject(weaponR);
		

	}
}
