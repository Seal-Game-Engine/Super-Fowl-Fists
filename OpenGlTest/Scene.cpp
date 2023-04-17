#include "Scene.h"
using namespace SealEngine;

void Scene::Refresh() {
    for (auto& gameObject : gameObjects) {
        for (auto& component : gameObject->components) component->Update();
        for (auto& component : gameObject->components) component->LateUpdate();
    }

    while (!instantiationQueue.empty()) {
        gameObjects.emplace_back(instantiationQueue.front());
        instantiationQueue.pop_back();
    }

    while (!destroyQueue.empty()) {
        for (int i = 0; i < gameObjects.size(); i++) {
            if (*gameObjects[i] == *destroyQueue.front()) {
                gameObjects[i].reset();
                gameObjects.erase(gameObjects.begin() + i);
                goto WhileLoop;
            }
        }
    WhileLoop:
        destroyQueue.pop_back();
    }
}
