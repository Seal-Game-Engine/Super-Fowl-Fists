#pragma once
#include "Vector3.h"
#include "MonoBehaviour.h"

namespace SealEngine {
	class Transform : public MonoBehaviour {
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