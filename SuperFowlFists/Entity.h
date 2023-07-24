#pragma once
#include "SealEngine.h"
using namespace SealEngine;
#include "IDamageable.h"

class Entity : public MonoBehaviour, public IDamageable {
public:
	virtual void OnDamageDealt() {}
	void OnDamageTaken(DamageData data, Vector2 knockbackDirection) override;
	virtual void OnDeath() {}

	bool isAlive() const { return _isAlive; }

	const float maxHp = 10;
	float currentHp = 10;

	Entity(const float hp);

private:
	bool _isAlive = true;

	Entity* _Clone() const override { return new Entity(*this); }
};

