#pragma once
#include "Boss.h"
class Robot :    public Boss{
public:
	//void OnDamageTaken(DamageData data, Vector2 knockbackDirection) override;
	void OnDeath() override;

	Robot(const float hp);

	void Awake() override;
	void Update() override;

private:
	enum class ActionState { InTransition, Charge, BombAttack, ChompAttack };
	ActionState actionState = ActionState::Charge;
	void OnStateEnter();
	void OnStateExit();
	void SetState(ActionState state);

	void Charge();
	void BombAttack();
	void ChompAttack();
	void SwitchSide();

	ObjectPool _bombPool = ObjectPool(Prefab::Bomb_Object);
	ObjectPool _projectilePool = ObjectPool(Prefab::BossProjectile_Object);

	const float _speed = 4.0f;

	float _nextActionTime = 0;

	const float _bombAttackDuration = 4;
	const float _bombAttackCooldown = 0.9f;
	float _nextBombTime = 0;

	const float _chompAttackDuration = 4;
	const float _chompAttackCooldown = 0.9f;
	float _nextChompTime = 0;


	Robot* _Clone() const override { return new Robot(*this); }
};

