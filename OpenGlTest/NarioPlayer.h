#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class NarioPlayer : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;
	void LateUpdate() override;

	NarioPlayer() = default;

private:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	Collider2D* collider = nullptr;

	float _nextSpawn = 0.0f;
	float _speed = 5.0f;
	float stopGravity = 0.0f;

	NarioPlayer* Clone_impl() const override { return new NarioPlayer(*this); }
};

