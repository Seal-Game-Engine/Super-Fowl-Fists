#pragma once
#include "SealEngine.h"
#include "AssetManager.h"
using namespace SealEngine;

class Assets_Scenes{
public:
	static std::vector<Scene> scenes;

	static Scene LandingScene;
	static Scene MenuScene;
	static Scene TutorialScene;
	static Scene NarioScene;
	static Scene XwingScene;
	static Scene GameScene;
};
