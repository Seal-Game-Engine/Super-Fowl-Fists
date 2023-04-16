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
		
		Transform();
		Transform(Vector3 position, Vector3 rotation, Vector3 scale);
		std::shared_ptr<Transform> Clone() const { return std::shared_ptr<Transform>(Clone_impl()); }

	private:
		virtual Transform* Clone_impl() const override { return new Transform(*this); }
	};
}