#include "Rigidbody2D.h"
#include "Collider2D.h"
#include "../GameObject.h"
#include "../Clock.h"
#include <cfloat>
#include "../Input.h"
using namespace SealEngine;

Rigidbody2D::Rigidbody2D(BodyType bodyType, float mass, float gravityScale) :bodyType(bodyType), mass(mass), gravityScale(gravityScale) {}

void Rigidbody2D::Update(){
	transform()->position += velocity * Time::deltaTime();

	if (bodyType != BodyType::Dynamic) return;

	AddForce(Vector2::down() * mass * 9.81f * gravityScale);
}

void Rigidbody2D::LateUpdate() {
	//velocity = (transform()->position - _initialPosition);
}

void Rigidbody2D::OnCollisionStay2D(Collision2D collision) {
	if (bodyType != BodyType::Dynamic) return;
	float e = 0.05f; //bounciness

	transform()->position += collision.normal() * -collision.separation();

	if (Vector2::Dot(collision.relativeVelocity(), collision.normal()) > 0) return;

	auto j = -(1.0f + e) * Vector2::Dot(collision.relativeVelocity(), collision.normal());
	j /= (1.0f / mass) + (1.0f / (collision.otherRigidbody() ? collision.otherRigidbody()->mass : FLT_MAX));
	AddForce(collision.normal() * -j, ForceMode2D::Impulse);
}

void Rigidbody2D::AddForce(Vector2 force, ForceMode2D mode) { 
	if (bodyType != BodyType::Dynamic) return;

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
