#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Obstacle : public MonoBehaviour {
public:
	void Awake() override;
	void Update() override;
	void OnCollisionEnter2D() override;
	std::shared_ptr<Obstacle> Clone() const { return std::shared_ptr<Obstacle>(Clone_impl()); }
	Vector2 spawnedPosition = Vector2::zero();
private:
	float speed = 5.0f;
	virtual Obstacle* Clone_impl() const override { return new Obstacle(*this); }
	
};
