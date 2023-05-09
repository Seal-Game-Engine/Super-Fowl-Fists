#include "ObstacleSpawner.h"
#include "../Prefab.h"
#include "../Testing/TestScene.h"

void ObstacleSpawner::Update() {
	if (Time::time() >= nextSpawnTime) {
		int x = (rand() % 7) - 3;
		int y = (rand() % 4) - 3;
		Object::Instantiate(TestScene::Obstacle_Object, Vector3(x, y, 0));
		nextSpawnTime = Time::time() + spawnDelay;
	}
}
