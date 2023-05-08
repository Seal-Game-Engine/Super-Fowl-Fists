#include "AssetManager.h"
#include "GlobalMenuScene.h"

#include "Parallax.h"
#include "LandingEventManager.h"
#include "MenuEventManager.h"
#include "TutorialEventManager.h"
#include "GameEventManager.h"
using State = AnimatorController::AnimationState;

#include "Player.h"
#include "Projectile.h"
#include "TikeMyson_Player.h"
#include "Parallax.h"
#include "Boss.h"
#include <string>

const GameObject AssetManager::MainCamera = GameObject(
	"Main Camera", "MainCamera",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Camera>(Camera::Projection::Orthographic, 3),
});

#pragma region PlayerCharacters
	#pragma region TikeMyson
	const Texture2D AssetManager::MiniTikeMysonTexture = Texture2D("Assets/TikeMyson_Mini.png", Texture2D::FilterMode::Nearest, 3, 6);
	#pragma region Clips
		const AnimationClip MiniTikeMyson_Idle = AnimationClip({
			{ AssetManager::MiniTikeMysonTexture[0], 0.1f },
			{ AssetManager::MiniTikeMysonTexture[1], 0.1f },
			{ AssetManager::MiniTikeMysonTexture[2], 0.1f },
			}, true);
		const AnimationClip MiniTikeMyson_Walk = AnimationClip({
			{ AssetManager::MiniTikeMysonTexture[3], 0.1f },
			{ AssetManager::MiniTikeMysonTexture[4], 0.1f },
			{ AssetManager::MiniTikeMysonTexture[3], 0.1f },
			{ AssetManager::MiniTikeMysonTexture[5], 0.1f },
			}, true);
		const AnimationClip MiniTikeMyson_Jump = AnimationClip({
			{ AssetManager::MiniTikeMysonTexture[6], 0.1f },
			{ AssetManager::MiniTikeMysonTexture[7], 0.1f },
			{ AssetManager::MiniTikeMysonTexture[8], 0.1f }
			}, false);
	#pragma endregion
	const Texture2D AssetManager::BigTikeMysonTexture = Texture2D("Assets/TikeMyson_Big.png", Texture2D::FilterMode::Nearest, 8, 5);
	#pragma region Clips
		const AnimationClip BigTikeMyson_Idle = AnimationClip({
			{ AssetManager::BigTikeMysonTexture[8], 0.1f },
			{ AssetManager::BigTikeMysonTexture[9], 0.1f },
			{ AssetManager::BigTikeMysonTexture[10], 0.1f },
			{ AssetManager::BigTikeMysonTexture[11], 0.1f },
			{ AssetManager::BigTikeMysonTexture[12], 0.1f },
			{ AssetManager::BigTikeMysonTexture[13], 0.1f },
			}, true);
		const AnimationClip BigTikeMyson_Walk = AnimationClip({
			{ AssetManager::BigTikeMysonTexture[0], 0.1f },
			{ AssetManager::BigTikeMysonTexture[1], 0.1f },
			{ AssetManager::BigTikeMysonTexture[2], 0.1f },
			{ AssetManager::BigTikeMysonTexture[3], 0.1f },
			{ AssetManager::BigTikeMysonTexture[4], 0.1f },
			{ AssetManager::BigTikeMysonTexture[5], 0.1f },
			{ AssetManager::BigTikeMysonTexture[6], 0.1f },
			{ AssetManager::BigTikeMysonTexture[7], 0.1f },
			}, true);
		const AnimationClip BigTikeMyson_Jump = AnimationClip({
			{ AssetManager::BigTikeMysonTexture[9], 0.1f },
			{ AssetManager::BigTikeMysonTexture[10], 0.1f },
			{ AssetManager::BigTikeMysonTexture[11], 0.1f }
			}, false);
		const AnimationClip BigTikeMyson_Punch = AnimationClip({
			{ AssetManager::BigTikeMysonTexture[16], 0.1f },
			{ AssetManager::BigTikeMysonTexture[17], 0.1f },
			{ AssetManager::BigTikeMysonTexture[18], 0.1f },
			{ AssetManager::BigTikeMysonTexture[19], 0.1f },
			{ AssetManager::BigTikeMysonTexture[20], 0.1f },
			{ AssetManager::BigTikeMysonTexture[21], 0.1f },
			{ AssetManager::BigTikeMysonTexture[22], 0.1f },
			{ AssetManager::BigTikeMysonTexture[23], 0.1f },
			}, false);
	#pragma endregion
	const AnimatorController AssetManager::TikeMyson_Controller = AnimatorController({
		State("Mini_Idle", &MiniTikeMyson_Idle, {
			{ "Mini_Walk", false, 1, [](auto& animator) { return animator.GetBool("isWalking"); }},
		}),
		State("Mini_Walk", &MiniTikeMyson_Walk, {
			{ "Mini_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isWalking"); } },
		}),
		State("Mini_Jump", &MiniTikeMyson_Jump, {
			{ "Mini_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isJumping"); }},
		}),

		State("Big_Idle", &BigTikeMyson_Idle, {
			{ "Big_Walk", false, 1, [](auto& animator) { return animator.GetBool("isWalking"); }},
		}),
		State("Big_Walk", &BigTikeMyson_Walk, {
			{ "Big_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isWalking"); } },
		}),
		State("Big_Jump", &BigTikeMyson_Jump, {
			{ "Big_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isJumping"); }},
		}),
		State("Big_Punch", &BigTikeMyson_Punch, {
			{ "Big_Idle", true, 1 },
		}),
		});

	const GameObject AssetManager::TikeMysonObject = GameObject(
		"Tike Myson", "Player",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&MiniTikeMysonTexture[0], false, false),
			std::make_shared<Animator>(&TikeMyson_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<CircleCollider2D>(),
			std::make_shared<TikeMyson_Player>(),
	});
	#pragma endregion

	#pragma region Chicken

	#pragma endregion

