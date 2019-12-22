#include "Enemy3Dead.h"
#include "Enemy3.h"
#include "Enemy3WalkState.h"
#include "../../Weapons/EnemiesWeapons/Enemy4Weapon.h"
#include "../../../GameComponents/SceneManager.h"

Enemy3Dead::Enemy3Dead()
{
	//not use
}

Enemy3Dead::Enemy3Dead(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Attack)
{
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLEnemy3Dead(), "Dead", ResourceManager::GetInstance()->GetTextureEnemies3(), true, 0.5f));

}


Enemy3Dead::~Enemy3Dead()
{
}

void Enemy3Dead::Update(float deltaTime)
{
	EnemyState::Update(deltaTime);

	
}
