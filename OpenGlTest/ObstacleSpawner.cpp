#include "ObstacleSpawner.h"
#include "AssetManager.h"

void ObstacleSpawner::Update() {
	if (Time::time() >= nextSpawnTime) {
		float x = (rand() % 14) - 7;
		float y = (rand() % 4) - 3;
		Object::Instantiate(AssetManager::ObstacleObject, Vector3(x, y, 0), Transform());
		nextSpawnTime = Time::time() + spawnDelay;
	}
}
