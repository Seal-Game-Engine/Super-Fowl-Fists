#include "Explosion.h"
#include "Hitbox.h"

Explosion::Explosion(float lifeSpan) :_lifeSpan(lifeSpan) {}

void Explosion::Awake() {
	Invoke([&] { Destroy(*gameObject); }, _lifeSpan);
}