#pragma endregion

#pragma region Enemies
	#pragma region Sensei
	const Texture2D AssetManager::Sensei_Texture = Texture2D("Assets/MasterWu.png", Texture2D::FilterMode::Nearest, 6, 6);
	#pragma region Clips
	const AnimationClip AssetManager::Sensei_Idle_Clip = AnimationClip({
		{ Sensei_Texture[0], 0.1f },
		{ Sensei_Texture[1], 0.1f },
		{ Sensei_Texture[2], 0.1f },
		}, true);
	const AnimationClip AssetManager::Sensei_Walking_Clip = AnimationClip({
		{ Sensei_Texture[6], 0.1f },
		{ Sensei_Texture[7], 0.1f },
		{ Sensei_Texture[8], 0.1f },
		}, true);
	const AnimationClip AssetManager::Sensei_Hadoken_Clip = AnimationClip({
		{ Sensei_Texture[12], 0.1f },
		{ Sensei_Texture[13], 0.1f },
		{ Sensei_Texture[14], 0.1f },
		}, true);
	const AnimationClip AssetManager::Sensei_CallsReinforcements_Clip = AnimationClip({
		{ Sensei_Texture[18], 0.1f },
		{ Sensei_Texture[19], 0.1f },
		{ Sensei_Texture[20], 0.1f },
		{ Sensei_Texture[21], 0.1f },
		{ Sensei_Texture[22], 0.1f },
		{ Sensei_Texture[23], 0.1f },
		}, true);
	const AnimationClip AssetManager::Sensei_CallingReinforcements_Clip = AnimationClip({
		{ Sensei_Texture[20], 0.1f },
		{ Sensei_Texture[21], 0.1f },
		{ Sensei_Texture[22], 0.1f },
		{ Sensei_Texture[23], 0.1f },
		}, true);
	const AnimationClip AssetManager::Sensei_TeleportOut_Clip = AnimationClip({
		{ Sensei_Texture[24], 0.1f },
		{ Sensei_Texture[25], 0.1f },
		{ Sensei_Texture[26], 0.1f },
		{ Sensei_Texture[27], 0.1f },
		{ Sensei_Texture[28], 0.1f },
		{ Sensei_Texture[29], 0.1f },
		}, true);
	const AnimationClip AssetManager::Sensei_TeleportIn_Clip = AnimationClip({
		{ Sensei_Texture[29], 0.1f },
		{ Sensei_Texture[28], 0.1f },
		{ Sensei_Texture[27], 0.1f },
		{ Sensei_Texture[26], 0.1f },
		{ Sensei_Texture[25], 0.1f },
		{ Sensei_Texture[24], 0.1f },
		}, true);
	const AnimationClip AssetManager::Sensei_Hurt_Clip = AnimationClip({
		{ Sensei_Texture[30], 0.1f },
		}, true);
	#pragma endregion
	const AnimatorController AssetManager::Sensei_Controller = AnimatorController({
		State("Idle", &Sensei_Idle_Clip, {
			{ "Walking", false, 1, [](auto& animator) { return animator.GetBool("isWalking"); } },
			{ "Hadoken", false, 1, [](auto& animator) { return animator.GetInteger("move") == 1; } },
			{ "Call", false, 1, [](auto& animator) { return animator.GetInteger("move") == 2; } },
			{ "TeleportOut", false, 1, [](auto& animator) { return animator.GetInteger("move") == 3; } },
		}),
		State("Walking", &Sensei_Walking_Clip, {
			{ "Idle", true, 1 },
		}),
		State("Hadoken", &Sensei_Hadoken_Clip, {
			{ "Idle", true, 1 },
		}),
		State("Call", &Sensei_CallsReinforcements_Clip, {
			{ "Calling", true, 1, [](auto& animator) { animator.SetInteger("move", 0); return true; } },
		}),
		State("Calling", &Sensei_CallingReinforcements_Clip, {
			{ "Idle", true, 3 },
		}),
		State("TeleportOut", &Sensei_TeleportOut_Clip, {
			{ "TeleportIn", true, 1, [](auto& animator) { animator.SetInteger("move", 0); return true; } },
		}),
		State("TeleportIn", &Sensei_TeleportIn_Clip, {
			{ "Idle", true, 1 },
		}),
		State("Hurt", &Sensei_Hurt_Clip, {
			{ "Idle", true, 1 },
		}),
		});

	const GameObject AssetManager::Sensei_Object = GameObject(
		"Boss", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&AssetManager::Sensei_Texture[0], false, false),
			std::make_shared<Animator>(&AssetManager::Sensei_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<CircleCollider2D>(),
			std::make_shared<Boss>(),

	});
	#pragma endregion
