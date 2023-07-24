#pragma once
#include "../SealEngine.h"

using namespace SealEngine;

class ObstacleSpawner : public MonoBehaviour{
public:
	void Update() override;

private:
	const float spawnDelay = 2.0f;
	float nextSpawnTime = 0;

	ObstacleSpawner* _Clone() const override { return new ObstacleSpawner(*this); }
};

