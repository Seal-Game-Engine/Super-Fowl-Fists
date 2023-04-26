#pragma once
#include "SealEngine.h"
#include "Collider2D.h"
using namespace SealEngine;

class Player : public MonoBehaviour {
public:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	Collider2D* collider = nullptr;
	void Awake() override;
	void Update() override;
	void LateUpdate() override;
	float speed() { return _speed; }
	Player() = default;
	Player(const Player& obj) : MonoBehaviour(obj) {}
	std::shared_ptr<Player> Clone() const { return std::shared_ptr<Player>(Clone_impl()); } //components needs this

private:
	float _nextSpawn = 0.0f;
	float _speed = 5.0f;
	float stopGravity = 0.0f;
	
	virtual Player* Clone_impl() const override{ return new Player(*this); } //components needs this
};

