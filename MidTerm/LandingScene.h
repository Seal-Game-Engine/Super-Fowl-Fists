#pragma once
#include "SealEngine.h"
using namespace SealEngine;

#include "Obstacle.h"
class Obstacle;

class LandingScene : public Scene {
public:
	LandingScene();

	void Load() override;
	void Refresh() override;

	static std::vector<std::unique_ptr<Obstacle>> obstacles;
};

