#include "Chicken_Player.h"
#include "Prefab.h"
#include "Projectile.h"
#include "Hitbox.h"

void Chicken_Player::Attack_Mini() {
	Player::Attack_Mini();
	Vector2 direction = Vector2::right() * transform()->scale.x();
	GameObject* projectile = _projectilePool.Get();
	projectile->transform->position = transform()->position + direction * 0.25f;
	projectile->transform->rotation = Vector3::forward() * -90 * transform()->scale.x();
	projectile->GetComponent<Projectile>()->Initialize(direction, gameObject, &_projectilePool);
	projectile->GetComponent<Hitbox>()->data.faction = faction;
	projectile->GetComponent<Hitbox>()->data.entity = this;
}

Chicken_Player::Chicken_Player(const float hp) :Player(hp) {}
