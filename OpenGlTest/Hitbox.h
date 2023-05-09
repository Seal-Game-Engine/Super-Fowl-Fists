#pragma once
#include "SealEngine.h"
using namespace SealEngine;
#include "IDamageable.h"
class Entity;

class Hitbox : public MonoBehaviour {
public:
	DamageData data;

	Hitbox(DamageData data = DamageData{});

	void OnTriggerEnter2D(Collider2D* collider) override;
	void OnCollisionEnter2D(Collision2D collision) override;

private:
	Hitbox* _Clone() const override { return new Hitbox(*this); }
};