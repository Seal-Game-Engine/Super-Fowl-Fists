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
#include "Chicken_Player.h"
#include "Parallax.h"
//#include "Boss.h"
#include "Student.h"
#include "SenseiWu.h"
#include "Robot.h"
#include "Explosion.h"
#include <string>

#pragma region PlayerCharacters
	#pragma region TikeMyson
	const Texture2D Prefab::MiniTikeMyson_Texture = Texture2D("Assets/TikeMyson_Mini.png", Texture2D::FilterMode::Nearest, 3, 6);
	#pragma region Clips
		const AnimationClip MiniTikeMyson_Idle = AnimationClip({
			{ Prefab::MiniTikeMyson_Texture[0], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[1], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[2], 0.1f },
			}, true);
		const AnimationClip MiniTikeMyson_Walk = AnimationClip({
			{ Prefab::MiniTikeMyson_Texture[3], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[4], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[3], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[5], 0.1f },
			}, true);
		const AnimationClip MiniTikeMyson_Jump = AnimationClip({
			{ Prefab::MiniTikeMyson_Texture[6], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[7], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[8], 0.1f }
			}, false);
		const AnimationClip MiniTikeMyson_Attack = AnimationClip({
			{ Prefab::MiniTikeMyson_Texture[9], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[10], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[11], 0.1f }
			}, false);
		const AnimationClip MiniTikeMyson_Hurt = AnimationClip({
			{ Prefab::MiniTikeMyson_Texture[12], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[1], 0.1f },
			}, true);
		const AnimationClip MiniTikeMyson_Die = AnimationClip({
			{ Prefab::MiniTikeMyson_Texture[15], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[16], 0.1f },
			{ Prefab::MiniTikeMyson_Texture[17], 0.1f }
			}, false);
	#pragma endregion
	const Texture2D Prefab::BigTikeMyson_Texture = Texture2D("Assets/TikeMyson_Big.png", Texture2D::FilterMode::Nearest, 8, 6);
	#pragma region Clips
		const AnimationClip BigTikeMyson_Idle = AnimationClip({
			{ Prefab::BigTikeMyson_Texture[8], 0.1f },
			{ Prefab::BigTikeMyson_Texture[9], 0.1f },
			{ Prefab::BigTikeMyson_Texture[10], 0.1f },
			{ Prefab::BigTikeMyson_Texture[11], 0.1f },
			{ Prefab::BigTikeMyson_Texture[12], 0.1f },
			{ Prefab::BigTikeMyson_Texture[13], 0.1f },
			}, true);
		const AnimationClip BigTikeMyson_Walk = AnimationClip({
			{ Prefab::BigTikeMyson_Texture[0], 0.1f },
			{ Prefab::BigTikeMyson_Texture[1], 0.1f },
			{ Prefab::BigTikeMyson_Texture[2], 0.1f },
			{ Prefab::BigTikeMyson_Texture[3], 0.1f },
			{ Prefab::BigTikeMyson_Texture[4], 0.1f },
			{ Prefab::BigTikeMyson_Texture[5], 0.1f },
			{ Prefab::BigTikeMyson_Texture[6], 0.1f },
			{ Prefab::BigTikeMyson_Texture[7], 0.1f },
			}, true);
		const AnimationClip BigTikeMyson_Jump = AnimationClip({
			{ Prefab::BigTikeMyson_Texture[24], 0.05f },
			{ Prefab::BigTikeMyson_Texture[25], 0.05f },
			{ Prefab::BigTikeMyson_Texture[26], 0.05f },
			{ Prefab::BigTikeMyson_Texture[27], 0.1f },
			{ Prefab::BigTikeMyson_Texture[28], 0.1f },
			{ Prefab::BigTikeMyson_Texture[29], 0.1f }
			}, false);
		const AnimationClip BigTikeMyson_Power = AnimationClip({
			{ Prefab::BigTikeMyson_Texture[16], 0.1f },
			{ Prefab::BigTikeMyson_Texture[17], 0.1f },
			{ Prefab::BigTikeMyson_Texture[18], 0.1f },
			{ Prefab::BigTikeMyson_Texture[19], 0.1f },
			{ Prefab::BigTikeMyson_Texture[20], 0.1f },
			{ Prefab::BigTikeMyson_Texture[21], 0.1f },
			{ Prefab::BigTikeMyson_Texture[22], 0.1f },
			{ Prefab::BigTikeMyson_Texture[23], 0.1f },
			}, false);
		const AnimationClip BigTikeMyson_Punch = AnimationClip({
			{ Prefab::BigTikeMyson_Texture[32], 0.1f },
			{ Prefab::BigTikeMyson_Texture[33], 0.1f },
			{ Prefab::BigTikeMyson_Texture[34], 0.1f },
			}, false);
		const AnimationClip BigTikeMyson_Hurt = AnimationClip({
			{ Prefab::BigTikeMyson_Texture[40], 0.1f },
			{ Prefab::BigTikeMyson_Texture[8], 0.1f },
			}, true);
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
		State("Mini_Attack", &MiniTikeMyson_Attack, {
			{ "Mini_Idle", true, 1 },
		}),
		State("Mini_Hurt", &MiniTikeMyson_Hurt, {
			{ "Mini_Idle", true, 2 },
		}),
		State("Mini_Die", &MiniTikeMyson_Die),


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
		State("Big_Power", &BigTikeMyson_Power, {
			{ "Big_Idle", true, 1 },
		}),
		State("Big_Hurt", &BigTikeMyson_Hurt, {
			{ "Big_Idle", true, 2 },
		})
		});

	const GameObject Prefab::TikeMyson_Object = GameObject(
		"Tike Myson", "Entity",
		std::make_shared<SpriteRenderer>(&MiniTikeMyson_Texture[0]),
		std::make_shared<Animator>(&TikeMyson_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<CircleCollider2D>(),
		std::make_shared<AudioSource>(),
		std::make_shared<TikeMyson_Player>(10)
	);
	#pragma endregion

	#pragma region Chicken
	const Texture2D Prefab::MiniChicken_Texture = Texture2D("Assets/Chicken_Mini.png", Texture2D::FilterMode::Nearest, 3, 6);
#pragma region Clips
	const AnimationClip MiniChicken_Idle = AnimationClip({
		{ Prefab::MiniChicken_Texture[0], 0.1f },
		{ Prefab::MiniChicken_Texture[1], 0.1f },
		{ Prefab::MiniChicken_Texture[2], 0.1f },
		}, true);
	const AnimationClip MiniChicken_Walk = AnimationClip({
		{ Prefab::MiniChicken_Texture[3], 0.1f },
		{ Prefab::MiniChicken_Texture[4], 0.1f },
		{ Prefab::MiniChicken_Texture[3], 0.1f },
		{ Prefab::MiniChicken_Texture[5], 0.1f },
		}, true);
	const AnimationClip MiniChicken_Jump = AnimationClip({
		{ Prefab::MiniChicken_Texture[6], 0.1f },
		{ Prefab::MiniChicken_Texture[7], 0.1f },
		{ Prefab::MiniChicken_Texture[8], 0.1f }
		}, true);
	const AnimationClip MiniChicken_Attack = AnimationClip({
		{ Prefab::MiniChicken_Texture[9], 0.1f },
		{ Prefab::MiniChicken_Texture[10], 0.1f },
		{ Prefab::MiniChicken_Texture[11], 0.1f },
		}, false);
	const AnimationClip MiniChicken_Hurt = AnimationClip({
		{ Prefab::MiniChicken_Texture[12], 0.1f },
		{ Prefab::MiniChicken_Texture[1], 0.1f },
		}, true);
	const AnimationClip MiniChicken_Die = AnimationClip({
		{ Prefab::MiniChicken_Texture[15], 0.1f },
		{ Prefab::MiniChicken_Texture[16], 0.1f },
		{ Prefab::MiniChicken_Texture[17], 0.1f }
		}, false);
#pragma endregion
	const Texture2D Prefab::BigChicken_Texture = Texture2D("Assets/Chicken_Big.png", Texture2D::FilterMode::Nearest, 8, 6);
#pragma region Clips
	const AnimationClip BigChicken_Idle = AnimationClip({
		{ Prefab::BigChicken_Texture[8], 0.1f },
		{ Prefab::BigChicken_Texture[9], 0.1f },
		{ Prefab::BigChicken_Texture[10], 0.1f },
		{ Prefab::BigChicken_Texture[11], 0.1f },
		{ Prefab::BigChicken_Texture[12], 0.1f },
		{ Prefab::BigChicken_Texture[13], 0.1f },
		}, true);
	const AnimationClip BigChicken_Walk = AnimationClip({
		{ Prefab::BigChicken_Texture[0], 0.1f },
		{ Prefab::BigChicken_Texture[1], 0.1f },
		{ Prefab::BigChicken_Texture[2], 0.1f },
		{ Prefab::BigChicken_Texture[3], 0.1f },
		{ Prefab::BigChicken_Texture[4], 0.1f },
		{ Prefab::BigChicken_Texture[5], 0.1f },
		{ Prefab::BigChicken_Texture[6], 0.1f },
		{ Prefab::BigChicken_Texture[7], 0.1f },
		}, true);
	const AnimationClip BigChicken_Jump = AnimationClip({
		{ Prefab::BigChicken_Texture[24], 0.05f },
		{ Prefab::BigChicken_Texture[25], 0.05f },
		{ Prefab::BigChicken_Texture[26], 0.05f },
		{ Prefab::BigChicken_Texture[27], 0.1f },
		{ Prefab::BigChicken_Texture[28], 0.1f },
		{ Prefab::BigChicken_Texture[29], 0.1f }
		}, false);
	const AnimationClip BigChicken_Power = AnimationClip({
		{ Prefab::BigChicken_Texture[16], 0.1f },
		{ Prefab::BigChicken_Texture[17], 0.1f },
		{ Prefab::BigChicken_Texture[18], 0.1f },
		{ Prefab::BigChicken_Texture[19], 0.1f },
		{ Prefab::BigChicken_Texture[20], 0.1f },
		{ Prefab::BigChicken_Texture[21], 0.1f },
		}, false);
	const AnimationClip BigChicken_Punch = AnimationClip({
		{ Prefab::BigChicken_Texture[32], 0.1f },
		{ Prefab::BigChicken_Texture[33], 0.1f },
		{ Prefab::BigChicken_Texture[34], 0.1f },
		}, false);
	const AnimationClip BigChicken_Hurt = AnimationClip({
		{ Prefab::BigChicken_Texture[40], 0.1f },
		{ Prefab::BigChicken_Texture[8], 0.1f },
		}, true);
#pragma endregion
	const AnimatorController Prefab::Chicken_Controller = AnimatorController({
		State("Mini_Idle", &MiniChicken_Idle, {
			{ "Mini_Walk", false, 1, [](auto& animator) { return animator.GetBool("isWalking"); }},
		}),
		State("Mini_Walk", &MiniChicken_Walk, {
			{ "Mini_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isWalking"); } },
		}),
		State("Mini_Jump", &MiniChicken_Jump, {
			{ "Mini_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isJumping"); }},
		}),
		State("Mini_Attack", &MiniChicken_Attack, {
			{ "Mini_Idle", true, 1},
		}),
		State("Mini_Hurt", &MiniChicken_Hurt, {
			{ "Mini_Idle", true, 2 },
		}),
		State("Mini_Die", &MiniChicken_Die),


		State("Big_Idle", &BigChicken_Idle, {
			{ "Big_Walk", false, 1, [](auto& animator) { return animator.GetBool("isWalking"); }},
		}),
		State("Big_Walk", &BigChicken_Walk, {
			{ "Big_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isWalking"); } },
		}),
		State("Big_Jump", &BigChicken_Jump, {
			{ "Big_Idle", false, 1, [](auto& animator) { return !animator.GetBool("isJumping"); }},
		}),
		State("Big_Punch", &BigChicken_Punch, {
			{ "Big_Idle", true, 1 },
		}),
		State("Big_Power", &BigChicken_Power, {
			{ "Big_Idle", true, 1 },
		}),
		State("Big_Hurt", &BigChicken_Hurt, {
			{ "Big_Idle", true, 2 },
		}),
		});

	const GameObject Prefab::Chicken_Object = GameObject(
		"Chicken", "Entity",
		std::make_shared<SpriteRenderer>(&MiniChicken_Texture[0]),
		std::make_shared<Animator>(&Chicken_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<CircleCollider2D>(),
		std::make_shared<AudioSource>(),
		std::make_shared<Chicken_Player>(10)
	);
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
	const Texture2D Prefab::Sensei_Projectile_Texture = Texture2D("Assets/Projectile_Sensei.png", Texture2D::FilterMode::Nearest, 3);
	const AnimationClip Sensei_Projectile_Clip = AnimationClip({
		{ Prefab::Sensei_Projectile_Texture[0], 0.1f },
		{ Prefab::Sensei_Projectile_Texture[1], 0.1f },
		{ Prefab::Sensei_Projectile_Texture[2], 0.1f },
		}, true);
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
		"Boss", "Entity",
		std::make_shared<SpriteRenderer>(&Sensei_Texture[0]),
		std::make_shared<Animator>(&Sensei_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<CircleCollider2D>(0.4f),
		std::make_shared<SenseiWu>(50),
		std::make_shared<AudioSource>()
	);
	#pragma endregion

	#pragma region Students
	const Texture2D Prefab::Students_Texture = Texture2D("Assets/Students.png", Texture2D::FilterMode::Nearest, 3, 4);
	#pragma region Clips
	const AnimationClip Students_Idle_Clip = AnimationClip({
		{ Prefab::Students_Texture[0], 0.1f },
		{ Prefab::Students_Texture[1], 0.1f },
		{ Prefab::Students_Texture[2], 0.1f },
		}, true);
	const AnimationClip Students_Walking_Clip = AnimationClip({
		{ Prefab::Students_Texture[3], 0.1f },
		{ Prefab::Students_Texture[4], 0.1f },
		{ Prefab::Students_Texture[5], 0.1f },
		}, true);
	const AnimationClip Students_Attack_Clip = AnimationClip({
		{ Prefab::Students_Texture[6], 0.1f },
		{ Prefab::Students_Texture[7], 0.1f },
		{ Prefab::Students_Texture[8], 0.1f },
		}, true);
	#pragma endregion
	const AnimatorController Prefab::Students_Controller = AnimatorController({
		State("Idle", &Students_Idle_Clip, {
			{ "Walking", false, 1, [](auto& animator) { return animator.GetBool("isWalking"); } },
		}),
		State("Walking", &Students_Walking_Clip, {
			{ "Idle", true, 1 },
		}),
		State("Attack", &Students_Attack_Clip, {
			{ "Idle", true, 1 },
		}),
		});

	const GameObject Prefab::Students_Object = GameObject(
		"Students", "Entity",
		std::make_shared<SpriteRenderer>(&Prefab::Students_Texture[0], false, false),
		std::make_shared<Animator>(&Prefab::Students_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<CircleCollider2D>(0.4f),
		std::make_shared<AudioSource>(),
		std::make_shared<Student>(5),
		std::make_shared<Hitbox>(DamageData{ Factions::Faction2, 0.5, 1, nullptr })
	);
	#pragma endregion

	#pragma region Boss1
		const Texture2D Prefab::Boss_Texture = Texture2D("Assets/Boss_1_Phase1.png", Texture2D::FilterMode::Nearest, 8, 7);
		#pragma region Clips
		const AnimationClip Boss_Charging = AnimationClip({
			{ Prefab::Boss_Texture[8], 0.1f },
			{ Prefab::Boss_Texture[9], 0.1f },
			{ Prefab::Boss_Texture[10], 0.1f },
			{ Prefab::Boss_Texture[11], 0.1f },
			{ Prefab::Boss_Texture[12], 0.1f },
			{ Prefab::Boss_Texture[13], 0.1f },
			{ Prefab::Boss_Texture[14], 0.1f },
			}, true);
		const AnimationClip Boss_Charged = AnimationClip({
			{ Prefab::Boss_Texture[15], 0.5f },
			}, false);		
		const AnimationClip Boss_Open = AnimationClip({ //1s
			{ Prefab::Boss_Texture[0], 0.1f },
			{ Prefab::Boss_Texture[1], 0.1f },
			{ Prefab::Boss_Texture[2], 0.1f },
			{ Prefab::Boss_Texture[3], 0.1f },
			{ Prefab::Boss_Texture[4], 0.1f },
			{ Prefab::Boss_Texture[5], 0.1f },
			{ Prefab::Boss_Texture[6], 0.1f },
			{ Prefab::Boss_Texture[7], 0.3f },
			}, false);
		const AnimationClip Boss_Close = AnimationClip({ //0.8s
			{ Prefab::Boss_Texture[24], 0.1f },
			{ Prefab::Boss_Texture[25], 0.1f },
			{ Prefab::Boss_Texture[26], 0.1f },
			{ Prefab::Boss_Texture[27], 0.1f },
			{ Prefab::Boss_Texture[28], 0.1f },
			{ Prefab::Boss_Texture[29], 0.1f },
			{ Prefab::Boss_Texture[30], 0.1f },
			{ Prefab::Boss_Texture[31], 0.1f },
			}, false);

		const AnimationClip Boss_Chomp_Indicator = AnimationClip({
			{ Prefab::Boss_Texture[48], 0.1f },
			{ Prefab::Boss_Texture[49], 0.1f },
			}, true);
		const AnimationClip Boss_Bomb_Indicator = AnimationClip({
			{ Prefab::Boss_Texture[40], 0.1f },
			{ Prefab::Boss_Texture[41], 0.1f },
			}, true);
		const AnimationClip Boss_Chomp_Attack = AnimationClip({ //0.6s
			{ Prefab::Boss_Texture[16], 0.075f },
			{ Prefab::Boss_Texture[17], 0.075f },
			{ Prefab::Boss_Texture[18], 0.075f },
			{ Prefab::Boss_Texture[19], 0.075f },
			{ Prefab::Boss_Texture[20], 0.075f },//0.375s
			{ Prefab::Boss_Texture[21], 0.075f },//full chomp
			{ Prefab::Boss_Texture[22], 0.075f },
			{ Prefab::Boss_Texture[23], 0.075f },
			}, true);
		const AnimationClip Boss_Bomb_Attack = AnimationClip({ //0.25s
			{ Prefab::Boss_Texture[32], 0.05f },
			{ Prefab::Boss_Texture[33], 0.05f },
			{ Prefab::Boss_Texture[34], 0.05f },
			{ Prefab::Boss_Texture[35], 0.05f },
			{ Prefab::Boss_Texture[36], 0.05f },
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
			{ "BombId", true, 1, [](auto& animator) { return animator.GetInteger("move") == 1; } },
			{ "ChompId", true, 1, [](auto& animator) { return animator.GetInteger("move") == 2; } },
		}),
		State("Close", &Boss_Close, {
			{ "Charging", true, 1, },
		}),
		State("BombId", &Boss_Bomb_Indicator, {
			{ "BombAtk", true, 6 },
		}),
		State("ChompId", &Boss_Chomp_Indicator, {
			{ "ChompAtk", true, 6 },
		}),
		State("BombAtk", &Boss_Bomb_Attack),
		State("ChompAtk", &Boss_Chomp_Attack),
		});
	//Charged + Open = 1.5s
	//+ indicatord = 1.5s + 1.2s = 2.7s

	const GameObject Prefab::BossObject = GameObject(
		"Boss", "Entity",
		std::make_shared<SpriteRenderer>(&Boss_Texture[0]),
		std::make_shared<Animator>(&Boss_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<BoxCollider2D>(Vector2(1.875f, 2.625f), false, Vector2(0, -0.36875f)),
		std::make_shared<AudioSource>(),
		std::make_shared<Robot>(100)
	);
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
		"Projectile (Blue)", "Projectile",
		std::make_shared<SpriteRenderer>(&Projectile_Blue_Texture[0]),
		std::make_shared<Animator>(&Projectile_Blue_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<CircleCollider2D>(0.125f, true),
		std::make_shared<Projectile>(8, 1.5f),
		std::make_shared<AudioSource>(),
		std::make_shared<Hitbox>()
	);
#pragma endregion

#pragma region Bomb
const Texture2D Prefab::Bomb_Texture = Texture2D("Assets/Projectile_Bomb.png", Texture2D::FilterMode::Nearest, 4);
const AnimationClip Bomb_Clip = AnimationClip({
	{ Prefab::Bomb_Texture[0], 0.1f },
	{ Prefab::Bomb_Texture[1], 0.1f },
	{ Prefab::Bomb_Texture[2], 0.1f },
	{ Prefab::Bomb_Texture[3], 0.1f },
	}, true);
const AnimatorController Prefab::Bomb_Controller = AnimatorController({	State("Idle", &Bomb_Clip),	});
const GameObject Prefab::Bomb_Object = GameObject(
	"Bomb", "Projectile",
	std::make_shared<SpriteRenderer>(&Bomb_Texture[0]),
	std::make_shared<Animator>(&Bomb_Controller),
	std::make_shared<Rigidbody2D>(Rigidbody2D::BodyType::Dynamic, 1, 1.5f),
	std::make_shared<CircleCollider2D>(0.2f),
	std::make_shared<Projectile>(3, 5, Projectile::TraversalMethods::UseForce, true),
	std::make_shared<AudioSource>()
);
#pragma endregion

#pragma region BossProjectile
const Texture2D Prefab::BossProjectile_Texture = Texture2D("Assets/Projectile_MK-1.png", Texture2D::FilterMode::Nearest, 3);
const AnimationClip BossProjectile_Clip = AnimationClip({
	{ Prefab::BossProjectile_Texture[0], 0.1f },
	{ Prefab::BossProjectile_Texture[1], 0.1f },
	{ Prefab::BossProjectile_Texture[2], 0.1f },
	}, true);
const AnimatorController Prefab::BossProjectile_Controller = AnimatorController({ State("Idle", &BossProjectile_Clip), });
const GameObject Prefab::BossProjectile_Object = GameObject(
	"BossProjectile", "Projectile",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&BossProjectile_Texture[0]),
		std::make_shared<Animator>(&BossProjectile_Controller),
		std::make_shared<Rigidbody2D>(),
		std::make_shared<CircleCollider2D>(0.2f, true),
		std::make_shared<Projectile>(6, 2),
		std::make_shared<Hitbox>(),
		std::make_shared<AudioSource>(),
});
#pragma endregion

