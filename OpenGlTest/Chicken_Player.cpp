#include "Chicken_Player.h"
#include "Prefab.h"
#include "Projectile.h"
#include "Hitbox.h"

void Chicken_Player::Attack_Mini() {
	Player::Attack_Mini();
	Vector2 direction = Vector2::right() * transform()->scale.x();
	GameObject* projectile = InstantiateT(Prefab::ProjectileObject_Blue, transform()->position + direction * 0.25f);
	projectile->transform->rotation += Vector3::forward() * -90 * transform()->scale.x();
	projectile->GetComponent<Projectile>()->Initialize(direction, gameObject);
	projectile->GetComponent<Hitbox>()->data.faction = faction;
	projectile->GetComponent<Hitbox>()->data.entity = this;
}
