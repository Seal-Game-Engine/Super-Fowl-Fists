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
	ControlScheme controlScheme = ControlScheme::Solo;

	void OnDamageTaken(DamageData data, Vector2 knockbackDirection) override;
	void OnDeath() override;

	Player(const float hp);

	void Awake() override;
	void Update() override;
	void OnCollisionEnter2D(Collision2D collision) override;
	void OnCollisionStay2D(Collision2D collision) override;
	void OnCollisionExit2D(Collision2D collision) override;

protected:
	virtual void Attack_Mini();
	virtual void Attack_Big();
	AudioSource* _audioSource = nullptr;

private:
	enum class PowerState : int { Mini, Big };

	void SetPowerState(PowerState powerState);

	const float miniColliderRadius = 0.1875f;
	const float bigColliderRadius = 0.375f;

	Animator* _animator = nullptr;
	Rigidbody2D* _rigidbody = nullptr;
	CircleCollider2D* _collider = nullptr;

	GameObject* hitbox = nullptr;

	float _maxVerticalVelocity = 6;
	float _speed = 4.0f;
	bool _canJump = true;
	float _nextAttack = 0;

	PowerState _powerState = PowerState::Mini;

	Player* _Clone() const override { return new Player(*this); }
};