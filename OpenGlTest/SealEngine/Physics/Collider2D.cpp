#include "Collider2D.h"
#include "Rigidbody2D.h"
#include "Collision2D.h"
#include "../GameObject.h"
#include "../Scene.h"
using namespace SealEngine;

Collider2D::Collider2D(Vector2 offset) : offset(offset) {}

void Collider2D::Start() {
	_attachedRigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Collider2D::LateUpdate() {
	if (!attachedRigidbody()) return;

	std::vector<Collider2D*> sceneColliders = FindObjectsByType<Collider2D>();
	for (auto& sceneCollider : sceneColliders) {
		if (*this == *sceneCollider || !Collider2D::CheckCollision(*this, *sceneCollider)) continue;

		for (auto& component : gameObject->components) component->OnCollisionEnter2D(Collision2D(sceneCollider, this));
		for (auto& component : sceneCollider->gameObject->components) component->OnCollisionEnter2D(Collision2D(this, sceneCollider));
	}
}

bool Collider2D::InCollisionRange(Collider2D& a, Collider2D& b){
	return Vector2::Distance(a.transform()->position + a.offset, b.transform()->position + b.offset) < (a.circumradius() + b.circumradius());
}

void Collider2D::ProjectVerticesOnAxis(const std::vector<Vector2>& worldSpaceVertices, const Vector2& axis, float& min, float& max){
	min = FLT_MAX;
	max = FLT_MIN;
	
	for (auto& vertice : worldSpaceVertices) {
		float projection = Vector2::Dot(vertice, axis);
		if (projection < min) min = projection;
		if (projection > max) max = projection;
	}
}

bool Collider2D::CheckCollision(Collider2D& a, Collider2D& b) {
	if (!InCollisionRange(a, b)) return false;

	for (int i = 0; i < a.worldSpaceVertices().size() && b.worldSpaceVertices().size() > 0; i++) {
		Vector2 axis = Vector2::Perpendicular(a.worldSpaceVertices()[((unsigned long long)i + 1) % a.worldSpaceVertices().size()] - a.worldSpaceVertices()[i]);

		float minA, maxA, minB, maxB;
		ProjectVerticesOnAxis(a.worldSpaceVertices(), axis, minA, maxA);
		ProjectVerticesOnAxis(b.worldSpaceVertices(), axis, minB, maxB);

		if (minA >= maxB || minB >= maxA) return false;
	}

	for (int i = 0; i < b.worldSpaceVertices().size() && a.worldSpaceVertices().size() > 0; i++) {
		Vector2 axis = Vector2::Perpendicular(b.worldSpaceVertices()[((unsigned long long)i + 1) % b.worldSpaceVertices().size()] - b.worldSpaceVertices()[i]);

		float minA, maxA, minB, maxB;
		ProjectVerticesOnAxis(a.worldSpaceVertices(), axis, minA, maxA);
		ProjectVerticesOnAxis(b.worldSpaceVertices(), axis, minB, maxB);

		if (minA >= maxB || minB >= maxA) return false;
	}

	return true;
}

//write code to project circle to axis:
//v1,v2 = ctr + dir * r, ctr - dir * r
//dot v1, v2 , axis, swap minmax

//circle axis:
//vector = circle ctr to nearest vertex of polygon