#include "BoxCollider2D.h"
#include "../Transform.h"
using namespace SealEngine;

BoxCollider2D::BoxCollider2D(Vector2 size, Vector2 offset) : size(size), Collider2D(offset) {}

void BoxCollider2D::ProjectVerticesOn(const Vector2& axis, float& min, float& max) {
	min = FLT_MAX;
	max = FLT_MIN;

	for (auto& vertex : worldSpaceVertices()) {
		float projection = Vector2::Dot(vertex, axis);
		if (projection < min) min = projection;
		if (projection > max) max = projection;
	}
}

std::vector<Vector2> BoxCollider2D::separationAxes(const std::vector<Vector2>& otherPolygonVertices){
	std::vector<Vector2> axes{};

	for (int i = 0; i < worldSpaceVertices().size(); i++)
		axes.emplace_back(Vector2::Perpendicular(worldSpaceVertices()[((unsigned long long)i + 1) % worldSpaceVertices().size()] - worldSpaceVertices()[i]).normalized());

	return axes;
}

std::vector<Vector2> BoxCollider2D::worldSpaceVertices() {
	float halfWidth = size.x() / 2;
	float halfHeight = size.y() / 2;
	Vector2 worldSpaceCenter = transform()->position + offset;

	return {
		worldSpaceCenter + Vector2(-halfWidth, halfHeight),
		worldSpaceCenter + Vector2(halfWidth, halfHeight),
		worldSpaceCenter + Vector2(halfWidth, -halfHeight),
		worldSpaceCenter + Vector2(-halfWidth, -halfHeight),
	};
}
