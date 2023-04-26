#include "Projectile.h"

void Projectile::Awake(){
	destroyTime = Time::time() + lifeSpan;
}

void Projectile::Update() {
	//destroyTime = Time::time() + 0.0001;
	transform()->scale.Set(0.25f, 0.25f, 1);

	if (Time::time() >= destroyTime) {
		Destroy(*gameObject);
		return;
	}
	transform()->position += Vector2::up() * speed * Time::deltaTime();
}
