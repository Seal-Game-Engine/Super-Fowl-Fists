#include "Collider2D.h"
#include "Rigidbody2D.h"
#include "Collision2D.h"
#include "ContactPoint2D.h"
#include "../GameObject.h"
#include "../Scene.h"
#include <algorithm>
#include <cfloat>
using namespace SealEngine;

Collider2D::Collider2D(bool isTrigger, Vector2 offset) : isTrigger(isTrigger), offset(offset) {}

void Collider2D::Awake() {
	_attachedRigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Collider2D::LateUpdate() {
	if (!attachedRigidbody()) return;

	std::vector<Collider2D*> sceneColliders = Scene::FindObjectsByType<Collider2D>();
	for (auto& sceneCollider : sceneColliders) {
		float separation = FLT_MAX;
		Vector2 normal = Vector2::zero();
		if (*this == *sceneCollider || !Collider2D::Collide(*this, *sceneCollider, separation, normal)) continue;

		if (isTrigger || sceneCollider->isTrigger) {
			for (auto& component : gameObject->components)
				component->OnTriggerEnter2D(sceneCollider);
			for (auto& component : sceneCollider->gameObject->components)
				component->OnTriggerEnter2D(sceneCollider);
		} else {
			for (auto& component : gameObject->components)
				component->OnCollisionEnter2D(Collision2D(sceneCollider, this, separation, normal));
			for (auto& component : sceneCollider->gameObject->components)
				component->OnCollisionEnter2D(Collision2D(this, sceneCollider, separation, normal * -1));
		}
	}

	for (auto& collider : _activeCollisions) {
	
	}
}

bool Collider2D::InCollisionRange(Collider2D& a, Collider2D& b){
	return Vector2::Distance(a.transform()->position + a.offset, b.transform()->position + b.offset) < (a.circumradius() + b.circumradius());
}

bool Collider2D::Collide(Collider2D& a, Collider2D& b, float& separation, Vector2& normal) {
	if (!InCollisionRange(a, b)) return false;
	separation = Vector2::Distance(a.transform()->position, b.transform()->position);
	normal = (b.transform()->position - a.transform()->position).normalized();

	float minA, maxA, minB, maxB;
	for (auto& axis : a.separationAxes(b.worldSpaceVertices())) {
		a.ProjectVerticesOn(axis, minA, maxA);
		b.ProjectVerticesOn(axis, minB, maxB);

		if (minA > maxB || minB > maxA) return false;

		if (auto currentSeparation = (std::min)(maxA - minB, maxB - minA) < separation) {
			separation = currentSeparation;
			normal = axis * (Vector2::Dot(b.transform()->position - a.transform()->position, axis) < 0 ? -1 : 1);
		}
	}

	for (auto& axis : b.separationAxes(a.worldSpaceVertices())) {
		a.ProjectVerticesOn(axis, minA, maxA);
		b.ProjectVerticesOn(axis, minB, maxB);

		if (minA > maxB || minB > maxA) return false;

		if (auto currentSeparation = (std::min)(maxA - minB, maxB - minA) < separation) {
			separation = currentSeparation;
			normal = axis * (Vector2::Dot(b.transform()->position - a.transform()->position, axis) < 0 ? -1 : 1);
		}
	}

	return true;
}
