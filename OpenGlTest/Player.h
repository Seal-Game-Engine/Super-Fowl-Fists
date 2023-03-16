#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Player {
public:
	Player();
	void Draw();
	void Init(char* fileName);
	void Actions(int);
	void Update();

	Transform transform;
	Vector3 pivotOffset = Vector3::zero();

	Texture2D* textureLoader = new Texture2D(0, 0);
	GLuint tex;
	float runSpeed, jumpSpeed;
	int actionTrigger;
};

