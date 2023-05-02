#pragma once
#include <vector>
#include "../Vector2.h"
#include "ContactPoint2D.h"
namespace SealEngine { 
	class Collider2D;
	class Rigidbody2D;
	class Transform;
	class GameObject;
}

namespace SealEngine {
	struct Collision2D {
		ContactPoint2D GetContact(int index);
		int GetContacts(std::vector<ContactPoint2D> contacts);

		Collider2D* collider = nullptr;
		Rigidbody2D* rigidbody();
		Transform* transform();
		GameObject* gameObject();

		Collider2D* otherCollider = nullptr;
		Rigidbody2D* otherRigidbody();

		int contactCount();
		Vector2 relativeVelocity();

		Collision2D(Collider2D* collider, Collider2D* otherCollider, const std::vector<Vector2>& normals);

	private:
		std::vector<ContactPoint2D> _contacts{};
	};
}