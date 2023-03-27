#pragma once
#include "SealEngine.h"
#include <array>
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
	std::array<const int, 4> idleFrames{ 1, 5, 1, 9 };
};

