#include "ObstacleSpawner.h"
#include "AssetManager.h"

void ObstacleSpawner::Update() {
	if(Time::time() >= nextSpawnTime)
	{Object::Instantiate(AssetManager::ObstacleObject);
	nextSpawnTime = Time::time() + spawnDelay;}
	

}
