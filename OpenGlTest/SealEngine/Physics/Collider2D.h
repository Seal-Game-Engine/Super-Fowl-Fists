#pragma once
#include "../MonoBehaviour.h"
#include "../Rect.h"
namespace SealEngine { class Rigidbody2D; }

namespace SealEngine {
	class Collider2D :public MonoBehaviour {
	public:
		Rigidbody2D* attachedRigidbody() { return _attachedRigidbody; }

		Vector2 offset = Vector2::zero();

		Collider2D(Vector2 offset = Vector2::zero());

		void Start() override;
		void LateUpdate() override;

	private:
		static bool InCollisionRange(Collider2D& a, Collider2D& b);
		static void ProjectVerticesOnAxis(const std::vector<Vector2>& worldSpaceVertices, const Vector2& axis, float& min, float& max);
		static bool CheckCollision(Collider2D& a, Collider2D& b);

		virtual float circumradius() const = 0;
		virtual std::vector<Vector2> worldSpaceVertices() { return {}; }

		Rigidbody2D* _attachedRigidbody = nullptr;
	};
}