#pragma once
#include "SealEngine.h"
#include "IDamageable.h"
#include <functional>
using namespace SealEngine;

class Player : public MonoBehaviour, public IDamageable {
public:
	enum class ControlScheme { Solo, Player1, Player2 };


	void TakeDamage(float damage) override;

	void Awake() override;
	void Update() override;
	void OnCollisionEnter2D(Collision2D collision) override;
	void OnCollisionStay2D(Collision2D collision) override;
	void OnCollisionExit2D(Collision2D collision) override;

	Player() = default;

private:
	SpriteRenderer* _renderer = nullptr;
	Animator* _animator = nullptr;
	Rigidbody2D* _rigidbody = nullptr;

	float _speed = 4.0f;
	bool _canJump = true;
	float _nextFire = 0;

	enum class PowerState : int { Small, Buff };
	PowerState _powerState = PowerState::Small;

	Player* _Clone() const override { return new Player(*this); }
};