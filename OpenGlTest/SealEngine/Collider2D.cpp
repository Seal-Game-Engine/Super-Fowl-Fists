#include "Collider2D.h"

Collider2D::Collider2D(float width, float height)
	:width(width), height(height), colliderBox(0, 0, width, height) {}

void Collider2D::Update() {
	colliderBox.SetCenter(transform()->position.x(), transform()->position.y());
}

bool Collider2D::checkCollision(Collider2D& a, Collider2D& b) {
	return Vector2::Distance(a.transform()->position, b.transform()->position) < 0.5f;
}


