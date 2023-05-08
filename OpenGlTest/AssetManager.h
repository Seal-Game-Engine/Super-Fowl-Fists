#pragma once
#include <memory>
#include "SealEngine.h"
using namespace SealEngine;
using namespace SealEngine::Ui;

class AssetManager {
public:

	static const GameObject MainCamera;

#pragma region PlayerCharacters
	static const Texture2D MiniTikeMysonTexture;
	static const Texture2D BigTikeMysonTexture;
	static const AnimatorController TikeMyson_Controller;
	static const GameObject TikeMysonObject;
#pragma endregion
	static const GameObject ProjectileObject_Blue;

	//Sensei
	static const Texture2D Sensei_Texture;
	static const AnimationClip Sensei_Idle_Clip;
	static const AnimationClip Sensei_Walking_Clip;
	static const AnimationClip Sensei_Hadoken_Clip;
	static const AnimationClip Sensei_CallsReinforcements_Clip;
	static const AnimationClip Sensei_CallingReinforcements_Clip;
	static const AnimationClip Sensei_TeleportOut_Clip;
	static const AnimationClip Sensei_TeleportIn_Clip;
	static const AnimationClip Sensei_Hurt_Clip;
	static const AnimatorController Sensei_Controller;
	static const GameObject Sensei_Object;

	//Boss
	static const Texture2D BossTexture;
	static const AnimationClip Boss_Charging;
	static const AnimationClip Boss_Charged;
	static const AnimationClip Boss_Close;
	static const AnimationClip Boss_Chomp_Indicator;
	static const AnimationClip Boss_Bomb_Indicator;
	static const AnimationClip Boss_Open;
	static const AnimationClip Boss_Chomp_Attack;
	static const AnimationClip Boss_Bomb_Attack;
	static const AnimatorController Boss_Controller;
	static const GameObject BossObject;

	//Spawner
	static const GameObject ObstacleSpawner_Object;

	//Misc
	static const Texture2D Googleplex_Texture;

	static const Texture2D SpaceBackground_Texture;
	static const Texture2D GalaxyBackground;

	static const Texture2D Font;

	static const Texture2D LandingScene_Title_Texture;
	static const Texture2D MenuOptions;
	static const Texture2D PauseScreen;
	static const Texture2D PauseMessage;

	static const Texture2D SkyBackground;
	static const Texture2D MountainBackground;

#pragma region Testing
	//Obstacle
	static const Texture2D Obstacle_Texture;
	static const AnimationClip Obstacle_Idle_Clip;
	static const AnimatorController Obstacle_Controller;
	//static const GameObject Obstacle_Object;


	static const Texture2D Projectile_Blue_Texture;
	static const AnimationClip Projectile_Blue_Idle_Clip;
	static const AnimatorController Projectile_Blue_Controller;
#pragma endregion
};
