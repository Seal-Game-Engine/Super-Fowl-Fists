#pragma once
#include "../SealEngine.h"
using namespace SealEngine;
#include "../Entity.h"

class XwingPlayer : public Entity {
public:
	void FireProjectile();

	void Awake() override;
	void Update() override;
	void LateUpdate() override;
	void OnCollisionEnter2D(Collision2D collision) override {}
	void OnCollisionStay2D(Collision2D collision) override {}
	void OnCollisionExit2D(Collision2D collision) override {}


	XwingPlayer() = default;

private:
	Rigidbody2D* rigidbody = nullptr;
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	AudioSource* audioSource = nullptr;

	float _speed = 5.0f;
	float _nextFire = 0;

	XwingPlayer* _Clone() const override { return new XwingPlayer(*this); }
};