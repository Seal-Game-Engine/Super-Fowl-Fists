#pragma once
#include "SealEngine.h"

using namespace SealEngine;

class Obstacle : public MonoBehaviour {
public:
	void Awake() override;
	void Start() override;
	void Update() override;
	void OnCollisionEnter2D(Collision2D collision) override;

private:
	float _speed = 2.0f;
	
	Rigidbody2D* rigidbody = nullptr;

	GameObject* player = nullptr;

	Obstacle* _Clone() const override { return new Obstacle(*this); }
};

