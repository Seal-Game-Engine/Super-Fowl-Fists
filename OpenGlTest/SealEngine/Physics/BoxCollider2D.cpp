#include "BoxCollider2D.h"
#include "../Transform.h"
using namespace SealEngine;

BoxCollider2D::BoxCollider2D(Vector2 size, Vector2 offset) : size(size), Collider2D(offset) {}

std::vector<Vector2> BoxCollider2D::worldSpaceVertices() {
	float halfWidth = size.x() / 2;
	float halfHeight = size.y() / 2;

	return {
		transform()->position + offset + Vector2(-halfWidth, halfHeight),
		transform()->position + offset + Vector2(halfWidth, halfHeight),
		transform()->position + offset + Vector2(halfWidth, -halfHeight),
		transform()->position + offset + Vector2(-halfWidth, -halfHeight),
	};
}
