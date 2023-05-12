#pragma once
#include "../SealEngine.h"
using namespace SealEngine;

class TestScene {
public:
	static const Texture2D Xwing_Texture;
	static const AnimatorController Xwing_Controller;
	static const GameObject Xwing_Object;

	static const Texture2D Obstacle_Texture;
	static const AnimationClip Obstacle_Idle_Clip;
	static const AnimatorController Obstacle_Controller;
	static const GameObject Obstacle_Object;

	static Scene TestingScene;
};