#pragma region Boss1
const Texture2D AssetManager::BossTexture = Texture2D("Assets/Boss_1_Phase1.png", Texture2D::FilterMode::Nearest, 8, 7);
	#pragma region Clips
	const AnimationClip AssetManager::Boss_Charging = AnimationClip({
		{ BossTexture[8], 0.1f },
		{ BossTexture[9], 0.1f },
		{ BossTexture[10], 0.1f },
		{ BossTexture[11], 0.1f },
		{ BossTexture[12], 0.1f },
		{ BossTexture[13], 0.1f },
		{ BossTexture[14], 0.1f },
		}, true);
	const AnimationClip AssetManager::Boss_Charged = AnimationClip({
		{ BossTexture[8], 0.1f },
		{ BossTexture[9], 0.1f },
		{ BossTexture[10], 0.1f },
		{ BossTexture[11], 0.1f },
		{ BossTexture[12], 0.1f },
		{ BossTexture[13], 0.1f },
		{ BossTexture[14], 0.1f },
		{ BossTexture[15], 0.1f },
		}, true);
	const AnimationClip AssetManager::Boss_Chomp_Indicator = AnimationClip({
		{ BossTexture[48], 0.1f },
		{ BossTexture[49], 0.1f },
		}, true);
	const AnimationClip AssetManager::Boss_Bomb_Indicator = AnimationClip({
		{ BossTexture[40], 0.1f },
		{ BossTexture[41], 0.1f },
		}, true);
	const AnimationClip AssetManager::Boss_Chomp_Attack = AnimationClip({
		{ BossTexture[16], 0.075f },
		{ BossTexture[17], 0.075f },
		{ BossTexture[18], 0.075f },
		{ BossTexture[19], 0.075f },
		{ BossTexture[20], 0.075f },
		{ BossTexture[21], 0.075f },
		{ BossTexture[22], 0.075f },
		{ BossTexture[23], 0.075f },
		}, true);
	const AnimationClip AssetManager::Boss_Bomb_Attack = AnimationClip({
		{ BossTexture[32], 0.05f },
		{ BossTexture[33], 0.05f },
		{ BossTexture[34], 0.05f },
		{ BossTexture[35], 0.05f },
		{ BossTexture[36], 0.05f },
		}, true);
	const AnimationClip AssetManager::Boss_Open = AnimationClip({
		{ BossTexture[0], 0.1f },
		{ BossTexture[1], 0.1f },
		{ BossTexture[2], 0.1f },
		{ BossTexture[3], 0.1f },
		{ BossTexture[4], 0.1f },
		{ BossTexture[5], 0.1f },
		{ BossTexture[6], 0.1f },
		{ BossTexture[7], 0.1f },
		}, true);
	const AnimationClip AssetManager::Boss_Close = AnimationClip({
		{ BossTexture[24], 0.1f },
		{ BossTexture[25], 0.1f },
		{ BossTexture[26], 0.1f },
		{ BossTexture[27], 0.1f },
		{ BossTexture[28], 0.1f },
		{ BossTexture[29], 0.1f },
		{ BossTexture[30], 0.1f },
		{ BossTexture[31], 0.1f },
		}, true);
	#pragma endregion
