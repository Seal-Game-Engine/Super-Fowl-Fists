#include "Sprite.h"
#include "Vector2.h"
#include "Texture2D.h"
using namespace SealEngine;

Sprite::Sprite(const Texture2D& texture, const Rect& rect, const Vector2& pivot, float pixelsPerUnit)
	: texture(&texture), rect(rect), pivot(pivot), _pixelsPerUnit(pixelsPerUnit) {}

Sprite::Sprite(const Sprite& obj) 
	: texture(obj.texture), rect(obj.rect), pivot(obj.pivot), _pixelsPerUnit(obj._pixelsPerUnit) {}

float Sprite::pixelsPerUnit() { return _pixelsPerUnit; }

const std::vector<Vector2>& Sprite::vertices()const {
	float halfWidth = (float)texture->width() / 2;
	float halfHeight = (float)texture->height() / 2;

	return std::vector<Vector2>{		
		Vector2(-pivot.x() - halfWidth, -pivot.y() - halfHeight),
		Vector2(-pivot.x() + halfWidth, -pivot.y() - halfHeight),
		Vector2(-pivot.x() + halfWidth, -pivot.y() + halfHeight),
		Vector2(-pivot.x() - halfWidth, -pivot.y() + halfHeight),
	};
}
