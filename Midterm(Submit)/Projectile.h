#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Projectile : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;

	std::shared_ptr<Projectile> Clone() const;
	float destroyTime = 0;
	float lifeSpan = 1.5f;

private:
	float speed = 8.0f;

	Projectile* Clone_impl() const override;
};