const AnimatorController AssetManager::Boss_Controller = AnimatorController({
	State("Charging", &Boss_Charging, {
		{ "Charged", false, 1, [](auto& animator) { return animator.GetInteger("move") > 0; } },
	}),
	State("Charged", &Boss_Charged, {
		{ "Open", true, 1 },
	}),
	State("Open", &Boss_Open, {
		{ "BombId", false, 1, [](auto& animator) { return animator.GetInteger("move") == 1; } },
		{ "ChompId", false, 1, [](auto& animator) { return animator.GetInteger("move") == 2; } },
	}),
	State("Close", &Boss_Close, {
		{ "Charging", true, 1, [](auto& animator) { animator.SetInteger("move", 0); return true; } },
	}),
	State("BombId", &Boss_Bomb_Indicator, {
		{ "BombAtk", true, 3 },
	}),
	State("ChompId", &Boss_Chomp_Indicator, {
		{ "ChompAtk", true, 3 },
	}),
	State("BombAtk", &Boss_Bomb_Attack, {
		{ "Close", true, 20 },
	}),
	State("ChompAtk", &Boss_Chomp_Attack, {
		{ "Close", true, 20 },
	}),
	});

const GameObject AssetManager::BossObject = GameObject(
	"Player", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::BossTexture[0], false, false),
		std::make_shared<Animator>(&AssetManager::Boss_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<BoxCollider2D>(),
		std::make_shared<Boss>(),
});
#pragma endregion
#pragma endregion

#pragma region Projectiles
	const Texture2D AssetManager::Projectile_Blue_Texture = Texture2D("Assets/Projectile_Blue.png", Texture2D::FilterMode::Nearest, 3, 1);
	const AnimationClip AssetManager::Projectile_Blue_Idle_Clip = AnimationClip({
		{ Projectile_Blue_Texture[0], 0.1f },
		{ Projectile_Blue_Texture[1], 0.1f },
		{ Projectile_Blue_Texture[2], 0.1f },
		}, true);
	const AnimatorController AssetManager::Projectile_Blue_Controller = AnimatorController({
		State("Idle", &Projectile_Blue_Idle_Clip),
		});
	const GameObject AssetManager::ProjectileObject_Blue = GameObject(
		"Projectile (Blue)", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Projectile_Blue_Texture[0], false, false),
			std::make_shared<Animator>(&Projectile_Blue_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<CircleCollider2D>(0.125f),
			std::make_shared<Projectile>(),
	});
	#pragma endregion


#pragma region UI

#pragma region Backgrounds

const Texture2D AssetManager::GalaxyBackground = Texture2D("Assets/GalaxyBackground.png", Texture2D::FilterMode::Nearest);
const GameObject GalaxyBackgroundObject = GameObject(
	"Background", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Parallax>(&AssetManager::GalaxyBackground[0], Vector2::left(), 0.05f),
});
#pragma endregion

#pragma region Menu
//const Texture2D AssetManager::GameTitle = Texture2D("Assets/GameTitle.png", Texture2D::FilterMode::Nearest);

