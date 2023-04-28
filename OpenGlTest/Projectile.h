#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Projectile : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;

	float destroyTime = 0;
	float lifeSpan = 1.5f;

private:
	float speed = 8.0f;
	Rigidbody2D* _rigidbody = nullptr;

	Projectile* _Clone() const override { return new Projectile(*this); }
};