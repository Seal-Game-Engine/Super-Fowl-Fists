#pragma once
#include "SealEngine.h"
#include "Entity.h"
using namespace SealEngine;

class Boss : public Entity {
public:
	//void TakeDamage(float damage) override;

	void Awake() override;
	void Update() override;
	//void OnCollisionEnter2D(Collision2D collision) override;

private:
	SpriteRenderer* _renderer = nullptr;
	Animator* animator = nullptr;
	Rigidbody2D* rigidbody = nullptr;

	float _speed = 4.0f;
	bool _canJump = true;
	float _nextFire = 0;

	enum class PowerState : int { Small, Buff };
	PowerState powerState = PowerState::Small;

	//static const std::array<const AnimatorController*, 2> animatorControllers;

	Boss* _Clone() const override { return new Boss(*this); }
};


