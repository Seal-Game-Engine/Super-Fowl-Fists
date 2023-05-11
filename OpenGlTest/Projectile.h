#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Projectile : public MonoBehaviour {
public:
	enum class TraversalMethods { UseVelocity, UseForce, };

	void Initialize(Vector2 direction, GameObject* sourceObject);

	Projectile(float speed = 1, float lifeSpan = 5, TraversalMethods traversalMethod = TraversalMethods::UseVelocity, bool isExplosive = false);

	void Awake() override;
	void Update() override;

	void OnTriggerEnter2D(Collider2D* collider) override;
	void OnCollisionEnter2D(Collision2D collision) override;

private:
	float _speed = 1;
	float _lifeSpan = 5;
	float _destroyTime = 0;
	TraversalMethods _traversalMethod = TraversalMethods::UseVelocity;
	bool _isExplosive = false;
	Vector2 _direction = Vector2::zero();

	GameObject* _sourceObject = nullptr;
	Rigidbody2D* _rigidbody = nullptr;

	Projectile* _Clone() const override { return new Projectile(*this); }
};