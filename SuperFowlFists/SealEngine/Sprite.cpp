#include "Sprite.h"
#include "Vector2.h"
#include "Texture2D.h"
using namespace SealEngine;

Sprite::Sprite(const Texture2D& texture, const Rect& rect, const Vector2& pivot, float pixelsPerUnit)
    : texture(&texture), _rect(rect), pivot(pivot), _pixelsPerUnit(pixelsPerUnit) {}

void Sprite::LoadVertices(){
	_textureRect = Rect(0, 0, texture->width() * rect().size().x() / pixelsPerUnit(), texture->height() * rect().size().y() / pixelsPerUnit());
	_textureRect.SetCenter(pivot.x(), pivot.y());

	_vertices[0].Set(textureRect().minVertex().x(), textureRect().maxVertex().y());
	_vertices[1].Set(textureRect().maxVertex().x(), textureRect().maxVertex().y());
	_vertices[2].Set(textureRect().maxVertex().x(), textureRect().minVertex().y());
	_vertices[3].Set(textureRect().minVertex().x(), textureRect().minVertex().y());
}

float Sprite::pixelsPerUnit() const { return _pixelsPerUnit; }

std::array<Vector2, 4> Sprite::vertices() const { return _vertices; }
