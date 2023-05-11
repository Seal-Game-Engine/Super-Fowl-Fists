#pragma once
#include "../MonoBehaviour.h"
#include "../Rect.h"
namespace SealEngine { class Rigidbody2D; }

namespace SealEngine {
	class Collider2D : public MonoBehaviour {
	public:
		static float nextCollisionCheckTime;

		Rigidbody2D* attachedRigidbody() { return _attachedRigidbody; }

		bool isTrigger = false;
		Vector2 offset = Vector2::zero();

		Collider2D(bool isTrigger = false, Vector2 offset = Vector2::zero());

		void Awake() override;
		void LateUpdate() override;
		std::list<GameObject*> _activeCollisions{};

	private:
		static bool InCollisionRange(Collider2D& a, Collider2D& b, float& separation, Vector2& normal);
		static bool Collide(Collider2D& a, Collider2D& b, float& separation, Vector2& normal);

		virtual void ProjectVerticesOn(const Vector2& axis, float& min, float& max) = 0;

		virtual float circumradius() const = 0;
		virtual std::vector<Vector2> separationAxes(const std::vector<Vector2>& otherPolygonVertices) = 0;
		virtual std::vector<Vector2> worldSpaceVertices() { return {}; }
		bool IsActiveCollision(const Collider2D* otherCollider) const;


		Rigidbody2D* _attachedRigidbody = nullptr;
	};
}