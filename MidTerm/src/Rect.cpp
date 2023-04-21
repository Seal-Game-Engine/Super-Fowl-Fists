#include "Rect.h"
using namespace SealEngine;

Rect::Rect(const float x, const float y, const float width, const float height)
	: _position(x, y), _size(width, height) {}
Rect::Rect(const Vector2& position, const Vector2& size)
	: _position(position), _size(size) {}

const Vector2& Rect::position() const { return _position; }
const Vector2& Rect::size() const { return _size; }
const Vector2& Rect::minVertex() const { return position(); }
const Vector2 Rect::maxVertex() const { return position() + size(); }
const Vector2 Rect::center() const { return position() + size() / 2; }

Rect Rect::zero() { return Rect(0, 0, 0, 0); }

bool Rect::operator==(const Rect& obj) const { return position() == obj.position() && size() == obj.size(); }

void Rect::SetPosition(const float x, const float y) { _position.Set(x, y); }
void Rect::SetSize(const float width, const float height) { _size.Set(width, height); }
void Rect::SetMinVertex(const float xMin, const float yMin) {
	SetSize(maxVertex().x() - xMin, maxVertex().y() - yMin);
	SetPosition(xMin, yMin);
}
void Rect::SetMaxVertex(const float xMax, const float yMax) {
	SetSize(xMax - minVertex().x(), yMax - minVertex().y());
}
void Rect::SetCenter(const float x, const float y){
	SetPosition(x - size().x() / 2, y - size().y() / 2);
}
void Rect::Set(const float x, const float y, const float width, const float height) {
	SetPosition(x, y);
	SetSize(width, height);
}

Rect Rect::MinMaxRect(float xMin, float yMin, float xMax, float yMax) { return Rect(xMin, yMin, xMax - xMin, yMax - yMin); }