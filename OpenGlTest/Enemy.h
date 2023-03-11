#pragma once
#include "SealEngine.h"
using namespace SealEngine;


class Enemy {
public:
	//Enemy();
	void Draw();
	void PlaceEnemy(Vector3);
	void Init(char* fileName, int, int);
	void Actions(int);
	void Update();

	Transform transform;
	Vector3 pivotOffset = Vector3::zero();

	Texture2D* textureLoader = new Texture2D();
	GLuint tex;
	float runSpeed, jumpSpeed;
	int actionTrigger;
};