#pragma region Explosion32x32
	const Texture2D Prefab::Explosion32_Texture = Texture2D("Assets/Explosion_32x32.png", Texture2D::FilterMode::Nearest, 3, 4);
#pragma region Clips
	const AnimationClip Explosion32_Clip = AnimationClip({
		{ Prefab::Explosion32_Texture[0], 0.1f },
		{ Prefab::Explosion32_Texture[1], 0.1f },
		{ Prefab::Explosion32_Texture[2], 0.1f },
		{ Prefab::Explosion32_Texture[3], 0.1f },
		{ Prefab::Explosion32_Texture[4], 0.1f },
		{ Prefab::Explosion32_Texture[5], 0.1f },
		{ Prefab::Explosion32_Texture[6], 0.1f },
		{ Prefab::Explosion32_Texture[7], 0.1f },
		{ Prefab::Explosion32_Texture[8], 0.1f },
		{ Prefab::Explosion32_Texture[9], 0.1f },
		{ Prefab::Explosion32_Texture[10], 0.1f },
		{ Prefab::Explosion32_Texture[11], 0.1f },
		}, false);
#pragma endregion
	const AnimatorController Prefab::Explosion32_Controller = AnimatorController({		State("Idle", &Explosion32_Clip),		});
	const GameObject Prefab::Explosion32_Object = GameObject(
		"Explosion", "Projectile",
		std::make_shared<SpriteRenderer>(&Explosion32_Texture[0], false, false),
		std::make_shared<Animator>(&Explosion32_Controller),
		std::make_shared<CircleCollider2D>(0.5f, true),
		std::make_shared<Explosion>(1.2f),
		std::make_shared<AudioSource>(),
		std::make_shared<Hitbox>(DamageData{ Factions::Faction2, 1, 1, nullptr })
	);
