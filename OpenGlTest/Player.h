#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player {
public:
	Player();
	void Actions(int);
	void Update();
	void LateUpdate();

	Transform transform;
	Vector3 pivotOffset = Vector3::zero();

	float runSpeed, jumpSpeed;
	int actionTrigger;

	SpriteRenderer renderer;

private:
	//Temporary
	std::unique_ptr<const int> idleFrames = std::unique_ptr<const int>(new int[4] {1, 5, 1, 9});
};

