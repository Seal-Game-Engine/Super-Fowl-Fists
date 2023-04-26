#pragma once
#include "SealEngine.h"
#include "Collider2D.h"
using namespace SealEngine;

class Player : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;
	void LateUpdate() override;

	Player() = default;
	Player(const Player& obj) : MonoBehaviour(obj) {}

private:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	Collider2D* collider = nullptr;

	float speed = 4.0f;
	float _nextFire = 0;
private:
	float _nextSpawn = 0.0f;
	float _speed = 5.0f;
	float stopGravity = 0.0f;

	float speed() { return _speed; }

	Player() = default;
	virtual Player* Clone_impl() const override{ return new Player(*this); } //components needs this
};

