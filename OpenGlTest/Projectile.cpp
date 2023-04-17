#include "Projectile.h"

//Projectile::Projectile(Vector3 position) : destroyTime(Time::time() + lifeSpan), id(idCounter++) {
	//transform.position = position;
	//transform.scale.Set(0.25f, 0.25f, 1);
	//renderer._transform = &transform;
	//renderer.sprite = &AssetManager::Projectile_Blue[0];
	//animator.SetAnimatorController(&AssetManager::Projectile_Blue_Controller);
	//animator.renderer = &renderer;
//}

void Projectile::Update() {
	//destroyTime = Time::time() + 0.0001;
	transform()->scale.Set(0.25f, 0.25f, 1);

	if (Time::time() >= destroyTime) {
		Destroy(*gameObject);
		//for (int i = 0; i < LandingScene::projectiles.size(); i++) {
		//	/*if (LandingScene::projectiles[i]->id == id) {
		//		LandingScene::projectiles.erase(LandingScene::projectiles.begin() + i);
		//		break;
		//	}*/
		//}
		return;
	}
	transform()->position += Vector2::up() * speed * Time::deltaTime();
}

