#include "Sprite.h"
#include "Vector2.h"
using namespace SealEngine;

//glEnable(GL_BLEND);
//glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

//int vfrm = 4, hfrm = 4;

//textureLoader->Load(fileName, tex);

Sprite::Sprite(const Texture2D& texture, const Vector2& pivot, float pixelsPerUnit) :
	texture(texture), 
	pivot(pivot), 
	_pixelsPerUnit(pixelsPerUnit) {
	//this->pivot = pivot;
}

float Sprite::pixelsPerUnit() { return _pixelsPerUnit; }

const std::vector<Vector2>& Sprite::vertices()const {
	float halfWidth = (float)texture.width() / 2;
	float halfHeight = (float)texture.height() / 2;

	return std::vector<Vector2>{		
		Vector2(-pivot.x() - halfWidth, -pivot.y() - halfHeight),
		Vector2(-pivot.x() + halfWidth, -pivot.y() - halfHeight),
		Vector2(-pivot.x() + halfWidth, -pivot.y() + halfHeight),
		Vector2(-pivot.x() - halfWidth, -pivot.y() + halfHeight),
	};
}
