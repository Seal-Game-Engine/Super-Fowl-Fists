#pragma once
#include "SealEngine.h"
using namespace SealEngine;
#include "IDamageable.h"

class Entity : public MonoBehaviour, public IDamageable {
public:
	Entity() = default;

	void TakeDamage(DamageData data, Vector2 knockbackDirection) override;

private:
	Entity* _Clone() const override { return new Entity(*this); }
};

