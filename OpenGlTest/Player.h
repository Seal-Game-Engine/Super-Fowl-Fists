#pragma once
#include "SealEngine.h"
#include <memory>
using namespace SealEngine;

class Player {
public:
	Player();
	void Awake();
	void Actions(int);
	void Update();
	void LateUpdate();

	Transform transform;
	Vector3 pivotOffset = Vector3::zero();

	float runSpeed, jumpSpeed;
	int actionTrigger;

	SpriteRenderer renderer;
};

