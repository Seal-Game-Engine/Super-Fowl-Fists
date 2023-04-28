#include "Projectile.h"

void Projectile::Awake(){
	destroyTime = Time::time() + lifeSpan;
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Projectile::Update() {
	if (Time::time() >= destroyTime) {
		Destroy(*gameObject);
		return;
	}
	_rigidbody->velocity = Vector2::up() * speed;
}
