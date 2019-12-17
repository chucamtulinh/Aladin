#include "BatDamageState.h"


#include "BatDamageState.h"
#include "Bat.h"
#include "BatIdleState.h"

BatDamageState::BatDamageState()
{
	//not use
}

BatDamageState::BatDamageState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Damage)
{
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLBat(), "Damage", ResourceManager::GetInstance()->GetTextureEnemies1(), false, 0.8f));
}


BatDamageState::~BatDamageState()
{
}

void BatDamageState::Update(float deltaTime)
{
	EnemyState::Update(deltaTime);

}
