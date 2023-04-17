#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Projectile : public MonoBehaviour {
public:
	void Update() override;

	std::shared_ptr<Projectile> Clone() const { return std::shared_ptr<Projectile>(Clone_impl()); }
	float destroyTime = 0;
	float lifeSpan = 1.5f;

private:
	float speed = 8.0f;

	virtual Projectile* Clone_impl() const override{ return new Projectile(*this); }
};

