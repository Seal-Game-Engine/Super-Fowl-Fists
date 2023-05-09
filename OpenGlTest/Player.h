#pragma once
#include <functional>
#include "SealEngine.h"
using namespace SealEngine;
#include "Entity.h"


class Player : public Entity {
public:
	struct InputData {
		float horizontal = 0;
		bool horizontalUp = false;

		bool jumpDown = false;

		bool attackDown = false;
	};
	enum class ControlScheme { Solo, Player1, Player2 };

	InputData GetInputData(ControlScheme controlScheme);
	//void TakeDamage(DamageData data, Vector2 knockbackDirection) override;
	ControlScheme controlScheme = ControlScheme::Solo;

	Player() = default;

	void Awake() override;
	void Update() override;
	void OnCollisionEnter2D(Collision2D collision) override;
	void OnCollisionStay2D(Collision2D collision) override;
	void OnCollisionExit2D(Collision2D collision) override;

private:
	const float miniColliderRadius = 0.1875f;
	const float bigColliderRadius = 0.375f;

	SpriteRenderer* _renderer = nullptr;
	Animator* _animator = nullptr;
	Rigidbody2D* _rigidbody = nullptr;
	CircleCollider2D* _collider = nullptr;
	AudioSource* _audioSource = nullptr;

	float _speed = 4.0f;
	bool _canJump = true;
	float _nextFire = 0;

	enum class PowerState : int { Small, Buff };
	PowerState _powerState = PowerState::Small;

	Player* _Clone() const override { return new Player(*this); }
};