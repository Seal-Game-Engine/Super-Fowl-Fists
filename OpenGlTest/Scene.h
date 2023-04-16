#pragma once
#include <vector>
#include "GameObject.h"

namespace SealEngine {
	class Scene {
	public:
		void virtual Refresh();

		std::vector<std::shared_ptr<GameObject>> gameObjects = std::vector<std::shared_ptr<GameObject>>{};
	};
}

