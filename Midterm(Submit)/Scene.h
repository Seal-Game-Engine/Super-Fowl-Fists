#pragma once
#include <vector>
#include <queue>
#include <tuple>
#include "GameObject.h"

namespace SealEngine
{
class Scene
{
private:
    struct GameObjectInitializer
    {
        const GameObject* gameObject;
        Transform transform;
    };
public:

    Scene(std::vector<GameObjectInitializer> gameObjects);
    void Load();
    void Unload();
    void Refresh();

    std::vector<std::shared_ptr<GameObject>> gameObjects{};
    std::queue<std::shared_ptr<GameObject>> instantiationQueue{};
    std::queue<GameObject*> destroyQueue{};

private:
    std::vector<GameObjectInitializer> _gameObjects{};

    std::queue<GameObject*> awakeEventQueue{};
    std::queue<GameObject*> startEventQueue{};
};
}
