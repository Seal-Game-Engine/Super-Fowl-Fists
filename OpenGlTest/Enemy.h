#pragma once
#include "SealEngine.h"
using namespace SealEngine;


class Enemy : public MonoBehaviour {
public:
	float runSpeed = 0, jumpSpeed = 0;
	int actionTrigger = 0;

	SpriteRenderer* renderer;
	Animator* animator;

private:
};

