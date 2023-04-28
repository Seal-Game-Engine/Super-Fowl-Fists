#pragma once
#include "SealEngine.h"
#include "Player.h"
using namespace SealEngine;

class XwingPlayer : public Player {
public:
	void Awake() override;
	void Update() override;
	void OnCollisionEnter2D(Collision2D collision) override {}

	XwingPlayer() = default;

private:
	Rigidbody2D* rigidbody = nullptr;
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;

	float _speed = 5.0f;
	float _nextFire = 0;

	XwingPlayer* _Clone() const override { return new XwingPlayer(*this); }
};