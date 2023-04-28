#include "Rigidbody2D.h"
#include "Collider2D.h"
#include "../GameObject.h"
#include "../Clock.h"
using namespace SealEngine;

void Rigidbody2D::Update(){
	_initialPosition = transform()->position;


	AddForce(Vector2::down() * mass * 0.98f * gravityScale);
	transform()->position += velocity * Time::deltaTime();
	//velocity = Vector2::Lerp(velocity, Vector2::zero(), Time::deltaTime());
}

void Rigidbody2D::LateUpdate() {
	//velocity = (transform()->position - _initialPosition);
}

void Rigidbody2D::OnCollisionEnter2D(Collision2D collision){
	Vector2 direction = (transform()->position - collision.transform()->position).normalized();
	transform()->position += direction * velocity.magnitude() * Time::deltaTime();
}

void Rigidbody2D::AddForce(Vector2 force, ForceMode2D mode) { velocity += force / mass * Time::deltaTime(); }

int Rigidbody2D::GetAttachedColliders(std::vector<Collider2D*>& results) {
	results = gameObject->GetComponents<Collider2D>();
	_attachedColliderCount = results.size();
	return attachedColliderCount();
}