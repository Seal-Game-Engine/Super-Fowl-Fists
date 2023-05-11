#pragma once
#include <functional>
#include "SealEngine.h"
using namespace SealEngine;
#include "Entity.h"
#include "Prefab.h"

class Boss : public Entity {
public:
	void OnDamageTaken(DamageData data, Vector2 knockbackDirection) override;
	void OnDeath() override;

	Boss(const float hp);

	void Awake() override;
	
protected:
	Animator* _animator = nullptr;
	Rigidbody2D* _rigidbody = nullptr;
	AudioSource* _audioSource = nullptr;

private:
	SpriteRenderer* _renderer = nullptr;

	Boss* _Clone() const override { return new Boss(*this); }
};


