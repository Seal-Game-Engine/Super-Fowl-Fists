#include "AssetManager.h"
using State = AnimatorController::AnimationState;

#include "Player.h"
#include "Projectile.h"
#include "Obstacle.h"
#include "ObstacleSpawner.h"

//Nario
const Texture2D AssetManager::Nario = Texture2D("Assets/Nario.png", Texture2D::FilterMode::Nearest, 3, 4);
const AnimationClip AssetManager::Nario_Idle = AnimationClip({
	{ Nario[0], 0.2f },
	{ Nario[1], 0.3f },
	{ Nario[0], 0.2f },
	{ Nario[2], 0.3f },
	}, true);
const AnimationClip AssetManager::Nario_Right = AnimationClip({
	{ Nario[3], 0.1f },
	{ Nario[4], 0.1f },
	{ Nario[3], 0.1f },
	{ Nario[5], 0.1f },
	}, true);
const AnimationClip AssetManager::Nario_Left = AnimationClip({
	{ Nario[6], 0.1f },
	{ Nario[7], 0.1f },
	{ Nario[6], 0.1f },
	{ Nario[8], 0.1f },
	}, true);
const AnimationClip AssetManager::Nario_Jump = AnimationClip({
	{ Nario[11], 0.1f }
	}, false);

const AnimatorController AssetManager::Nario_Controller = AnimatorController({
	State("Idle", &Nario_Idle, {
		{ "Left", false, 1, [](auto& animator) { return animator.GetInteger("x") < 0; } },
		{ "Right", false, 1, [](auto& animator) { return animator.GetInteger("x") > 0; } },
	}),
	State("Left", &Nario_Left, {
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") >= 0; } },
	}),
	State("Right", &Nario_Right, {
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") <= 0; } },
	}),
	State("Jump", &Nario_Jump, {
		{ "Idle", true, 3, [](auto& animator) { return true; } },
	}),
	});

const GameObject AssetManager::NarioObject = GameObject("Player", std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::Nario[0], false, false),
		std::make_shared<Animator>(&AssetManager::Nario_Controller),
		std::make_shared<Player>(),
		std::make_shared<Collider2D>()
});
//Obstacle
const Texture2D AssetManager::ObstacleTexture = Texture2D("Assets/Obstacle.png", Texture2D::FilterMode::Nearest, 3,1);
const AnimationClip AssetManager::Obstacle_Idle = AnimationClip({
	{ ObstacleTexture[0], 0.2f },
	{ ObstacleTexture[1], 0.3f },
	{ ObstacleTexture[2], 0.2f },
	{ ObstacleTexture[1], 0.3f },
	}, true);
const AnimatorController AssetManager::Obstacle_Controller = AnimatorController({State("Idle", &Obstacle_Idle, {})});
const GameObject AssetManager::ObstacleObject = GameObject("Obstacle", std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::ObstacleTexture[0], false, false),
		std::make_shared<Collider2D>(),
		std::make_shared<Animator>(&AssetManager::Obstacle_Controller),
		std::make_shared<Obstacle>()
});

//ObstaclesSpawner
const GameObject AssetManager::ObstacleSpawnerObject = GameObject("ObstacleSpawnerObject", std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<ObstacleSpawner>(),
});

//Misc
const Texture2D AssetManager::SkyBackground = Texture2D("Assets/SkyBackground.png", Texture2D::FilterMode::Nearest);
const Texture2D AssetManager::MountainBackground = Texture2D("Assets/MountainBackground.png", Texture2D::FilterMode::Nearest);
const Texture2D AssetManager::Googleplex = Texture2D("Assets/Googleplex.png", Texture2D::FilterMode::Linear);
