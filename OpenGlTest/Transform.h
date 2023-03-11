#pragma once
#include "Vector3.h"
//namespace SealEngine { struct Vector3; }

namespace SealEngine {
	class Transform {
	public:
		Transform();
		Transform(Vector3, Vector3, Vector3);

		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		Vector3 up() const;
		Vector3 right() const;
		Vector3 forward() const;
	};
}