#pragma endregion 

#pragma region Explosion64x64
	const Texture2D Prefab::Explosion64_Texture = Texture2D("Assets/Explosion_64x64.png", Texture2D::FilterMode::Nearest, 4, 4);
#pragma region Clips
	const AnimationClip Explosion64_Clip = AnimationClip({
		{ Prefab::Explosion64_Texture[0], 0.1f },
		{ Prefab::Explosion64_Texture[1], 0.1f },
		{ Prefab::Explosion64_Texture[2], 0.1f },
		{ Prefab::Explosion64_Texture[3], 0.1f },
		{ Prefab::Explosion64_Texture[4], 0.1f },
		{ Prefab::Explosion64_Texture[5], 0.1f },
		{ Prefab::Explosion64_Texture[6], 0.1f },
		{ Prefab::Explosion64_Texture[7], 0.1f },
		{ Prefab::Explosion64_Texture[8], 0.1f },
		{ Prefab::Explosion64_Texture[9], 0.1f },
		{ Prefab::Explosion64_Texture[10], 0.1f },
		{ Prefab::Explosion64_Texture[11], 0.1f },
		{ Prefab::Explosion64_Texture[12], 0.1f },
		{ Prefab::Explosion64_Texture[13], 0.1f },
		{ Prefab::Explosion64_Texture[14], 0.1f },
		{ Prefab::Explosion64_Texture[15], 0.1f },
		}, false);
#pragma endregion
	const AnimatorController Prefab::Explosion64_Controller = AnimatorController({ State("Idle", &Explosion64_Clip), });
	const GameObject Prefab::Explosion64_Object = GameObject(
		"Explosion", "Projectile",
		std::make_shared<SpriteRenderer>(&Explosion64_Texture[0], false, false),
		std::make_shared<Animator>(&Explosion64_Controller),
		//std::make_shared<CircleCollider2D>(0.5f, true),
		std::make_shared<Explosion>(1.6f)
		//std::make_shared<AudioSource>(),
		//std::make_shared<Hitbox>(),
		);
#pragma endregion 

#pragma region UI Items
const Texture2D Prefab::PauseScreen = Texture2D("Assets/PauseScreen.png", Texture2D::FilterMode::Nearest);

const Texture2D Prefab::WinScreen = Texture2D("Assets/LevelComplete.png", Texture2D::FilterMode::Nearest, 1, 1, 208);
const Texture2D Prefab::LoseScreen = Texture2D("Assets/Lose.png", Texture2D::FilterMode::Nearest, 1, 1, 208);

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