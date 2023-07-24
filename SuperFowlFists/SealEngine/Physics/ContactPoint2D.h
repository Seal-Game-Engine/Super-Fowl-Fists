#pragma once
#include "../Vector2.h"

namespace SealEngine {
	class Collider2D;
	class Rigidbody2D;
}

namespace SealEngine {
	struct ContactPoint2D {
		Collider2D* collider = nullptr;
		Rigidbody2D* rigidbody();

		Collider2D* otherCollider = nullptr;
		Rigidbody2D* otherRigidbody();

		Vector2 relativeVelocity();

		Vector2	normal = Vector2::zero();

		//normalImpulse
		//point
		float separation = 0;
		//tangentImpulse

		ContactPoint2D(Collider2D* collider, Collider2D* otherCollider, const Vector2& normal);
	};
}
