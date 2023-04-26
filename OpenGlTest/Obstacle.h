#pragma once
#include "SealEngine.h"
#include "NarioPlayer.h"
#include "Player.h"

using namespace SealEngine;

class Obstacle : public MonoBehaviour {
public:
	void Awake() override;
	void Start() override;
	void Update() override;
	void OnCollisionEnter2D() override;

	Vector2 spawnedPosition = Vector2::zero();

private:
	float speed = 0.5f;
	
	NarioPlayer* narioPlayer = nullptr;
	Player* player = nullptr;

	Obstacle* Clone_impl() const override { return new Obstacle(*this); }
};

