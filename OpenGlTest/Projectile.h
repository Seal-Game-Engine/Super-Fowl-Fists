#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Projectile {
public:
	Projectile(Vector3 position);
	Transform transform;

	SpriteRenderer renderer;
	Animator animator;


	void Update();

private:
	float speed = 8.0f;
	float lifeSpan = 1.5f;
	float destroyTime = 0;

	int id;
	static int idCounter;
};

