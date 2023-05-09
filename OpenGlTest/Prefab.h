#pragma once
#include <memory>
#include "SealEngine.h"
using namespace SealEngine;
using namespace SealEngine::Ui;

class Prefab {
public:

#pragma region PlayerCharacters
	static const Texture2D MiniTikeMysonTexture;
	static const Texture2D BigTikeMysonTexture;
	static const AnimatorController TikeMyson_Controller;
	static const GameObject TikeMysonObject;
#pragma endregion
	static const GameObject ProjectileObject_Blue;

	//Sensei
	static const Texture2D Sensei_Texture;
	static const AnimatorController Sensei_Controller;
	static const GameObject Sensei_Object;

	//Boss
	static const Texture2D BossTexture;
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
