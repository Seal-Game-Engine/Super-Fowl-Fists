#include "Assets_Scenes.h"
#include "AssetManager.h"
#include "Parallax.h"
#include "GameEventManager.h"
#include "LandingEventManager.h"

Scene Assets_Scenes::LandingScene = Scene({
	{AssetManager::GalaxyBackgroundObject, Transform()},
	{GameObject(
		"Title",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&AssetManager::GameTitle[0], false, false),
	}),	Transform()},
	{GameObject(
		"LandingEventManager",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<LandingEventManager>(),
	}), Transform()},
	});

Scene Assets_Scenes::MenuScene = Scene({
	{AssetManager::GalaxyBackgroundObject, Transform()},
	
	});

Scene Assets_Scenes::TutorialScene = Scene({
	{AssetManager::GalaxyBackgroundObject, Transform()},
	
	});

Scene Assets_Scenes::GameScene = Scene({
	/*{GameObject(
		"Background",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Parallax>(&AssetManager::SpaceBackground[0], Vector2::down(), 0.1f),
	}), Transform()},

	{AssetManager::XwingObject, Transform(Vector3(0, -1, 0))},

	{GameObject(
		"Button",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&AssetManager::GreenSlime[1], false, false),
			std::make_shared<Button>(),
	}), Transform()},

	{GameObject(
		"GameEventManager",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&AssetManager::PauseScreen[0], false, false),
		std::make_shared<GameEventManager>(),
	}), Transform()},*/
	});

std::vector<Scene> Assets_Scenes::scenes = std::vector<Scene>{
	GameScene,
	LandingScene,
};