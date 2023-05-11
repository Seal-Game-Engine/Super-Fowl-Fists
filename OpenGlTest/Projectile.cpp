#include "Projectile.h"

void Projectile::Initialize(Vector2 direction, GameObject* sourceObject, ObjectPool* objectPool){
	gameObject->SetActive(true);
	_destroyTime = Time::time() + _lifeSpan;
	_direction = direction;
	_sourceObject = sourceObject;
	_objectPool = objectPool;
	if(_rigidbody) _rigidbody->velocity = Vector2::zero();

	if (_traversalMethod == TraversalMethods::UseForce) _rigidbody->AddForce(_direction * _speed, Rigidbody2D::ForceMode2D::Impulse);
}

Projectile::Projectile(float speed, float lifeSpan, TraversalMethods traversalMethod, bool isExplosive) :_speed(speed), _lifeSpan(lifeSpan), _traversalMethod(traversalMethod), _isExplosive(isExplosive) {}

void Projectile::Awake(){
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Projectile::Update() {
	if (Time::time() >= _destroyTime) {
		if (_objectPool) {
			gameObject->SetActive(false);
			_objectPool->Release(gameObject);
		} else Destroy(*gameObject);
		return;
	}

	if (_traversalMethod == TraversalMethods::UseVelocity) _rigidbody->velocity = _direction * _speed;
}

void Projectile::OnTriggerEnter2D(Collider2D* collider) {
	if (collider->gameObject != _sourceObject && !collider->gameObject->CompareTag("Projectile")) {
		//if(isExplosive) instantiate explosion

		if (_objectPool) {
			gameObject->SetActive(false);
			_objectPool->Release(gameObject);
		} else Destroy(*gameObject);
	}
}
void Projectile::OnCollisionEnter2D(Collision2D collision) { OnTriggerEnter2D(collision.collider); }
