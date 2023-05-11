#pragma once
#include <memory>
#include "SealEngine.h"
using namespace SealEngine;
using namespace SealEngine::Ui;

class Prefab {
public:

#pragma region PlayerCharacters
	static const Texture2D MiniTikeMyson_Texture;
	static const Texture2D BigTikeMyson_Texture;
	static const AnimatorController TikeMyson_Controller;
	static const GameObject TikeMyson_Object;

	static const Texture2D MiniChicken_Texture;
	static const Texture2D BigChicken_Texture;
	static const AnimatorController Chicken_Controller;
	static const GameObject Chicken_Object;
#pragma endregion
	static const GameObject ProjectileObject_Blue;

	//Sensei
	static const Texture2D Sensei_Texture;
	static const Texture2D Sensei_Projectile_Texture;
	static const AnimatorController Sensei_Controller;
	static const GameObject Sensei_Object;

	//Students
	static const Texture2D Students_Texture;
	static const AnimatorController Students_Controller;
	static const GameObject Students_Object;

	//Boss
	static const Texture2D Boss_Texture;
	static const Texture2D Boss_Projectile_Texture;
	static const AnimatorController Boss_Controller;
	static const GameObject BossObject;

	//Spawner
	static const GameObject ObstacleSpawner_Object;


	static const Texture2D PauseScreen;


#pragma region Testing
	//Obstacle
	static const Texture2D Obstacle_Texture;
	static const AnimatorController Obstacle_Controller;
	static const GameObject Obstacle_Object;


	static const Texture2D Projectile_Blue_Texture;
	static const AnimatorController Projectile_Blue_Controller;
#pragma endregion
};
