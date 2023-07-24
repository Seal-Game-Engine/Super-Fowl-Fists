#pragma once
#include "SealEngine.h"
#include "Prefab.h"
using namespace SealEngine;

class GlobalGameScene {
public:
	static std::vector<Scene> scenes;

	static Scene TutorialScene;	//0
	static Scene Lv0Scene;		//1
	static Scene Lv1Scene;	//2
};

