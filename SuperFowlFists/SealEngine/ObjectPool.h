#pragma once
#include <stack>
#include "GameObject.h"

namespace SealEngine {
	class ObjectPool {
	public:
		GameObject* Get();
		void Release(GameObject* object);

		ObjectPool(const GameObject& objectOriginal);

	private:
		const GameObject& objectOriginal;
		std::stack<GameObject*> _objects{};
	};
}

