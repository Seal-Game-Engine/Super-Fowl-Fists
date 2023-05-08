#include "../SealEngine.h"
#include "../Parallax.h"
#include "../GameEventManager.h"
#include "../GlobalMenuScene.h"
#include "TestScene.h"

#include "../Testing/XwingPlayer.h"
#include "../Testing/Obstacle.h"
#include "../Testing/ObstacleSpawner.h"

using namespace SealEngine;
using namespace SealEngine::Ui;
using State = AnimatorController::AnimationState;

const Texture2D TutorialText = Texture2D("Assets/TutorialText.png", Texture2D::FilterMode::Nearest);
const Texture2D Obstacle_Texture = Texture2D("Assets/Obstacle.png", Texture2D::FilterMode::Nearest, 3, 1);

#pragma region Xwing
	#pragma region Ship
	const Texture2D Xwing_Texture = Texture2D("Assets/X-wing.png", Texture2D::FilterMode::Nearest, 3, 2);
	#pragma region Clips
	const AnimationClip Xwing_Idle = AnimationClip({
		{ Xwing_Texture[0], 0.05f },
		{ Xwing_Texture[3], 0.05f },
		}, true);
	const AnimationClip Xwing_Left = AnimationClip({
		{ Xwing_Texture[1], 0.05f },
		{ Xwing_Texture[4], 0.05f },
		}, true);
	const AnimationClip Xwing_Right = AnimationClip({
		{ Xwing_Texture[2], 0.05f },
		{ Xwing_Texture[5], 0.05f },
		}, true);
	#pragma endregion
	const AnimatorController Xwing_Controller = AnimatorController({
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
	const GameObject Xwing_Object = GameObject(
		"Xwing", "Player",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Xwing_Texture[0], false, false),
			std::make_shared<Animator>(&Xwing_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<CircleCollider2D>(0.25f, false, Vector2(0, -0.0625)),
			//std::make_shared<BoxCollider2D>(Vector2(0.5f, 0.5f), false, Vector2(0, -0.0625f)),
			std::make_shared<XwingPlayer>(),
			std::make_shared<AudioSource>("Assets/faded.wav"),
	});
	#pragma endregion
	
	#pragma region Obstacle
	//Obstacle
	const Texture2D TestScene::Obstacle_Texture = Texture2D("Assets/Obstacle.png", Texture2D::FilterMode::Nearest, 3, 1);
	const AnimationClip TestScene::Obstacle_Idle_Clip = AnimationClip({
		{ Obstacle_Texture[0], 0.2f },
		{ Obstacle_Texture[1], 0.3f },
		{ Obstacle_Texture[2], 0.2f },
		{ Obstacle_Texture[1], 0.3f },
		}, true);
	const AnimatorController TestScene::Obstacle_Controller = AnimatorController({ State("Idle", &Obstacle_Idle_Clip, {}) });
	const GameObject TestScene::Obstacle_Object = GameObject(
		"Obstacle", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&TestScene::Obstacle_Texture[0], false, false),
			std::make_shared<Animator>(&TestScene::Obstacle_Controller),
			std::make_shared<Rigidbody2D>(),
			std::make_shared<BoxCollider2D>(Vector2(1, 1)),
			std::make_shared<Obstacle>()
	});

	//ObstaclesSpawner
	const GameObject ObstacleSpawner_Object = GameObject(
		"ObstacleSpawner_Object", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<ObstacleSpawner>(),
	});
	#pragma endregion

#pragma endregion

#pragma region Scene
const Texture2D SpaceBackground_Texture = Texture2D("Assets/SpaceBackground.png", Texture2D::FilterMode::Nearest);
const GameObject SpaceBackgroundObject = GameObject(
	"Background", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Parallax>(&SpaceBackground_Texture[0], Vector2::down(), 0.1f),
});
const Texture2D PauseScreen = Texture2D("Assets/PauseScreen.png", Texture2D::FilterMode::Nearest);
const Texture2D PauseMessage = Texture2D("Assets/PauseMessage.png", Texture2D::FilterMode::Nearest);
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

const GameObject Ground = GameObject(
	"Ground", "Ground",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<SpriteRenderer>(&Obstacle_Texture[0], false, false),
		std::make_shared<BoxCollider2D>(Vector2(1600, 1)),
});

const GameObject ButtonTest = GameObject(
	"Button", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	//std::make_shared<Image>(&AssetManager::Font[0]),
		/*std::make_shared<Button>([] {
		SceneManager::LoadScene(1);
			}),*/
});

Scene Assets_Scenes::XwingScene = Scene({
#pragma region Ui
	{&GameEventManagerObject, Transform(Vector3(2, 0, 0))},
	{&OtherGameEventManagerObject, Transform(Vector3(-1, 0, 0))},
	{&ButtonTest, Transform(Vector2(-3, 2))},
#pragma endregion

	{&AssetManager::MainCamera, Transform()},
	{&SpaceBackgroundObject, Transform()},
	{&Ground, Transform(Vector3(0, -2, 0), Vector3::zero(), Vector3(50, 1, 1))},
	{&Xwing_Object, Transform(Vector3(0, -1, 0))},
	//{&ObstacleSpawner_Object, Transform()},
	});
#pragma endregion