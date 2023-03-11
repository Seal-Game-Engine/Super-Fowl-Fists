#include "Vector2.h"
#include <cmath>
#include "Vector3.h"

using namespace SealEngine;

Vector2::Vector2(const float& x, const float& y) : _x(x), _y(y) {}
Vector2::Vector2(const Vector2& obj) :_x(obj.x()), _y(obj.y()) {}

Vector2::operator Vector3() const { return Vector3(x(), y(), 0); }

const float& Vector2::x() const { return _x; }
const float& Vector2::y() const { return _y; }

void Vector2::Set(const float& x, const float& y) {
	_x = x;
	_y = y;
}

Vector2 Vector2::zero() { return Vector2(0, 0); }
Vector2 Vector2::one() { return Vector2(1, 1); }
Vector2 Vector2::up() { return Vector2(0, 1); }
Vector2 Vector2::down() { return Vector2(0, -1); }
Vector2 Vector2::left() { return Vector2(-1, 0); }
Vector2 Vector2::right() { return Vector2(1, 0); }

Vector2 Vector2::operator+(const Vector2& obj) const { return Vector2(x() + obj.x(), y() + obj.y()); }
Vector2 Vector2::operator-(const Vector2& obj) const { return Vector2(x() - obj.x(), y() - obj.y()); }
Vector2 Vector2::operator*(const float& obj) const { return Vector2(x() * obj, y() * obj); }
Vector2 Vector2::operator/(const float& obj) const { return Vector2(x() / obj, y() / obj); }

Vector2& Vector2::operator+=(const Vector2& obj) { return *this = this->operator+(obj); }
Vector2& Vector2::operator-=(const Vector2& obj) { return *this = this->operator-(obj); }
Vector2& Vector2::operator*=(const float& obj) { return *this = this->operator*(obj); }
Vector2& Vector2::operator/=(const float& obj) { return *this = this->operator/(obj); }

bool Vector2::operator==(const Vector2& obj) const { return x() == obj.x() && y() == obj.y(); }
bool Vector2::operator!=(const Vector2& obj) const { return !this->operator==(obj); }

float Vector2::sqrMagnitude() const { return std::powf(x(), 2) + std::powf(y(), 2); }
float Vector2::magnitude() const { return std::sqrtf(sqrMagnitude()); }
Vector2 Vector2::normalized() const { return *this / magnitude(); }

float Vector2::Dot(const Vector2& a, const Vector2& b) { return a.x() * b.x() + a.y() * b.y(); }
float Vector2::Distance(const Vector2& a, const Vector2& b) { return (a - b).magnitude(); }
