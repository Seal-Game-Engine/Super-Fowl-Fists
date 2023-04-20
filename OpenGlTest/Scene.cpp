#include "Scene.h"
using namespace SealEngine;

Scene::Scene(std::vector<std::tuple<GameObject, Transform>> gameObjects) : _gameObjects(gameObjects) {}

void Scene::Load() {
    for (auto& gameObject : _gameObjects) Object::Instantiate(std::get<0>(gameObject));//Object::Instantiate(std::get<0>(gameObject), std::get<1>(gameObject).position, Transform());
}

void Scene::Unload(){
    gameObjects.clear();
}

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
        if (!gameObject->activeSelf()) continue;
        for (auto& component : gameObject->components) { if (component->enabled)component->Update(); }
        for (auto& component : gameObject->components) { if (component->enabled) component->LateUpdate(); }
    }

    while (!instantiationQueue.empty()) {
        awakeEventQueue.push(instantiationQueue.front().get());
        startEventQueue.push(instantiationQueue.front().get());
        gameObjects.push_back(instantiationQueue.front());
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
