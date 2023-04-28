#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;
	void LateUpdate() override;
	void OnCollisionEnter2D() override;

	Player() = default;

private:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	Collider2D* collider = nullptr;

	float _nextFire = 0;

	float _nextSpawn = 0.0f;
	float _speed = 1.0f;
	float stopGravity = 0.0f;

	enum class PowerState : int { Small, Buff };
	PowerState powerState = PowerState::Small;

	static const std::array<const AnimatorController*, 2> animatorControllers;

	Player* Clone_impl() const override { return new Player(*this); }
};

