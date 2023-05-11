#include "Explosion.h"

Explosion::Explosion(float lifeSpan) :_lifeSpan(lifeSpan) {}

void Explosion::Awake(){
	Destroy(*gameObject, _lifeSpan);
}
