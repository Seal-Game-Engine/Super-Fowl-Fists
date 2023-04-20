#pragma once
#include <vector>
#include <queue>
#include <tuple>
#include "GameObject.h"

namespace SealEngine {
	class Scene {
	public:
		Scene(std::vector<std::tuple<GameObject, Transform>> gameObjects);
		void virtual Load();
		void Unload();
		void virtual Refresh();

		std::vector<std::shared_ptr<GameObject>> gameObjects = std::vector<std::shared_ptr<GameObject>>{};
		std::queue<std::shared_ptr<GameObject>> instantiationQueue = std::queue<std::shared_ptr<GameObject>>{};
		std::queue<GameObject*> destroyQueue = std::queue<GameObject*>{};

	private:
		std::vector<std::tuple<GameObject, Transform>> _gameObjects = std::vector<std::tuple<GameObject, Transform>>{};

		std::queue<GameObject*> awakeEventQueue{};
		std::queue<GameObject*> startEventQueue{};
	};
}