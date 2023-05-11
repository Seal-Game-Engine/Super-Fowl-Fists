#include "TikeMyson_Player.h"
#include "Prefab.h"
#include "Projectile.h"
#include "Hitbox.h"

void TikeMyson_Player::Attack_Mini() {
	Player::Attack_Mini();

	std::array<Vector2, 3> directions{ 
		Vector2::right() * transform()->scale.x() + Vector2::up() * 0.3f,
		Vector2::right() * transform()->scale.x(),
		Vector2::right() * transform()->scale.x() + Vector2::down() * 0.3f,
	};

	for (auto& direction : directions) {
		GameObject* projectile = InstantiateT(Prefab::ProjectileObject_Blue, transform()->position + direction * 0.25f);
		projectile->transform->rotation += Vector3::forward() * -90 * transform()->scale.x();
		projectile->GetComponent<Projectile>()->Initialize(direction, gameObject);
		projectile->GetComponent<Hitbox>()->data.faction = faction;
		projectile->GetComponent<Hitbox>()->data.entity = this;
	}
}

TikeMyson_Player::TikeMyson_Player(const float hp) :Player(hp) {}
