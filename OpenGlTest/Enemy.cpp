#include "Enemy.h"
#include "AssetManager.h"

Enemy::Enemy() {
	renderer._transform = &transform;
	renderer.sprite = &AssetManager::GreenSlime[1];
	animator.SetAnimatorController(&AssetManager::GreenSlime_Controller);
	animator.renderer = &renderer;
	runSpeed = 0;
	jumpSpeed = 0;
	actionTrigger = 0;
}

void Enemy::Actions(int action){

}

void Enemy::Update(){
}

void Enemy::LateUpdate(){

}
