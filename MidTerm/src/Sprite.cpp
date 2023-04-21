#include "Sprite.h"
#include "Vector2.h"
#include "Texture2D.h"
using namespace SealEngine;

Sprite::Sprite(const Texture2D& texture, const Rect& rect, const Vector2& pivot, float pixelsPerUnit)
	: texture(&texture), rect(rect), pivot(pivot), _pixelsPerUnit(pixelsPerUnit) {}

float Sprite::pixelsPerUnit() const { return _pixelsPerUnit; }

std::array<Vector2, 4> Sprite::vertices()const {
	float halfWidth = texture->width() * rect.size().x() / pixelsPerUnit() / 2;
	float halfHeight = texture->height() * rect.size().y() / pixelsPerUnit() / 2;

	Vector2 worldPointPivot = Vector2(halfWidth * pivot.x(), halfHeight * pivot.y());

	return std::array<Vector2, 4>{
		Vector2(-worldPointPivot.x() - halfWidth, -worldPointPivot.y() + halfHeight),
		Vector2(-worldPointPivot.x() + halfWidth, -worldPointPivot.y() + halfHeight),
		Vector2(-worldPointPivot.x() + halfWidth, -worldPointPivot.y() - halfHeight),
		Vector2(-worldPointPivot.x() - halfWidth, -worldPointPivot.y() - halfHeight),
	};
}
