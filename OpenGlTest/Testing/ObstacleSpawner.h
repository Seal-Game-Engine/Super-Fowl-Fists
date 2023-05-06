#pragma once
#include "../SealEngine.h"

using namespace SealEngine;
class ObstacleSpawner : public MonoBehaviour{
public:
	void Update() override;

	const float spawnDelay = 2.0f;
	float nextSpawnTime = currentTime + spawnDelay;
	float currentTime = Time::time();
private:
	ObstacleSpawner* _Clone() const override { return new ObstacleSpawner(*this); }
};

