#pragma once
#include "Boss.h"

class SenseiWu : public Boss{
public:
	void OnDeath() override;

	SenseiWu(const float hp);


	void Awake() override;
	void Update() override;

private:
	enum class ActionState { InTransition, Idle, FireballAttack, TeleportOut, TeleportIn, StudentAttack };
	ActionState actionState = ActionState::Idle;
	void OnStateEnter();
	void OnStateExit();
	void SetState(ActionState state);

	void Idle();
	void FireballAttack();
	void TeleportOut();
	void TeleportIn();
	void StudentAttack();

	ObjectPool _projectilePool = ObjectPool(Prefab::BossProjectile_Object);

	const float _speed = 4.0f;

	float _nextActionTime = 0;

	const float _fireballAttackDuration = 3;
	const float _fireballAttackCooldown = 0.8f;
	float _nextFireballTime = 0;

	const float _studentAttackDuration = 5;
	const float _studentAttackCooldown = 3;
	float _nextStudentTime = 0;

	SenseiWu* _Clone() const override { return new SenseiWu(*this); }
};

