#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player {
public:
	Player();
	void Update();
	void LateUpdate();

	Transform transform;
	Vector3 pivotOffset = Vector3::zero();

	SpriteRenderer renderer;
	Animator animator;

private:
	float speed = 4.0f;
};

