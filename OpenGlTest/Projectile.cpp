#include "Projectile.h"

void Projectile::Awake(){
	destroyTime = Time::time() + lifeSpan;
}

void Projectile::Update() {
	if (Time::time() >= destroyTime) {
		Destroy(*gameObject);
		return;
	}
	transform()->position += Vector2::up() * speed * Time::deltaTime();
}
