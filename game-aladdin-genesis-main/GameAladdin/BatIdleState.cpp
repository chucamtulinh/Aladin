#include "BatIdleState.h"

#include "BatIdleState.h"
#include "Bat.h"
#include "BatFlyState.h"

BatIdleState::BatIdleState()
{
	//not use
}

BatIdleState::BatIdleState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Idle)
{
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLBat(), "Idle", ResourceManager::GetInstance()->GetTextureEnemies1(), false));
}


BatIdleState::~BatIdleState()
{
}

void BatIdleState::Update(float deltaTime)
{
	EnemyState::Update(deltaTime);

	//change state
	if (_enemy->GetVelocity().x != 0)
	{
		_enemy->SetState(new BatFlyState(_enemy));
		return;
	}

	/*if (_enemy->IsTargetInAttackRange())
	{
		_enemy->SetState(new BatAttackState(_enemy));
		return;
	}*/
}
