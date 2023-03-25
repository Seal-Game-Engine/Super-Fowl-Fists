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
	static int frameId = 0;

	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lastAnimatedFrame).count() > 200) {
		renderer.sprite = &AssetManager::GreenSlime[idleFrames.get()[frameId++ % 2]];
		lastAnimatedFrame = std::chrono::high_resolution_clock::now();
	}
}
