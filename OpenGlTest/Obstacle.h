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
	void OnCollisionEnter2D(Collision2D collision) override;

private:
	float speed = 0.5f;
	
	Rigidbody2D* rigidbody = nullptr;

	NarioPlayer* narioPlayer = nullptr;
	Player* player = nullptr;

	Obstacle* _Clone() const override { return new Obstacle(*this); }
};

