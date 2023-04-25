#pragma once
#include "SealEngine.h"

using namespace SealEngine;
class ObstacleSpawner : public MonoBehaviour{
public:
	//ObstacleSpawner();
	void Update() override;
	std::shared_ptr<ObstacleSpawner> Clone() const { return std::shared_ptr<ObstacleSpawner>(Clone_impl()); }
	const float spawnDelay = 1.0f;
	float nextSpawnTime = currentTime + spawnDelay;
	float currentTime = Time::time();
private:
	virtual ObstacleSpawner* Clone_impl() const override { return new ObstacleSpawner(*this); }
};