const Texture2D MenuOptions = Texture2D("Assets/MenuOptions.png", Texture2D::FilterMode::Nearest);
const Texture2D PauseScreen = Texture2D("Assets/PauseScreen.png", Texture2D::FilterMode::Nearest);
const Texture2D PauseMessage = Texture2D("Assets/PauseMessage.png", Texture2D::FilterMode::Nearest);

const Texture2D AssetManager::Font = Texture2D("Assets/font.png", Texture2D::FilterMode::Nearest, 16, 8);

//{.targetState = "Run", .hasExitTime = false, .condition = [&]() { return false; } },
#pragma endregion

#pragma endregion

#pragma region Misc
//Misc
const Texture2D AssetManager::MountainBackground = Texture2D("Assets/MountainBackground.png", Texture2D::FilterMode::Nearest);
const Texture2D BossScene = Texture2D("Assets/MK-1_Intro.png", Texture2D::FilterMode::Nearest);


#pragma endregion

#pragma region Scenes
//Help Menu
#pragma region TutorialScene 
const Texture2D TutorialText = Texture2D("Assets/TutorialText.png", Texture2D::FilterMode::Nearest);
const GameObject TutorialTextObject = GameObject(
	"TutorialText", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&TutorialText[0]),
});
const GameObject TutorialEventManagerObject = GameObject(
	"TutorialEventManager", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<TutorialEventManager>(),
});
Scene Assets_Scenes::TutorialScene = Scene({
#pragma region Ui
	{&TutorialTextObject, Transform()},
	{&TutorialEventManagerObject, Transform()},
#pragma endregion

	{&AssetManager::MainCamera, Transform()},
	{&GalaxyBackgroundObject, Transform()},
	});

#pragma endregion


#pragma region GameScene
const Texture2D ForestBackgroundTexture = Texture2D("Assets/level_1.png", Texture2D::FilterMode::Linear);
const GameObject ForestBackgroundObject = GameObject(
	"Background", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Parallax>(&ForestBackgroundTexture[0], Vector2::left(), 0.1f),
});

const Texture2D AssetManager::Obstacle_Texture = Texture2D("Assets/Obstacle.png", Texture2D::FilterMode::Nearest, 3, 1);
const GameObject Ground = GameObject(
	"Ground", "Ground",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::Obstacle_Texture[0], false, false),
		std::make_shared<BoxCollider2D>(Vector2(1600, 1)),
});

const GameObject GameEventManagerObject = GameObject(
	"GameEventManager", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&PauseScreen[0]),
		std::make_shared<Image>(&PauseMessage[0]),
		std::make_shared<GameEventManager>(),
});
const GameObject OtherGameEventManagerObject = GameObject(
	"GameEventManager", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&TutorialText[0]),
		std::make_shared<GameEventManager>(),
});

Scene Assets_Scenes::GameScene = Scene({
#pragma region Ui
	{&GameEventManagerObject, Transform(Vector3(2, 0, 0))},
	{&OtherGameEventManagerObject, Transform(Vector3(-1, 0, 0))},
#pragma endregion

	{&AssetManager::MainCamera, Transform()},
	{&ForestBackgroundObject, Transform()},
	{&Ground, Transform(Vector3(0, -2, 0), Vector3::zero(), Vector3(50, 1, 1))},
	{&AssetManager::BossObject, Transform()},
	{&AssetManager::Sensei_Object, Transform()},
	//{&AssetManager::MiniTikeMysonObject, Transform()},
	//{&AssetManager::ObstacleSpawner_Object, Transform()},
	});

Scene Assets_Scenes::TestingScene = Scene({
#pragma region Ui
	{&GameEventManagerObject, Transform(Vector3(2, 0, 0))},
	{&OtherGameEventManagerObject, Transform(Vector3(-1, 0, 0))},
#pragma endregion

	{&AssetManager::MainCamera, Transform()},
	{&ForestBackgroundObject, Transform()},
	{&Ground, Transform(Vector3(0, -2, 0), Vector3::zero(), Vector3(50, 1, 1))},
	//{&AssetManager::BossObject, Transform()},
	{&AssetManager::Sensei_Object, Transform()},
	//{&AssetManager::MiniTikeMysonObject, Transform()},
	//{&AssetManager::ObstacleSpawner_Object, Transform()},
	});
#pragma endregion
#pragma endregion