#pragma once
#include "SealEngine.h"
#include "AssetManager.h"
using namespace SealEngine;

class Assets_Scenes{
public:
	static std::vector<Scene> scenes;

	static Scene LandingScene;	//0
	static Scene MenuScene;		//1
	static Scene TutorialScene;	//2
	static Scene TestingScene;	//3
	static Scene XwingScene;	//4
	static Scene GameScene;		//5
};
