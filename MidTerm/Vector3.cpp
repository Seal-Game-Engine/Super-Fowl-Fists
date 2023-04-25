#include "Vector3.h"
#include <cmath>
#include "Vector2.h"
using namespace SealEngine;

Vector3::Vector3(const float x, const float y, const float z): _x(x), _y(y), _z(z) {}
Vector3::Vector3(const Vector3& obj) :_x(obj.x()), _y(obj.y()), _z(obj.z()) {}

float Vector3::x() const { return _x; }
float Vector3::y() const { return _y; }
float Vector3::z() const { return _z; }

Vector3 Vector3::zero() { return Vector3(0, 0, 0); }
Vector3 Vector3::one() { return Vector3(1, 1, 1); }
Vector3 Vector3::up() { return Vector3(0, 1, 0); }
Vector3 Vector3::down() { return Vector3(0, -1, 0); }
Vector3 Vector3::left() { return Vector3(-1, 0, 0); }
Vector3 Vector3::right() { return Vector3(1, 0, 0); }
Vector3 Vector3::forward() { return Vector3(0, 0, 1); }
Vector3 Vector3::back() { return Vector3(0, 0, -1); }

Vector3 Vector3::operator+(const Vector3& obj) const { return Vector3(x() + obj.x(), y() + obj.y(),z() + obj.z()); }
Vector3 Vector3::operator-(const Vector3& obj) const { return Vector3(x() - obj.x(), y() - obj.y(), z() - obj.z()); }
Vector3 Vector3::operator*(const float obj) const { return Vector3(x() * obj, y() * obj, z() * obj); }
Vector3 Vector3::operator/(const float obj) const { return Vector3(x() / obj, y() / obj, z() / obj); }

Vector3& Vector3::operator+=(const Vector3& obj) { return *this = this->operator+(obj); }
Vector3& Vector3::operator-=(const Vector3& obj) { return *this = this->operator-(obj); }
Vector3& Vector3::operator*=(const float obj) { return *this = this->operator*(obj); }
Vector3& Vector3::operator/=(const float obj) { return *this = this->operator/(obj); }

bool Vector3::operator==(const Vector3& obj) const { return x() == obj.x() && y() == obj.y() && z() == obj.z(); }
bool Vector3::operator!=(const Vector3& obj) const { return !this->operator==(obj); }

Vector3::operator Vector2() const { return Vector2(x(), y()); }

void Vector3::Set(const float x, const float y, const float z) {
	_x = x;
	_y = y;
	_z = z;
}
float Vector3::sqrMagnitude() const { return std::pow(x(), 2) + std::pow(y(), 2) + std::pow(z(), 2); }
float Vector3::magnitude() const { return std::sqrt(sqrMagnitude()); }
Vector3 Vector3::normalized() const { return *this / magnitude(); }

float Vector3::Dot(const Vector3& a, const Vector3& b) { return a.x() * b.x() + a.y() * b.y() + a.z() * b.z(); }
Vector3 Vector3::Cross(const Vector3& a, const Vector3& b) {
	return Vector3(
		a.y() * b.z() - a.z() * b.y(),
		a.x() * b.z() - a.z() * b.x(),
		a.x() * b.y() - a.y() * b.x()
	);
}
float Vector3::Distance(const Vector3& a, const Vector3& b) { return (a - b).magnitude(); }

Vector3 Vector3::ProjectOnPlane(const Vector3& vector, const Vector3& planeNormal) {
	// Calculate the projection of the vector onto the plane
	return planeNormal * Vector3::Dot(vector, planeNormal);//todo
}

