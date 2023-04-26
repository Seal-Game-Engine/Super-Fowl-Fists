#include "AssetManager.h"
#include "Assets_Scenes.h"

#include "Parallax.h"
#include "LandingEventManager.h"
#include "MenuEventManager.h"
#include "TutorialEventManager.h"
#include "GameEventManager.h"
using State = AnimatorController::AnimationState;

#include "Player.h"
#include "Projectile.h"
#include "Parallax.h"

const Texture2D AssetManager::Hector_Run = Texture2D("Assets/Hector_Run.png", Texture2D::FilterMode::Nearest, 4, 3);
const AnimationClip AssetManager::Hector_Idle = AnimationClip({
	{ Hector_Run[1], 0.05f },
	{ Hector_Run[5], 0.05f },
	{ Hector_Run[1], 0.05f },
	{ Hector_Run[9], 0.05f },
}, true);
const AnimationClip AssetManager::Hector_IdleN = AnimationClip({
	{ Hector_Run[0], 0.05f },
	{ Hector_Run[4], 0.05f },
	{ Hector_Run[0], 0.05f },
	{ Hector_Run[8], 0.05f },
}, true);
const AnimatorController AssetManager::Hector_Controller = AnimatorController({
	State("Idle", &Hector_Idle, {
		{"IdleN", false, 1, [](auto& animator) { return animator.GetInteger("y") >= 0; } },
	}),
	State("IdleN", &Hector_IdleN, {
		{"Idle", false, 1, [](auto& animator) { return animator.GetInteger("y") < 0; } },
	}),
});
const GameObject AssetManager::HectorObject = GameObject(
	"Hector",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::Hector_Run[1], false, false),
		std::make_shared<Animator>(&AssetManager::Hector_Controller),
		std::make_shared<Player>(),
});

const Texture2D AssetManager::Xwing = Texture2D("Assets/X-wing.png", Texture2D::FilterMode::Nearest, 3, 2);
const AnimationClip AssetManager::Xwing_Idle = AnimationClip({
	{ Xwing[0], 0.05f },
	{ Xwing[3], 0.05f },
}, true);
const AnimationClip AssetManager::Xwing_Left = AnimationClip({
	{ Xwing[1], 0.05f },
	{ Xwing[4], 0.05f },
}, true);
const AnimationClip AssetManager::Xwing_Right = AnimationClip({
	{ Xwing[2], 0.05f },
	{ Xwing[5], 0.05f },
}, true);
const AnimatorController AssetManager::Xwing_Controller = AnimatorController({
	State("Idle", &Xwing_Idle, {
		{ "Left", false, 1, [](auto& animator) { return animator.GetInteger("x") < 0; } },
		{ "Right", false, 1, [](auto& animator) { return animator.GetInteger("x") > 0; } },
	}),
	State("Left", &Xwing_Left, {
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") >= 0; } },
	}),
	State("Right", &Xwing_Right, {
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") <= 0; } },
	}),
});;
const GameObject AssetManager::XwingObject = GameObject(
	"Player",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::Xwing[0], false, false),
		std::make_shared<Animator>(&AssetManager::Xwing_Controller),
		std::make_shared<Player>(),
});

const Texture2D AssetManager::Projectile_Blue = Texture2D("Assets/Projectile_Blue.png", Texture2D::FilterMode::Nearest, 3, 1);
const AnimationClip AssetManager::Projectile_Blue_Idle = AnimationClip({
	{ Projectile_Blue[0], 0.1f },
	{ Projectile_Blue[1], 0.1f },
	{ Projectile_Blue[2], 0.1f },
}, true);
const AnimatorController AssetManager::Projectile_Blue_Controller = AnimatorController({
	State("Idle", &Projectile_Blue_Idle),
});
const GameObject AssetManager::ProjectileObject_Blue = GameObject(
	"Projectile (Blue)",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::Projectile_Blue[0], false, false),
		std::make_shared<Animator>(&AssetManager::Projectile_Blue_Controller),
		std::make_shared<Projectile>(),
});

const Texture2D AssetManager::SpaceBackground = Texture2D("Assets/SpaceBackground.png", Texture2D::FilterMode::Nearest);
const Texture2D AssetManager::GalaxyBackground = Texture2D("Assets/GalaxyBackground.png", Texture2D::FilterMode::Nearest);
const GameObject GalaxyBackgroundObject = GameObject(
	"Background",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Parallax>(&AssetManager::GalaxyBackground[0], Vector2::left(), 0.05f),
});

