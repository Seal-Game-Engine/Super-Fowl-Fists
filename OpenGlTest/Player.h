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
	Vector3 originOffset = Vector3::zero();

	TextureLoader* textureLoader = new TextureLoader();
	GLuint tex;
	float runSpeed, jumpSpeed;int actionTrigger;
};

