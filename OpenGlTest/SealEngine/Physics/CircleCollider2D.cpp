#include "CircleCollider2D.h"
#include "../Transform.h"
using namespace SealEngine;

CircleCollider2D::CircleCollider2D(float radius, Vector2 offset) : radius(radius), Collider2D(offset) {}

void CircleCollider2D::ProjectVerticesOn(const Vector2& axis, float& min, float& max) {
	Vector2 worldSpaceCenter = transform()->position + offset;
	Vector2 directedRadius = axis.normalized() * radius;
	min = Vector2::Dot(worldSpaceCenter - directedRadius, axis);
	max = Vector2::Dot(worldSpaceCenter + directedRadius, axis);

	if (min > max) std::swap(min, max);
}

std::vector<Vector2> CircleCollider2D::separationAxes(const std::vector<Vector2>& otherPolygonVertices) {
	Vector2 worldSpaceCenter = transform()->position + offset;

	Vector2 nearestVertex = *std::min_element(otherPolygonVertices.begin(), otherPolygonVertices.end(), [&](const auto& a, const auto& b) {
		return Vector2::Distance(worldSpaceCenter, a) < Vector2::Distance(worldSpaceCenter, b);
		});

	return { (nearestVertex - worldSpaceCenter).normalized() };
}