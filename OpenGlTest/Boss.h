#pragma once
#include <functional>
#include "SealEngine.h"
using namespace SealEngine;
#include "Entity.h"

class Boss : public Entity {
public:
	//void TakeDamage(float damage) override;

	Boss(const float hp);

	void Awake() override;
	void Update() override;
	//void OnCollisionEnter2D(Collision2D collision) override;

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

	SpriteRenderer* _renderer = nullptr;
	Animator* _animator = nullptr;
	Rigidbody2D* _rigidbody = nullptr;
	AudioSource* _audioSource = nullptr;

	float _speed = 4.0f;


	float _nextActionTime = 0;

	const float _bombAttackDuration = 3;
	const float _bombAttackCooldown = 0.5f;
	float _nextBombTime = 0;

	Boss* _Clone() const override { return new Boss(*this); }
};


