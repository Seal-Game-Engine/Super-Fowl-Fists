#include "Collider2D.h"
#include "Rigidbody2D.h"
#include "Collision2D.h"
#include "ContactPoint2D.h"
#include "../GameObject.h"
#include "../Scene.h"
#include <algorithm>
using namespace SealEngine;

Collider2D::Collider2D(Vector2 offset) : offset(offset) {}

void Collider2D::Awake() {
	_attachedRigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Collider2D::LateUpdate() {
	if (!attachedRigidbody()) return;

	std::vector<Collider2D*> sceneColliders = FindObjectsByType<Collider2D>();
	for (auto& sceneCollider : sceneColliders) {
		std::vector<Vector2> normals{};
		if (*this == *sceneCollider || !Collider2D::Collide(*this, *sceneCollider, normals)) continue;

		for (auto& component : gameObject->components) 
			component->OnCollisionEnter2D(Collision2D(sceneCollider, this, normals));
		for (auto& component : sceneCollider->gameObject->components) {
			std::vector<Vector2> invertedNormals{};
			invertedNormals.reserve(normals.size());
			std::for_each(normals.begin(), normals.end(), [&invertedNormals](const auto& normal) { invertedNormals.emplace_back(normal * -1); });
			component->OnCollisionEnter2D(Collision2D(this, sceneCollider, invertedNormals));
		}
	}
}

bool Collider2D::InCollisionRange(Collider2D& a, Collider2D& b){
	return Vector2::Distance(a.transform()->position + a.offset, b.transform()->position + b.offset) < (a.circumradius() + b.circumradius());
}

bool Collider2D::Collide(Collider2D& a, Collider2D& b, std::vector<Vector2>& normals) {
	if (!InCollisionRange(a, b)) return false;

	float minA, maxA, minB, maxB;
	Vector2 normal = Vector2::zero();
	for (auto& axis : a.separationAxes(b.worldSpaceVertices())) {
		a.ProjectVerticesOn(axis, minA, maxA);
		b.ProjectVerticesOn(axis, minB, maxB);

		if (minA > maxB || minB > maxA) return false;

		normals.emplace_back(axis * (std::min)(maxA - minB, maxB - minA) * 
			(Vector2::Dot(b.transform()->position - a.transform()->position, axis) < 0 ? -1 : 1));
	}

	for (auto& axis : b.separationAxes(a.worldSpaceVertices())) {
		a.ProjectVerticesOn(axis, minA, maxA);
		b.ProjectVerticesOn(axis, minB, maxB);

		if (minA > maxB || minB > maxA) return false;

		normals.emplace_back(axis * (std::min)(maxA - minB, maxB - minA) *
			(Vector2::Dot(b.transform()->position - a.transform()->position, axis) < 0 ? -1 : 1));
	}

	return true;
}