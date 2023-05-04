#include "Rigidbody2D.h"
#include "Collider2D.h"
#include "../GameObject.h"
#include "../Clock.h"
#include <cfloat>
using namespace SealEngine;

void Rigidbody2D::Update(){
	_initialPosition = transform()->position;


	AddForce(Vector2::down() * mass * 9.81f * gravityScale);
	//velocity = Vector2::Lerp(velocity, Vector2::zero(), Time::deltaTime());

	transform()->position += velocity * Time::deltaTime();
}

void Rigidbody2D::LateUpdate() {
	//velocity = (transform()->position - _initialPosition);
}

void Rigidbody2D::OnCollisionEnter2D(Collision2D collision) {
	float e = 0.5f;

	transform()->position += collision.normal() * -collision.separation() * 2 * Time::deltaTime();

	if (Vector2::Dot(collision.relativeVelocity(), collision.normal()) > 0) return;

	auto j = -(1.0f + e) * Vector2::Dot(collision.relativeVelocity(), collision.normal());//
	j /= (1.0f / mass) + (1.0f / (collision.otherRigidbody() ? collision.otherRigidbody()->mass : FLT_MAX));
	auto impulse = collision.normal() * -j;
	velocity += impulse / mass;
}

void Rigidbody2D::AddForce(Vector2 force, ForceMode2D mode) { 
	switch (mode) {
	case ForceMode2D::Force:
		velocity += force / mass * Time::deltaTime();
		break;
	case ForceMode2D::Impulse:
		velocity += force / mass;
		break;
	}
}

int Rigidbody2D::GetAttachedColliders(std::vector<Collider2D*>& results) {
	results = gameObject->GetComponents<Collider2D>();
	_attachedColliderCount = results.size();
	return attachedColliderCount();
}
