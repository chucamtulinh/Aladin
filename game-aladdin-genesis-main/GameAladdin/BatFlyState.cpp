#include "BatFlyState.h"



#include "BatFlyState.h"
#include "Bat.h"
#include "BatIdleState.h"

BatFlyState::BatFlyState()
{
}

BatFlyState::BatFlyState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Fly)
{
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLBat(), "Fly", ResourceManager::GetInstance()->GetTextureEnemies1(), false, 0.7f));
}


BatFlyState::~BatFlyState()
{
}

void BatFlyState::Update(float deltaTime)
{
	EnemyState::Update(deltaTime);

	//change state
	if (_enemy->GetVelocity().x == 0)//change state
	{
		_enemy->SetState(new BatIdleState(_enemy));
		return;
	}

	/*if (_enemy->IsTargetInAttackRange())
	{
		_enemy->SetState(new BatAttackState(_enemy));
		return;
	}*/
}
