#pragma once
#include <string>
#include "SealEngine.h"
using namespace SealEngine;


class Enemy {
public:
	Enemy();
	void Draw();
	void PlaceEnemy(Vector3);
	void Init(int, int);
	void Actions(int);
	void Update();

	Transform transform;
	Vector3 pivotOffset = Vector3::zero();

	Texture2D textureLoader;
	GLuint tex;
	float runSpeed, jumpSpeed;
	int actionTrigger;
};

