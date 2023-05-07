#include "ObstacleSpawner.h"
#include "../AssetManager.h"

void ObstacleSpawner::Update() {
	if (Time::time() >= nextSpawnTime) {
		int x = (rand() % 7) - 3;
		int y = (rand() % 4) - 3;
		Object::Instantiate(AssetManager::ObstacleObject, Vector3(x, y, 0));
		nextSpawnTime = Time::time() + spawnDelay;
	}
}
