#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;
	//void LateUpdate() override;

	Player() = default;
	Player(const Player& obj) : MonoBehaviour(obj) {}
	std::shared_ptr<Player> Clone() const;

private:
	SpriteRenderer* renderer = nullptr;
	Animator* animator = nullptr;
	float speed = 4.0f;
	float _nextFire = 0;

	Player* Clone_impl() const override;
};

