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

	//Projectiles
	static const Texture2D Bomb_Texture;
	static const AnimatorController Bomb_Controller;
	static const GameObject Bomb_Object;

	static const Texture2D BossProjectile_Texture;
	static const AnimatorController BossProjectile_Controller;
	static const GameObject BossProjectile_Object;

	//Explosion 32x32
	static const Texture2D Explosion32_Texture;
	static const AnimatorController Explosion32_Controller;
	static const GameObject Explosion32_Object;

	//Explosion 64x64
	static const Texture2D Explosion64_Texture;
	static const AnimatorController Explosion64_Controller;
	static const GameObject Explosion64_Object;

	static const Texture2D PauseScreen;
	static const Texture2D WinScreen;
	static const Texture2D LoseScreen;

#pragma region Testing
	//Obstacle
	static const Texture2D Obstacle_Texture;
	static const AnimatorController Obstacle_Controller;
	static const GameObject Obstacle_Object;


	static const Texture2D Projectile_Blue_Texture;
	static const AnimatorController Projectile_Blue_Controller;
	static const GameObject ProjectileObject_Blue;
#pragma endregion
};
