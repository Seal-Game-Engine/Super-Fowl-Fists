#include "Collision2D.h"

#include "Collider2D.h"
#include "Rigidbody2D.h"
#include "../Transform.h"
#include "../GameObject.h"
using namespace SealEngine;

ContactPoint2D Collision2D::GetContact(int index){	return _contacts[index];}

int Collision2D::GetContacts(std::vector<ContactPoint2D> contacts) { return 0; }

Rigidbody2D* Collision2D::rigidbody() { return collider->attachedRigidbody(); }
Transform* Collision2D::transform() { return collider->transform(); }
GameObject* Collision2D::gameObject() { return collider->gameObject; }

Rigidbody2D* Collision2D::otherRigidbody() { return otherCollider->attachedRigidbody(); }

int Collision2D::contactCount() { return _contacts.size(); }
Vector2 Collision2D::relativeVelocity() {
	return
		(rigidbody() ? rigidbody()->velocity : Vector2::zero()) -
		(otherRigidbody() ? otherRigidbody()->velocity : Vector2::zero());
}

Collision2D::Collision2D(Collider2D* collider, Collider2D* otherCollider, const float separation, const Vector2& normal) 
	: collider(collider), otherCollider(otherCollider), _separation(separation), _normal(normal) {
	//_contacts.reserve(normals.size());
	//for (auto& normal : normals) _contacts.emplace_back(collider, otherCollider, normal);
}
