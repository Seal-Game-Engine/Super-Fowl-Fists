#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player : public MonoBehaviour {
public:
	float speed() const { return _speed; }

	void Awake() override;
	void Update() override;
	void LateUpdate() override;

	Player() = default;

private:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	Collider2D* collider = nullptr;

	float _nextFire = 0;

	float _nextSpawn = 0.0f;
	float _speed = 5.0f;
	float stopGravity = 0.0f;

	Player* Clone_impl() const override { return new Player(*this); }
};

