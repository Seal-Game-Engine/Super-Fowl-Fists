#include "Scene.h"
using namespace SealEngine;

void Scene::Refresh() {
    while (!awakeEventQueue.empty()) {
        for (auto& component : awakeEventQueue.front()->components) component->Awake();
        awakeEventQueue.pop();
    }
    while (!startEventQueue.empty()) {
        for (auto& component : startEventQueue.front()->components) component->Start();
        startEventQueue.pop();
    }

    for (auto& gameObject : gameObjects) {
        for (auto& component : gameObject->components) component->Update();
        for (auto& component : gameObject->components) component->LateUpdate();
    }

    while (!instantiationQueue.empty()) {
        awakeEventQueue.push(instantiationQueue.front().get());
        startEventQueue.push(instantiationQueue.front().get());
        gameObjects.emplace_back(instantiationQueue.front());
        instantiationQueue.pop();
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
        destroyQueue.pop();
    }
}
