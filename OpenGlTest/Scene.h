#pragma once
#include <vector>
#include <queue>
#include "GameObject.h"

namespace SealEngine {
	class Scene {
	public:
		void virtual Load() {}
		void virtual Refresh();

		std::vector<std::shared_ptr<GameObject>> gameObjects = std::vector<std::shared_ptr<GameObject>>{};
		std::vector<std::shared_ptr<GameObject>> instantiationQueue = std::vector<std::shared_ptr<GameObject>>{};
		std::vector<GameObject*> destroyQueue = std::vector<GameObject*>{};
	};
}

