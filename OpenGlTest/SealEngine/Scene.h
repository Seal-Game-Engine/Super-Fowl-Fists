#pragma once
#include <vector>
#include <queue>
#include <memory>
#include <tuple>
#include "Transform.h"
#include "GameObject.h"
#include "Ui/UiElement.h"

namespace SealEngine {
    class Object;
    //class GameObject;
    //class Transform;
}

namespace SealEngine {
    class Scene {
    private:
        struct GameObjectInitializer {
            const GameObject* gameObject;
            Transform transform;
        };
    public:
		enum class FindObjectsInactive { Exclude, Include };

		template<class T>
		static T* FindFirstObjectByType(FindObjectsInactive findObjectsInactive = FindObjectsInactive::Exclude) {
			T* target = nullptr;

			for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
				if (findObjectsInactive == FindObjectsInactive::Exclude && !gameObject->activeSelf()) continue;
				if (target = dynamic_cast<T*>(gameObject.get())) return target;

				for (auto& component : gameObject->components) {
					if (!component->enabled) continue;
					if (target = dynamic_cast<T*>(component.get())) return target;
				}
			}
			return nullptr;
		}

		template<class T>
		static std::vector<T*> FindObjectsByType(FindObjectsInactive findObjectsInactive = FindObjectsInactive::Exclude) {
			std::vector<T*> targets{};

			for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
				if (findObjectsInactive == FindObjectsInactive::Exclude && !gameObject->activeSelf()) continue;
				if (auto target = dynamic_cast<T*>(gameObject.get())) targets.emplace_back(target);

				for (auto& component : gameObject->components) {
					if (!component->enabled) continue;
					if (auto target = dynamic_cast<T*>(component.get())) targets.emplace_back(target);
				}
			}
			return targets;
		}

        Scene(std::vector<GameObjectInitializer> gameObjects);
        void Load();
        void Unload();
        void RefreshWorld();
		void RefreshGui();
		void RefreshHierarchy();

        std::vector<std::shared_ptr<GameObject>> gameObjects{};
        std::queue<std::shared_ptr<GameObject>> instantiationQueue{};
        std::queue<Object*> destroyQueue{};

    private:
        std::vector<GameObjectInitializer> _gameObjects{};

        std::queue<GameObject*> _awakeEventQueue{};
        std::queue<GameObject*> _startEventQueue{};
		std::list<Ui::UiElement*> _uiElements{};
    };
}
