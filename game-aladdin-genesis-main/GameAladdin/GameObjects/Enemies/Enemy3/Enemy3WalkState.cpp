#include "Enemy3Dead.h"
#include "Enemy3WalkState.h"
#include "Enemy3.h"
#include "Enemy3IdleState.h"
#include "Enemy3AttackState.h"

Enemy3WalkState::Enemy3WalkState()
{
}

Enemy3WalkState::Enemy3WalkState(Enemy * enemy) : EnemyState(enemy, EnemyState::StateName::Fly)
{
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLEnemy3(), "Fly", ResourceManager::GetInstance()->GetTextureEnemies3(), false, 0.3f));
}


Enemy3WalkState::~Enemy3WalkState()
{
}

void Enemy3WalkState::Update(float deltaTime)
{
	EnemyState::Update(deltaTime);
	

	//change state
	if (_enemy->GetVelocity().x == 0)//change state
	{
		_enemy->SetState(new Enemy3IdleState(_enemy));
		return;
	}

	if (!_enemy->IsTargetInAttackRange())
	{
		_enemy->SetState(new Enemy3IdleState(_enemy));
		return;
	}

	if (_enemy->GetHealth() <= 50)
	{
		// _enemy->SetState(new Enemy3Dead(_enemy));
		return;
	}
}
