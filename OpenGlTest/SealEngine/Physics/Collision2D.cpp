#include "Collision2D.h"

#include "Collider2D.h"
#include "Rigidbody2D.h"
#include "../Transform.h"
#include "../GameObject.h"
using namespace SealEngine;

Rigidbody2D* Collision2D::rigidbody() { return collider->attachedRigidbody(); }
Transform* Collision2D::transform() { return collider->transform(); }
GameObject* Collision2D::gameObject() { return collider->gameObject; }

Rigidbody2D* Collision2D::otherRigidbody() { return otherCollider->attachedRigidbody(); }

Collision2D::Collision2D(Collider2D* collider, Collider2D* otherCollider) : collider(collider), otherCollider(otherCollider) {}
