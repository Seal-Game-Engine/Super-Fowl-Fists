#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player : public MonoBehaviour {
public:
	void Update() override;
	//void LateUpdate() override;

	Player() = default;
	Player(const Player& obj) : MonoBehaviour(obj) {}
	std::shared_ptr<Player> Clone() const { return std::shared_ptr<Player>(Clone_impl()); }

private:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	float speed = 4.0f;
	float _nextFire = 0;

	virtual Player* Clone_impl() const override{ return new Player(*this); }
};

