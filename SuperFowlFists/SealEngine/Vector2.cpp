#include "Vector2.h"
#include <cmath>
#include <cfloat>
#include "Vector3.h"
using namespace SealEngine;

Vector2::Vector2(const float x, const float y) : _x(x), _y(y) {}
Vector2::Vector2(const Vector2& obj) : _x(obj.x()), _y(obj.y()) {}

float Vector2::x() const { return _x; }
float Vector2::y() const { return _y; }

Vector2 Vector2::zero() { return Vector2(0, 0); }
Vector2 Vector2::one() { return Vector2(1, 1); }
Vector2 Vector2::up() { return Vector2(0, 1); }
Vector2 Vector2::down() { return Vector2(0, -1); }
Vector2 Vector2::left() { return Vector2(-1, 0); }
Vector2 Vector2::right() { return Vector2(1, 0); }

Vector2 Vector2::operator+(const Vector2& obj) const { return Vector2(x() + obj.x(), y() + obj.y()); }
Vector2 Vector2::operator-(const Vector2& obj) const { return Vector2(x() - obj.x(), y() - obj.y()); }
Vector2 Vector2::operator*(const float obj) const { return Vector2(x() * obj, y() * obj); }
Vector2 Vector2::operator/(const float obj) const { return Vector2(x() / obj, y() / obj); }

Vector2& Vector2::operator+=(const Vector2& obj) { return *this = this->operator+(obj); }
Vector2& Vector2::operator-=(const Vector2& obj) { return *this = this->operator-(obj); }
Vector2& Vector2::operator*=(const float obj) { return *this = this->operator*(obj); }
Vector2& Vector2::operator/=(const float obj) { return *this = this->operator/(obj); }

bool Vector2::operator==(const Vector2& obj) const { return x() == obj.x() && y() == obj.y(); }
bool Vector2::operator!=(const Vector2& obj) const { return !this->operator==(obj); }

Vector2::operator Vector3() const { return Vector3(x(), y(), 0); }

void Vector2::Set(const float x, const float y) {
	_x = x;
	_y = y;
}
float Vector2::sqrMagnitude() const { return std::pow(x(), 2) + std::pow(y(), 2); }
float Vector2::magnitude() const { return std::sqrt(sqrMagnitude()); }
Vector2 Vector2::normalized() const {
	float _magnitude = magnitude();
	return _magnitude < FLT_EPSILON ? Vector2::zero() : *this / _magnitude;
}

float Vector2::Dot(const Vector2& a, const Vector2& b) { return a.x() * b.x() + a.y() * b.y(); }
float Vector2::Distance(const Vector2& a, const Vector2& b) { return (a - b).magnitude(); }
Vector2 Vector2::Perpendicular(const Vector2& obj) { return Vector2(-obj.y(), obj.x()); }
Vector2 Vector2::Lerp(const Vector2& a, const Vector2& b, float t) { return a + (b - a) * t; }
