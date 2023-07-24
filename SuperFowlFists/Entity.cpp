#include "Entity.h"

void Entity::OnDamageTaken(DamageData data, Vector2 knockbackDirection){
	if (!isAlive()) return;

	currentHp -= data.damage;
	if (currentHp <= 0) {
		currentHp = 0;
		_isAlive = false;
		OnDeath();
	}
}

Entity::Entity(const float hp) :maxHp(hp), currentHp(hp) {}
