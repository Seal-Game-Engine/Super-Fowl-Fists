#include "Obstacle.h"
#include "../Projectile.h"

void Obstacle::Awake() {
	rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Obstacle::Start(){
	player = gameObject->FindWithTag("Player");
}

void Obstacle::Update() { //move to other direction
	Vector2 direction = (player->transform->position - transform()->position).normalized();

	//rigidbody->velocity = Vector2(direction.x() * _speed, rigidbody->velocity.y());
	rigidbody->AddForce(direction * _speed);
}

void Obstacle::OnCollisionEnter2D(Collision2D collision) {
	if (collision.gameObject()->GetComponent<Projectile>()) Destroy(*gameObject);
}
