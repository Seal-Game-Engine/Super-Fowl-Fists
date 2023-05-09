#include "GlobalGameScene.h"
#include "TutorialEventManager.h"
#include "GameEventManager.h" 
#include "Prefab.h"
#include "Parallax.h"

#pragma region Shared Assets
const Texture2D Random_Texture = Texture2D("Assets/Game_Lv0.png", Texture2D::FilterMode::Nearest);
const GameObject MainCamera = GameObject(
	"Main Camera", "MainCamera",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Camera>(Camera::Projection::Orthographic, 3),
});
const GameObject GameEventManagerObject = GameObject(		//Game Interactions (ie: pause)
	"GameEventManager", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&Prefab::PauseScreen[0]),
		//std::make_shared<Image>(&PauseMessage[0]),
		std::make_shared<GameEventManager>(),
});
	const GameObject Ground = GameObject(
		"Ground", "Ground",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&Random_Texture[0], false, false),
			std::make_shared<BoxCollider2D>(Vector2(1600, 1)),
	});

	const Texture2D Prefab::Obstacle_Texture = Texture2D("Assets/Obstacle.png", Texture2D::FilterMode::Nearest, 3, 1);
#pragma endregion

#pragma region TutorialScene 

	#pragma region TutorialScene Assets
const Texture2D TutorialScene_Texture = Texture2D("Assets/Game_Tutorial.png", Texture2D::FilterMode::Nearest,1,1,192);
	const Texture2D TutorialText = Texture2D("Assets/TutorialText.png", Texture2D::FilterMode::Nearest);
	const GameObject TutorialUIObject = GameObject(
		"TutorialText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&TutorialText[0]),
		std::make_shared<Image>(&TutorialScene_Texture[0])
	});
	#pragma endregion

	#pragma region TutorialScene Properties
	Scene GlobalGameScene::TutorialScene = Scene({
	{&TutorialUIObject, Transform()},
	{&GameEventManagerObject, Transform()},
	{&MainCamera, Transform()},
	});
	#pragma endregion

#pragma endregion

#pragma region Lv0Scene

	#pragma region Lv0Scene Assets
	const Texture2D Lv0Scene_Texture = Texture2D("Assets/Game_Lv0.png", Texture2D::FilterMode::Nearest);
	const GameObject Lv0Scene_Object = GameObject(
		"Background", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		//std::make_shared<Image>(&Lv0Scene_Texture[0]),
	});
	#pragma endregion

	#pragma region Lv0Scene Properties
	Scene GlobalGameScene::Lv0Scene = Scene({
	{&Lv0Scene_Object, Transform()},
	{&GameEventManagerObject, Transform()},
	{&Ground, Transform()},
	{&MainCamera, Transform()},
		});
	#pragma endregion

#pragma endregion

#pragma region Lv1Scene

	#pragma region Lv1Scene Assets
	const Texture2D Lv1Scene_Texture = Texture2D("Assets/Game_Lv1.png", Texture2D::FilterMode::Linear);
	const GameObject Lv1Scene_Object = GameObject(
		"Background", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Parallax>(&Lv1Scene_Texture[0], Vector2::left(), 0.1f),
	});

	#pragma endregion

	#pragma region Lv1Scene Properties
	Scene GlobalGameScene::Lv1Scene = Scene({
	{&Lv1Scene_Object, Transform()},
	{&GameEventManagerObject, Transform()},
	{&Ground, Transform()},
	{&MainCamera, Transform()},
		});
	#pragma endregion

#pragma endregion