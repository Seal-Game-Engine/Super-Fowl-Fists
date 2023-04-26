#pragma once
#include<memory>
#include "SealEngine.h"
using namespace SealEngine;

class AssetManager {
public:
	//Nario
	static const Texture2D Nario;
	static const AnimationClip Nario_Idle;
	static const AnimationClip Nario_Left;
	static const AnimationClip Nario_Right;
	static const AnimationClip Nario_Jump;
	static const AnimatorController Nario_Controller;
	static const GameObject NarioObject;

	//Obstacle
	static const Texture2D ObstacleTexture;
	static const AnimationClip Obstacle_Idle;
	static const AnimatorController Obstacle_Controller;
	static const GameObject ObstacleObject;

	//Spawner
	static const GameObject ObstacleSpawnerObject;

	//Misc
	static const Texture2D Googleplex;
	static const Texture2D SkyBackground;
	static const Texture2D MountainBackground;
};