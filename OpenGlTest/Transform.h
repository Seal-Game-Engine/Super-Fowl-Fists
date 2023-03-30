#pragma once
#include "Vector3.h"
#include "MonoBehaviour.h"

namespace SealEngine {
	class Transform : public MonoBehaviour {
	public:
		Vector3 position;
		Vector3 rotation;
		Vector3 scale;

		Vector3 up() const;
		Vector3 right() const;
		Vector3 forward() const;
		
		Transform(GameObject gameObject);
		Transform(GameObject gameObject, Vector3 position, Vector3 rotation, Vector3 scale);
	};
}