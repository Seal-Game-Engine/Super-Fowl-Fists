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

std::shared_ptr<Projectile> Projectile::Clone() const { return std::shared_ptr<Projectile>(Clone_impl()); }

Projectile* Projectile::Clone_impl() const { return new Projectile(*this); }

