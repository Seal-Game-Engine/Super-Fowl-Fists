#include "ContactPoint2D.h"
#include "Rigidbody2D.h"
using namespace SealEngine;

Rigidbody2D* ContactPoint2D::rigidbody() { return collider->attachedRigidbody(); }
Rigidbody2D* ContactPoint2D::otherRigidbody() { return otherCollider->attachedRigidbody(); }
Vector2 ContactPoint2D::relativeVelocity() { return (otherRigidbody() ? otherRigidbody()->velocity : Vector2::zero()) - (rigidbody() ? rigidbody()->velocity : Vector2::zero()); }

ContactPoint2D::ContactPoint2D(Collider2D* collider, Collider2D* otherCollider, const Vector2& normal)
	:collider(collider), otherCollider(otherCollider), normal(normal.normalized()), separation(normal.magnitude()) {}
