#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player : public MonoBehaviour {
public:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;

	void Update() override;
	//void LateUpdate() override;

	Player() = default;
	Player(const Player& obj) : MonoBehaviour(obj) {}
	std::shared_ptr<Player> Clone() const { return std::shared_ptr<Player>(Clone_impl()); }

private:
	float speed = 4.0f;

	virtual Player* Clone_impl() const override{ return new Player(*this); }
};

