#include "Prefab.h"
#include "GlobalMenuScene.h"

#include "Parallax.h"
#include "EventManagers/LandingEventManager.h"
#include "EventManagers/MenuEventManager.h"
#include "EventManagers/TutorialEventManager.h"
#include "EventManagers/GameEventManager.h"
using State = AnimatorController::AnimationState;

#include "Player.h"
#include "Projectile.h"
#include "Hitbox.h"
#include "TikeMyson_Player.h"
#include "Parallax.h"
#include "Boss.h"
#include <string>

#pragma region PlayerCharacters
	#pragma region TikeMyson
	const Texture2D Prefab::MiniTikeMysonTexture = Texture2D("Assets/TikeMyson_Mini.png", Texture2D::FilterMode::Nearest, 3, 6);
	#pragma region Clips
		const AnimationClip MiniTikeMyson_Idle = AnimationClip({
			{ Prefab::MiniTikeMysonTexture[0], 0.1f },
			{ Prefab::MiniTikeMysonTexture[1], 0.1f },
			{ Prefab::MiniTikeMysonTexture[2], 0.1f },
			}, true);
		const AnimationClip MiniTikeMyson_Walk = AnimationClip({
			{ Prefab::MiniTikeMysonTexture[3], 0.1f },
			{ Prefab::MiniTikeMysonTexture[4], 0.1f },
			{ Prefab::MiniTikeMysonTexture[3], 0.1f },
			{ Prefab::MiniTikeMysonTexture[5], 0.1f },
			}, true);
		const AnimationClip MiniTikeMyson_Jump = AnimationClip({
			{ Prefab::MiniTikeMysonTexture[6], 0.1f },
			{ Prefab::MiniTikeMysonTexture[7], 0.1f },
			{ Prefab::MiniTikeMysonTexture[8], 0.1f }
			}, false);
	#pragma endregion
	const Texture2D Prefab::BigTikeMysonTexture = Texture2D("Assets/TikeMyson_Big.png", Texture2D::FilterMode::Nearest, 8, 5);
	#pragma region Clips
		const AnimationClip BigTikeMyson_Idle = AnimationClip({
			{ Prefab::BigTikeMysonTexture[8], 0.1f },
			{ Prefab::BigTikeMysonTexture[9], 0.1f },
			{ Prefab::BigTikeMysonTexture[10], 0.1f },
			{ Prefab::BigTikeMysonTexture[11], 0.1f },
			{ Prefab::BigTikeMysonTexture[12], 0.1f },
			{ Prefab::BigTikeMysonTexture[13], 0.1f },
			}, true);
		const AnimationClip BigTikeMyson_Walk = AnimationClip({
			{ Prefab::BigTikeMysonTexture[0], 0.1f },
			{ Prefab::BigTikeMysonTexture[1], 0.1f },
			{ Prefab::BigTikeMysonTexture[2], 0.1f },
			{ Prefab::BigTikeMysonTexture[3], 0.1f },
			{ Prefab::BigTikeMysonTexture[4], 0.1f },
			{ Prefab::BigTikeMysonTexture[5], 0.1f },
			{ Prefab::BigTikeMysonTexture[6], 0.1f },
			{ Prefab::BigTikeMysonTexture[7], 0.1f },
			}, true);
		const AnimationClip BigTikeMyson_Jump = AnimationClip({
			{ Prefab::BigTikeMysonTexture[9], 0.1f },
			{ Prefab::BigTikeMysonTexture[10], 0.1f },
			{ Prefab::BigTikeMysonTexture[11], 0.1f }
			}, false);
		const AnimationClip BigTikeMyson_Punch = AnimationClip({
			{ Prefab::BigTikeMysonTexture[16], 0.1f },
			{ Prefab::BigTikeMysonTexture[17], 0.1f },
			{ Prefab::BigTikeMysonTexture[18], 0.1f },
			{ Prefab::BigTikeMysonTexture[19], 0.1f },
			{ Prefab::BigTikeMysonTexture[20], 0.1f },
			{ Prefab::BigTikeMysonTexture[21], 0.1f },
			{ Prefab::BigTikeMysonTexture[22], 0.1f },
			{ Prefab::BigTikeMysonTexture[23], 0.1f },
			}, false);
	#pragma endregion
	const AnimatorController Prefab::TikeMyson_Controller = AnimatorController({
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

	const GameObject Prefab::TikeMysonObject = GameObject(
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
	const Texture2D Prefab::Sensei_Texture = Texture2D("Assets/MasterWu.png", Texture2D::FilterMode::Nearest, 6, 6);
	#pragma region Clips
	const AnimationClip Sensei_Idle_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[0], 0.1f },
		{ Prefab::Sensei_Texture[1], 0.1f },
		{ Prefab::Sensei_Texture[2], 0.1f },
		}, true);
	const AnimationClip Sensei_Walking_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[6], 0.1f },
		{ Prefab::Sensei_Texture[7], 0.1f },
		{ Prefab::Sensei_Texture[8], 0.1f },
		}, true);
	const AnimationClip Sensei_Hadoken_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[12], 0.1f },
		{ Prefab::Sensei_Texture[13], 0.1f },
		{ Prefab::Sensei_Texture[14], 0.1f },
		}, true);
	const AnimationClip Sensei_CallsReinforcements_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[18], 0.1f },
		{ Prefab::Sensei_Texture[19], 0.1f },
		{ Prefab::Sensei_Texture[20], 0.1f },
		{ Prefab::Sensei_Texture[21], 0.1f },
		{ Prefab::Sensei_Texture[22], 0.1f },
		{ Prefab::Sensei_Texture[23], 0.1f },
		}, true);
	const AnimationClip Sensei_CallingReinforcements_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[20], 0.1f },
		{ Prefab::Sensei_Texture[21], 0.1f },
		{ Prefab::Sensei_Texture[22], 0.1f },
		{ Prefab::Sensei_Texture[23], 0.1f },
		}, true);
	const AnimationClip Sensei_TeleportOut_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[24], 0.1f },
		{ Prefab::Sensei_Texture[25], 0.1f },
		{ Prefab::Sensei_Texture[26], 0.1f },
		{ Prefab::Sensei_Texture[27], 0.1f },
		{ Prefab::Sensei_Texture[28], 0.1f },
		{ Prefab::Sensei_Texture[29], 0.1f },
		}, true);
	const AnimationClip Sensei_TeleportIn_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[29], 0.1f },
		{ Prefab::Sensei_Texture[28], 0.1f },
		{ Prefab::Sensei_Texture[27], 0.1f },
		{ Prefab::Sensei_Texture[26], 0.1f },
		{ Prefab::Sensei_Texture[25], 0.1f },
		{ Prefab::Sensei_Texture[24], 0.1f },
		}, true);
	const AnimationClip Sensei_Hurt_Clip = AnimationClip({
		{ Prefab::Sensei_Texture[30], 0.1f },
		}, true);
	#pragma endregion
	const AnimatorController Prefab::Sensei_Controller = AnimatorController({
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

	const GameObject Prefab::Sensei_Object = GameObject(
		"Boss", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Prefab::Sensei_Texture[0], false, false),
			std::make_shared<Animator>(&Prefab::Sensei_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<CircleCollider2D>(),
			std::make_shared<Boss>(),

	});
	#pragma endregion

	#pragma region Boss1
	const Texture2D Prefab::BossTexture = Texture2D("Assets/Boss_1_Phase1.png", Texture2D::FilterMode::Nearest, 8, 7);
		#pragma region Clips
		const AnimationClip Boss_Charging = AnimationClip({
			{ Prefab::BossTexture[8], 0.1f },
			{ Prefab::BossTexture[9], 0.1f },
			{ Prefab::BossTexture[10], 0.1f },
			{ Prefab::BossTexture[11], 0.1f },
			{ Prefab::BossTexture[12], 0.1f },
			{ Prefab::BossTexture[13], 0.1f },
			{ Prefab::BossTexture[14], 0.1f },
			}, true);
		const AnimationClip Boss_Charged = AnimationClip({
			{ Prefab::BossTexture[8], 0.1f },
			{ Prefab::BossTexture[9], 0.1f },
			{ Prefab::BossTexture[10], 0.1f },
			{ Prefab::BossTexture[11], 0.1f },
			{ Prefab::BossTexture[12], 0.1f },
			{ Prefab::BossTexture[13], 0.1f },
			{ Prefab::BossTexture[14], 0.1f },
			{ Prefab::BossTexture[15], 0.1f },
			}, true);
		const AnimationClip Boss_Chomp_Indicator = AnimationClip({
			{ Prefab::BossTexture[48], 0.1f },
			{ Prefab::BossTexture[49], 0.1f },
			}, true);
		const AnimationClip Boss_Bomb_Indicator = AnimationClip({
			{ Prefab::BossTexture[40], 0.1f },
			{ Prefab::BossTexture[41], 0.1f },
			}, true);
		const AnimationClip Boss_Chomp_Attack = AnimationClip({
			{ Prefab::BossTexture[16], 0.075f },
			{ Prefab::BossTexture[17], 0.075f },
			{ Prefab::BossTexture[18], 0.075f },
			{ Prefab::BossTexture[19], 0.075f },
			{ Prefab::BossTexture[20], 0.075f },
			{ Prefab::BossTexture[21], 0.075f },
			{ Prefab::BossTexture[22], 0.075f },
			{ Prefab::BossTexture[23], 0.075f },
			}, true);
		const AnimationClip Boss_Bomb_Attack = AnimationClip({
			{ Prefab::BossTexture[32], 0.05f },
			{ Prefab::BossTexture[33], 0.05f },
			{ Prefab::BossTexture[34], 0.05f },
			{ Prefab::BossTexture[35], 0.05f },
			{ Prefab::BossTexture[36], 0.05f },
			}, true);
		const AnimationClip Boss_Open = AnimationClip({
			{ Prefab::BossTexture[0], 0.1f },
			{ Prefab::BossTexture[1], 0.1f },
			{ Prefab::BossTexture[2], 0.1f },
			{ Prefab::BossTexture[3], 0.1f },
			{ Prefab::BossTexture[4], 0.1f },
			{ Prefab::BossTexture[5], 0.1f },
			{ Prefab::BossTexture[6], 0.1f },
			{ Prefab::BossTexture[7], 0.1f },
			}, true);
		const AnimationClip Boss_Close = AnimationClip({
			{ Prefab::BossTexture[24], 0.1f },
			{ Prefab::BossTexture[25], 0.1f },
			{ Prefab::BossTexture[26], 0.1f },
			{ Prefab::BossTexture[27], 0.1f },
			{ Prefab::BossTexture[28], 0.1f },
			{ Prefab::BossTexture[29], 0.1f },
			{ Prefab::BossTexture[30], 0.1f },
			{ Prefab::BossTexture[31], 0.1f },
			}, true);
		#pragma endregion
	const AnimatorController Prefab::Boss_Controller = AnimatorController({
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

	const GameObject Prefab::BossObject = GameObject(
		"Player", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Prefab::BossTexture[0], false, false),
			std::make_shared<Animator>(&Prefab::Boss_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<BoxCollider2D>(),
			std::make_shared<Boss>(),
	});
	#pragma endregion
#pragma endregion

#pragma region Projectiles
	const Texture2D Prefab::Projectile_Blue_Texture = Texture2D("Assets/Projectile_Blue.png", Texture2D::FilterMode::Nearest, 3, 1);
	const AnimationClip Projectile_Blue_Idle_Clip = AnimationClip({
		{ Prefab::Projectile_Blue_Texture[0], 0.1f },
		{ Prefab::Projectile_Blue_Texture[1], 0.1f },
		{ Prefab::Projectile_Blue_Texture[2], 0.1f },
		}, true);
	const AnimatorController Prefab::Projectile_Blue_Controller = AnimatorController({
		State("Idle", &Projectile_Blue_Idle_Clip),
		});
	const GameObject Prefab::ProjectileObject_Blue = GameObject(
		"Projectile (Blue)", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Projectile_Blue_Texture[0], false, false),
			std::make_shared<Animator>(&Projectile_Blue_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<CircleCollider2D>(0.125f),
			std::make_shared<Projectile>(8, 1.5f),
			std::make_shared<Hitbox>(),
	});
	#pragma endregion

#pragma region UI Items
const Texture2D Prefab::PauseScreen = Texture2D("Assets/PauseScreen.png", Texture2D::FilterMode::Nearest);


const Texture2D BossScene = Texture2D("Assets/MK-1_Intro.png", Texture2D::FilterMode::Nearest);


#pragma region Scenes
//Help Menu

//Scene GlobalMenuScene::TutorialScene = Scene({
//#pragma region Ui
//	{&TutorialTextObject, Transform()},
//	{&TutorialEventManagerObject, Transform()},
//#pragma endregion
//
//	{&AssetManager::MainCamera, Transform()},
//	{&GalaxyBackgroundObject, Transform()},
//	});
//
#pragma endregion


#pragma region GameScene


//Scene GlobalMenuScene::Scene = Scene({
//#pragma region Ui
//	{&GameEventManagerObject, Transform(Vector3(2, 0, 0))},
//	{&OtherGameEventManagerObject, Transform(Vector3(-1, 0, 0))},
//#pragma endregion
//
//	{&AssetManager::MainCamera, Transform()},
//	{&ForestBackgroundObject, Transform()},
//	{&Ground, Transform(Vector3(0, -2, 0), Vector3::zero(), Vector3(50, 1, 1))},
//	{&AssetManager::BossObject, Transform()},
//	{&AssetManager::Sensei_Object, Transform()},
//	//{&AssetManager::MiniTikeMysonObject, Transform()},
//	//{&AssetManager::ObstacleSpawner_Object, Transform()},
//	});

//Scene GlobalMenuScene::TestingScene = Scene({
//#pragma region Ui
//	{&GameEventManagerObject, Transform(Vector3(2, 0, 0))},
//	{&OtherGameEventManagerObject, Transform(Vector3(-1, 0, 0))},
//#pragma endregion
//
//	{&AssetManager::MainCamera, Transform()},
//	{&ForestBackgroundObject, Transform()},
//	{&Ground, Transform(Vector3(0, -2, 0), Vector3::zero(), Vector3(50, 1, 1))},
//	//{&AssetManager::BossObject, Transform()},
//	{&AssetManager::Sensei_Object, Transform()},
//	//{&AssetManager::MiniTikeMysonObject, Transform()},
//	//{&AssetManager::ObstacleSpawner_Object, Transform()},
//	});
#pragma endregion

#pragma endregion