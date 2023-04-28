#pragma once
namespace SealEngine { 
	class Collider2D;
	class Rigidbody2D;
	class Transform;
	class GameObject;
}

namespace SealEngine {
	struct Collision2D {
		Collider2D* collider = nullptr;
		Rigidbody2D* rigidbody();
		Transform* transform();
		GameObject* gameObject();

		Collider2D* otherCollider = nullptr;
		Rigidbody2D* otherRigidbody();

		Collision2D(Collider2D* collider, Collider2D* otherCollider);
	};
}

