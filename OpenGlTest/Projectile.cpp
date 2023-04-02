#include "Projectile.h"
#include "AssetManager.h"
#include "SceneManager.h"

int Projectile::idCounter = 0;

Projectile::Projectile(Vector3 position) : destroyTime(Time::time() + lifeSpan), id(idCounter++) {
	transform.position = position;
	transform.scale.Set(0.25f, 0.25f, 1);
	renderer._transform = &transform;
	renderer.sprite = &AssetManager::Projectile_Blue[0];
	animator.SetAnimatorController(&AssetManager::Projectile_Blue_Controller);
	animator.renderer = &renderer;
}

void Projectile::Update() {
	if (Time::time() >= destroyTime) {
		for (int i = 0; i < SceneManager::projectiles.size(); i++) {
			if (SceneManager::projectiles[i]->id == id) {
				SceneManager::projectiles.erase(SceneManager::projectiles.begin() + i);
				break;
			}
		}
		return;
	}
	transform.position += Vector2::up() * speed * Time::deltaTime();
	animator.Update();
}

