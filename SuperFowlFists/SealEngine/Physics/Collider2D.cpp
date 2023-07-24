#include "Collider2D.h"
#include "Rigidbody2D.h"
#include "Collision2D.h"
#include "ContactPoint2D.h"
#include "../GameObject.h"
#include "../Scene.h"
#include "../Clock.h"
#include <algorithm>
#include <cfloat>
using namespace SealEngine;

float Collider2D::nextCollisionCheckTime = 0;

Collider2D::Collider2D(bool isTrigger, Vector2 offset) :isTrigger(isTrigger), offset(offset) {}

void Collider2D::Awake() {
	_attachedRigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Collider2D::LateUpdate() {
	if (Time::time() < nextCollisionCheckTime || !attachedRigidbody()) return;

	std::vector<Collider2D*> sceneColliders = Scene::FindObjectsByType<Collider2D>();
	for (auto& sceneCollider : sceneColliders) {
		float separation = FLT_MAX;
		Vector2 normal = Vector2::zero();
		if (*this == *sceneCollider) continue;

		bool isActiveCollision = IsActiveCollision(sceneCollider);

		if (Collider2D::Collide(*this, *sceneCollider, separation, normal)) {
			if (!isActiveCollision) {
				_activeCollisions.emplace_back(sceneCollider->gameObject);
#pragma region Enter
				if (isTrigger || sceneCollider->isTrigger) {
					for (auto& component : gameObject->components) if(component->enabled) component->OnTriggerEnter2D(sceneCollider);
					for (auto& component : sceneCollider->gameObject->components) if (component->enabled)component->OnTriggerEnter2D(this);
				} else {
					for (auto& component : gameObject->components) if (component->enabled)component->OnCollisionEnter2D(Collision2D(sceneCollider, this, separation, normal));
					for (auto& component : sceneCollider->gameObject->components) if (component->enabled)component->OnCollisionEnter2D(Collision2D(this, sceneCollider, separation, normal * -1));
				}
#pragma endregion
			} else {
#pragma region Stay
				if (isTrigger || sceneCollider->isTrigger) {
					for (auto& component : gameObject->components)if (component->enabled) component->OnTriggerStay2D(sceneCollider);
					for (auto& component : sceneCollider->gameObject->components) if (component->enabled)component->OnTriggerStay2D(this);
				} else {
					for (auto& component : gameObject->components) if (component->enabled)component->OnCollisionStay2D(Collision2D(sceneCollider, this, separation, normal));
					for (auto& component : sceneCollider->gameObject->components) if (component->enabled)component->OnCollisionStay2D(Collision2D(this, sceneCollider, separation, normal * -1));
				}
#pragma endregion
			}
		} else {
			if (isActiveCollision) {
				_activeCollisions.remove(sceneCollider->gameObject);
#pragma region Exit
				if (isTrigger || sceneCollider->isTrigger) {
					for (auto& component : gameObject->components)if (component->enabled) component->OnTriggerExit2D(sceneCollider);
					for (auto& component : sceneCollider->gameObject->components)if (component->enabled) component->OnTriggerExit2D(this);
				} else {
					for (auto& component : gameObject->components)if (component->enabled) component->OnCollisionExit2D(Collision2D(sceneCollider, this, separation, normal));
					for (auto& component : sceneCollider->gameObject->components) if (component->enabled)component->OnCollisionExit2D(Collision2D(this, sceneCollider, separation, normal * -1));
				}
#pragma endregion
			}
		}
	}
}

bool Collider2D::InCollisionRange(Collider2D& a, Collider2D& b, float& separation, Vector2& normal){
	float distance = Vector2::Distance(a.transform()->position + a.offset, b.transform()->position + b.offset);

	separation = (a.circumradius() + b.circumradius()) - distance;
	normal = (b.transform()->position + b.offset - a.transform()->position + a.offset) / distance;

	return separation >= 0;
}

bool Collider2D::Collide(Collider2D& a, Collider2D& b, float& separation, Vector2& normal) {
	if (!InCollisionRange(a, b, separation, normal)) return false;

	float minA, maxA, minB, maxB, currentSeparation;

	for (auto& axis : a.separationAxes(b.worldSpaceVertices())) {
		a.ProjectVerticesOn(axis, minA, maxA);
		b.ProjectVerticesOn(axis, minB, maxB);

		if (minA > maxB || minB > maxA) return false;
		
		currentSeparation = (std::min)(maxA - minB, maxB - minA);
		if (currentSeparation < separation) {
			separation = currentSeparation;
			normal = axis * (Vector2::Dot(b.transform()->position - a.transform()->position, axis) < 0 ? -1 : 1);
		}
	}
	for (auto& axis : b.separationAxes(a.worldSpaceVertices())) {
		a.ProjectVerticesOn(axis, minA, maxA);
		b.ProjectVerticesOn(axis, minB, maxB);

		if (minA > maxB || minB > maxA) return false;
		
		currentSeparation = (std::min)(maxA - minB, maxB - minA);
		if (currentSeparation < separation) {
			separation = currentSeparation;
			normal = axis * (Vector2::Dot(b.transform()->position - a.transform()->position, axis) < 0 ? -1 : 1);
		}
	}

	return true;
}

bool Collider2D::IsActiveCollision(const Collider2D* otherCollider) const {
	for (auto& collider : _activeCollisions) if (collider == otherCollider->gameObject) return true;
	return false;
}
