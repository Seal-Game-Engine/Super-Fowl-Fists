#pragma once
#include <functional>
#include "SealEngine.h"
using namespace SealEngine;
#include "Entity.h"


class Player : public Entity {
public:
	struct InputData {
		float x = 0;
		float y = 0;
		bool anyMovementUp = false;

		bool attackDown = false;
	};
	enum class ControlScheme { Solo, Player1, Player2 };

	InputData GetInputData(ControlScheme controlScheme);
	//void TakeDamage(DamageData data, Vector2 knockbackDirection) override;

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