#pragma once
#include "SealEngine.h"
#include <array>
using namespace SealEngine;


class Enemy {
public:
	Enemy();
	void PlaceEnemy(Vector3);
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
	std::array<const int, 2> idleFrames{ 1, 5 };
};

