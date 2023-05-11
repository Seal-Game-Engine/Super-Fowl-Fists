#include "Projectile.h"

void Projectile::Initialize(Vector2 direction, GameObject* sourceObject){
	_direction = direction;
	_sourceObject = sourceObject;

	if (_traversalMethod == TraversalMethods::UseForce) _rigidbody->AddForce(_direction * _speed, Rigidbody2D::ForceMode2D::Impulse);
}

Projectile::Projectile(float speed, float lifeSpan, TraversalMethods traversalMethod, bool isExplosive) :_speed(speed), _lifeSpan(lifeSpan), _traversalMethod(traversalMethod), _isExplosive(isExplosive) {}

void Projectile::Awake(){
	_destroyTime = Time::time() + _lifeSpan;
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Projectile::Update() {
	if (Time::time() >= _destroyTime) {
		Destroy(*gameObject);
		return;
	}

	if (_traversalMethod == TraversalMethods::UseVelocity) _rigidbody->velocity = _direction * _speed;
}

void Projectile::OnTriggerEnter2D(Collider2D* collider) { 
	if (collider->gameObject != _sourceObject && !collider->gameObject->CompareTag("Projectile")) {
		//instantiate explosion
		Destroy(*gameObject);
	}
}
void Projectile::OnCollisionEnter2D(Collision2D collision) { OnTriggerEnter2D(collision.collider); }
