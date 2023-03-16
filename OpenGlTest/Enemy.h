#pragma once
#include "SealEngine.h"
using namespace SealEngine;


class Enemy {
public:
	void Draw();
	void PlaceEnemy(Vector3);
	void Init(char* fileName, int, int);
	void Actions(int);
	void Update();

	Transform transform;
	Vector3 pivotOffset = Vector3::zero();

	Texture2D* textureLoader = new Texture2D(0, 0);
	GLuint tex;
	float runSpeed, jumpSpeed;
	int actionTrigger;
};

