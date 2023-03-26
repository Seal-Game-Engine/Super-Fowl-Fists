#include "Enemy.h"
#include "AssetManager.h"

Enemy::Enemy() {
	renderer.sprite = &AssetManager::GreenSlime[1];
	runSpeed = 0;
	jumpSpeed = 0;
	actionTrigger = 0;
}

void Enemy::Actions(int action){

}

void Enemy::Update(){
}

void Enemy::LateUpdate(){
	static float frameId = 0;
	frameId += 5.0f * Time::deltaTime();
	renderer.sprite = &AssetManager::GreenSlime[idleFrames.get()[(int)frameId % 2]];
}
