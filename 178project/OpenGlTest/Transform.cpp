#include "Transform.h"
#include <cmath>
#include "SealEngine.h"
using namespace SealEngine;

Transform::Transform() 
	: position(Vector3::zero()), rotation(Vector3::zero()), scale(Vector3::one()) {}
Transform::Transform(Vector3 position, Vector3 rotation, Vector3 scale) 
	: position(position), rotation(rotation), scale(scale) {}

Vector3 Transform::up() const { 
	Vector3 up = Vector3::up();

	float x = 0, y = 1, z = 0;

	using namespace std;
	up.Set(
		x * cos(rotation.z()) - y * sin(rotation.z()),
		x * sin(rotation.z()) + y * cos(rotation.z()),
		z
	);

	x = up.x();
	y = up.y();
	z = up.z();

	up.Set(
		x * cos(rotation.y()) + z * sin(rotation.y()),
		y,
		-x * sin(rotation.y()) + z * cos(rotation.y())
	);

	x = up.x();
	y = up.y();
	z = up.z();

	up.Set(
		x,
		y * cos(rotation.x()) - z * sin(rotation.x()),
		y * sin(rotation.x()) + z * cos(rotation.x())
	);

	return up; 
}

Vector3 Transform::right()const { return Vector3::right(); }

Vector3 Transform::forward()const { 
	Vector3 forward = Vector3::forward();

	float x = 0, y = 0, z = 1;

	using namespace std;
	forward.Set(
		x * cos(rotation.z()) - y * sin(rotation.z()),
		x * sin(rotation.z()) + y * cos(rotation.z()),
		z
	);

	x = forward.x();
	y = forward.y();
	z = forward.z();

	forward.Set(
		x * cos(rotation.y()) + z * sin(rotation.y()),
		y,
		-x * sin(rotation.y()) + z * cos(rotation.y())
	);

	x = forward.x();
	y = forward.y();
	z = forward.z();

	forward.Set(
		x,
		y * cos(rotation.x()) - z * sin(rotation.x()),
		y * sin(rotation.x()) + z * cos(rotation.x())
	);

	return forward;
}
