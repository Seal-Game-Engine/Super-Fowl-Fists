#pragma once
#include "Vector2.h"
using namespace SealEngine;

class CheckCollision
{
public:
	bool isRadialCollision(Vector2, Vector2);
	bool isLinearCollision(float x1, float x2);
	bool isSphereCollision(Vector3, Vector3);
	bool isQuadColission(Vector2, Vector2);

};

