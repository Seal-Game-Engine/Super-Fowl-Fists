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

	static const Texture2D GreenSlime;
	static const AnimationClip GreenSlime_Idle;
	static const AnimatorController GreenSlime_Controller;

	//Sensei
	static const Texture2D SenseiTexture;
	static const AnimationClip Sensei_Idle;
	static const AnimationClip Sensei_Walking;
	static const AnimationClip Sensei_Hadoken;
	static const AnimationClip Sensei_CallsReinforcements;
	static const AnimationClip Sensei_CallingReinforcements;
	static const AnimationClip Sensei_TeleportOut;
	static const AnimationClip Sensei_TeleportIn;
	static const AnimationClip Sensei_Hurt;
	static const AnimatorController Sensei_Controller;
	static const GameObject SenseiObject;

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
	static const GameObject ObstacleSpawnerObject;

	//Misc
	static const Texture2D Googleplex;

	static const Texture2D SpaceBackground;
	static const Texture2D GalaxyBackground;

	static const Texture2D Font;

	static const Texture2D GameTitle;
	static const Texture2D MenuOptions;
	static const Texture2D PauseScreen;
	static const Texture2D PauseMessage;

	static const Texture2D SkyBackground;
	static const Texture2D MountainBackground;

#pragma region Testing
	static const Texture2D XwingTexture;
	static const AnimatorController Xwing_Controller;
	static const GameObject XwingObject;

	static const Texture2D Projectile_Blue_Texture;
	static const AnimationClip Projectile_Blue_Idle;
	static const AnimatorController Projectile_Blue_Controller;

	//Obstacle
	static const Texture2D ObstacleTexture;
	static const AnimationClip Obstacle_Idle;
	static const AnimatorController Obstacle_Controller;
	static const GameObject ObstacleObject;
#pragma endregion
};
