#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class XwingPlayer : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;

	XwingPlayer() = default;

private:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;

	float _speed = 5.0f;
	float _nextFire = 0;

	XwingPlayer* Clone_impl() const override { return new XwingPlayer(*this); }
};