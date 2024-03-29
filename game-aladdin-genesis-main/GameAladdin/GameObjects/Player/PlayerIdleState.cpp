#include "PlayerIdleState.h"
#include "Player.h"
#include "PlayerRunState.h"
#include "PlayerAttackState.h"
#include "PlayerThrowState.h"
#include "PlayerJumpState.h"
#include "PlayerFallState.h"
#include "PlayerCrouchIdleState.h"
#include "PlayerDamageState.h"
#include "PlayerUpState.h"
#include "PlayerPushWallState.h"

PlayerIdleState::PlayerIdleState()
{
}

PlayerIdleState::PlayerIdleState(Player* player) :PlayerState(player, PlayerState::StateName::Idle)
{
	SetAnimation(new Animation(ResourceManager::GetInstance()->GetAnimationXMLAladdin(), "Idle", ResourceManager::GetInstance()->GetTextureAladdin(), true, 1.6f));
}


PlayerIdleState::~PlayerIdleState()
{
}

void PlayerIdleState::Update(float deltaTime)
{
	PlayerState::Update(deltaTime);

	//change state

	if (_player->GetIsPushWall())
	{
		_player->SetState(new PlayerPushWallState(_player));
		return;
	}

	if (_player->GetVelocity().x != 0)
	{
		_player->SetState(new PlayerRunState(_player));
		return;
	}

	if (Input::GetInstance()->IsKeyPressed(DIK_X))
	{
		_player->SetState(new PlayerAttackState(_player));
		return;
	}

	if (Input::GetInstance()->IsKeyPressed(DIK_C))
	{
		_player->SetState(new PlayerJumpState(_player));
		return;
	}

	if (Input::GetInstance()->IsKeyPressed(DIK_Z) && _player->GetNumAppleWeapon() > 0)
	{
		_player->SetState(new PlayerThrowState(_player));
		return;
	}

	if (Input::GetInstance()->IsKeyPressed(DIK_DOWN))
	{
		_player->SetState(new PlayerCrouchIdleState(_player));
		return;
	}

	//Up
	if (Input::GetInstance()->IsKeyPressed(DIK_UP))
	{
		_player->SetState(new PlayerUpState(_player));
		return;
	}

	if (!_player->IsGround())
	{
		_player->SetState(new PlayerFallState(_player));
		return;
	}

	//if (!_player->IsGround())
	//{
	//	if (_player->GetVelocity().y > 10)
	//	{
	//		_player->SetState(new PlayerFallState(_player));
	//		return;
	//	}
	//	else
	//	{
	//		_player->SetAccelerationY(_player->GetMass());
	//		return;
	//	}
	//}
}
