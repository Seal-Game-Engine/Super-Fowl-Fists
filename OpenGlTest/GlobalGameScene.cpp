#include "GlobalGameScene.h"
#include "EventManagers/TutorialEventManager.h"
#include "EventManagers/GameEventManager.h" 
#include "Prefab.h"
#include "Parallax.h"
using State = AnimatorController::AnimationState;

#pragma region Shared Assets

const GameObject MainCamera = GameObject(
	"Main Camera", "MainCamera",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Camera>(Camera::Projection::Orthographic, 2.5f),
});
#pragma region GameEventManager
const GameObject GameEventManagerObject = GameObject(		//Game Interactions (ie: pause)
	"GameEventManager", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&Prefab::PauseScreen[0]),
		//std::make_shared<Image>(&PauseMessage[0]),
		std::make_shared<GameEventManager>(),
});
#pragma endregion
#pragma region Ground
const GameObject Ground = GameObject(
	"Ground", "Ground",
	std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<BoxCollider2D>(Vector2(1600, 1)),
});
const GameObject Wall = GameObject(
	"Wall", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<BoxCollider2D>(Vector2(1, 1600)),
});

	const Texture2D Prefab::Obstacle_Texture = Texture2D("Assets/Obstacle.png", Texture2D::FilterMode::Nearest, 3, 1);
#pragma endregion
#pragma region UI
	#pragma region TikeMyson UI
	const Texture2D TikeMyson_UI_Texture = Texture2D("Assets/TikeMyson_UI.png", Texture2D::FilterMode::Nearest, 4, 1, 40);
	const AnimationClip TikeMyson_UI_Texture_Clip = AnimationClip({
		{TikeMyson_UI_Texture[0], 0.1f},
		{TikeMyson_UI_Texture[1], 0.1f},
		{TikeMyson_UI_Texture[2], 0.1f},
		{TikeMyson_UI_Texture[3], 0.1f},
		}, true);
	const AnimatorController TikeMyson_UI_Controller = AnimatorController({
		State("Mini_Idle", &TikeMyson_UI_Texture_Clip, {}) });
	const GameObject TikeMyson_UI_Object = GameObject(
		"Background", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&TikeMyson_UI_Texture[0]),
		std::make_shared<Animator>(&TikeMyson_UI_Controller),
	});

	#pragma endregion
	#pragma region Chicken UI
	const Texture2D Chicken_UI_Texture = Texture2D("Assets/Chicken_UI.png", Texture2D::FilterMode::Nearest, 4, 1, 40);
	const AnimationClip Chicken_UI_Texture_Clip = AnimationClip({
		{Chicken_UI_Texture[0], 0.1f},
		{Chicken_UI_Texture[1], 0.1f},
		{Chicken_UI_Texture[2], 0.1f},
		{Chicken_UI_Texture[3], 0.1f},
		}, true);
	const AnimatorController Chicken_UI_Controller = AnimatorController({
		State("Mini_Idle", &Chicken_UI_Texture_Clip, {}) });
	const GameObject Chicken_UI_Object = GameObject(
		"Background", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
			std::make_shared<Image>(&Chicken_UI_Texture[0]),
			std::make_shared<Animator>(&Chicken_UI_Controller)
	});
	#pragma endregion
#pragma endregion
#pragma endregion

#pragma region TutorialScene 

	#pragma region TutorialScene Assets
	const Texture2D TutorialScene_Texture = Texture2D("Assets/Background_TutorialScene.png", Texture2D::FilterMode::Nearest);
	const Texture2D TutorialText = Texture2D("Assets/TutorialText.png", Texture2D::FilterMode::Nearest);
	const GameObject TutorialUIObject = GameObject(
		"TutorialText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&TutorialText[0]),
		std::make_shared<SpriteRenderer>(&TutorialScene_Texture[0])
	});
	#pragma endregion

	#pragma region TutorialScene Properties
	Scene GlobalGameScene::TutorialScene = Scene({
	{&TutorialUIObject, Transform()},
	{&GameEventManagerObject, Transform()},
	{&Ground, Transform(Vector2(0, -3))},
	{&MainCamera, Transform()},
	});
	#pragma endregion

#pragma endregion

#pragma region Lv0Scene

	#pragma region Lv0Scene Assets
	const Texture2D Lv0Scene_Texture = Texture2D("Assets/Game_Lv0.png", Texture2D::FilterMode::Nearest);
	//const Texture2D Lv0Scene_Texture = Texture2D("Assets/Game_Lv0.png", Texture2D::FilterMode::Nearest);
	const GameObject Lv0Scene_Object = GameObject(
		"Background", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Lv0Scene_Texture[0]),
	});
	#pragma endregion

	#pragma region Lv0Scene Properties
	Scene GlobalGameScene::Lv0Scene = Scene({
	{&Lv0Scene_Object, Transform()},
	{&GameEventManagerObject, Transform()},
	{&Ground, Transform(Vector2(0, -2.3))},
	{&Wall, Transform(Vector2(-7.5,0))},
	{&Wall, Transform(Vector2(10,0))},
	{&TikeMyson_UI_Object, Transform(Vector2(-2.5,-1.9))},
	{&Chicken_UI_Object, Transform(Vector2(2.5,-1.9))},
	{&MainCamera, Transform()},
		});
	#pragma endregion

#pragma endregion

#pragma region Lv1Scene

	#pragma region Lv1Scene Assets
	const Texture2D Lv1Scene_Texture = Texture2D("Assets/Background_TutorialScene.png", Texture2D::FilterMode::Nearest);
	//const Texture2D Lv1Scene_Texture = Texture2D("Assets/Game_Lv1.png", Texture2D::FilterMode::Linear);
	const GameObject Lv1Scene_Object = GameObject(
		"Background", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Lv0Scene_Texture[0]),
		//std::make_shared<Parallax>(&Lv1Scene_Texture[0], Vector2::left(), 0.1f),
	});

	#pragma endregion

	#pragma region Lv1Scene Properties
	Scene GlobalGameScene::Lv1Scene = Scene({
	{&Lv1Scene_Object, Transform()},
	{&GameEventManagerObject, Transform()},
	{&Ground, Transform(Vector2(0, -2))},
	{&MainCamera, Transform()},
		});
	#pragma endregion

#pragma endregion