const Texture2D AssetManager::GameTitle = Texture2D("Assets/GameTitle.png", Texture2D::FilterMode::Nearest);
const Texture2D AssetManager::MenuOptions = Texture2D("Assets/MenuOptions.png", Texture2D::FilterMode::Nearest);
const Texture2D AssetManager::PauseScreen = Texture2D("Assets/PauseScreen.png", Texture2D::FilterMode::Nearest);
const Texture2D AssetManager::PauseMessage = Texture2D("Assets/PauseMessage.png", Texture2D::FilterMode::Nearest);

const Texture2D AssetManager::Font = Texture2D("Assets/font.png", Texture2D::FilterMode::Nearest, 16, 8);
const Texture2D AssetManager::GreenSlime = Texture2D("Assets/GreenSlime.png", Texture2D::FilterMode::Nearest, 4, 2);
const AnimationClip AssetManager::GreenSlime_Idle = AnimationClip({
	{ GreenSlime[1], 0.15f },
	{ GreenSlime[5], 0.15f },
}, true);
const AnimatorController AssetManager::GreenSlime_Controller = AnimatorController({
	State("Idle", &GreenSlime_Idle, {
		//{.targetState = "Run", .hasExitTime = false, .condition = [&]() { return false; } },
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

#pragma region LandingScene
const GameObject TitleObject = GameObject(
	"Title",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::GameTitle[0], false, false),
});
const GameObject LandingEventManagerObject = GameObject(
	"LandingEventManager",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<LandingEventManager>(),
});

Scene Assets_Scenes::LandingScene = Scene({
	{&GalaxyBackgroundObject, Transform()},
	{&TitleObject, Transform()},
	{&LandingEventManagerObject, Transform()},
	});
#pragma endregion

#pragma region MenuScene
const Texture2D MenuText = Texture2D("Assets/MenuText.png", Texture2D::FilterMode::Nearest);
const GameObject MenuOptionsObject = GameObject(
	"MenuOptions",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::MenuOptions[0], false, false),
});
const GameObject MenuTextObject = GameObject(
	"MenuText",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&MenuText[0], false, false),
});
const GameObject MenuEventManagerObject = GameObject(
	"MenuEventManager",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::GreenSlime[1], false, false),
		std::make_shared<Animator>(&AssetManager::GreenSlime_Controller),
		std::make_shared<MenuEventManager>(),
});

Scene Assets_Scenes::MenuScene = Scene({
	{&GalaxyBackgroundObject, Transform()},
	{&MenuOptionsObject, Transform(Vector3(0, 0.05f, 0))},
	{&MenuTextObject, Transform(Vector3(-1.5f, -3, 0))},
	{&MenuEventManagerObject, Transform()},
	});
#pragma endregion


#pragma region TutorialScene
const Texture2D TutorialText = Texture2D("Assets/TutorialText.png", Texture2D::FilterMode::Nearest);
const GameObject TutorialTextObject = GameObject(
	"TutorialText",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&TutorialText[0], false, false),
});
const GameObject TutorialEventManagerObject = GameObject(
	"TutorialEventManager",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<TutorialEventManager>(),
});
Scene Assets_Scenes::TutorialScene = Scene({
	{&GalaxyBackgroundObject, Transform()},
	{&TutorialTextObject, Transform()},
	{&TutorialEventManagerObject, Transform()},
	});

#pragma endregion

#pragma region GameScene
const GameObject SpaceBackgroundObject = GameObject(
	"Background",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Parallax>(&AssetManager::SpaceBackground[0], Vector2::down(), 0.1f),
});
const GameObject GameEventManagerObject = GameObject(
	"GameEventManager",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&AssetManager::PauseScreen[0], false, false),
		std::make_shared<SpriteRenderer>(&AssetManager::PauseMessage[0], false, false),
		std::make_shared<GameEventManager>(),
});
Scene Assets_Scenes::GameScene = Scene({
	{&SpaceBackgroundObject, Transform()},
	{&AssetManager::XwingObject, Transform(Vector3(0, -1, 0))},

	/*{GameObject(
		"Button",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&AssetManager::GreenSlime[1], false, false),
			std::make_shared<Button>(),
	}), Transform()},*/

	{&GameEventManagerObject, Transform()},
	});
#pragma endregion


