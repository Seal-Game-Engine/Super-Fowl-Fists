#include "Scene.h"
#include "GameObject.h"
//#include "Transform.h"
using namespace SealEngine;

Scene::Scene(std::vector<GameObjectInitializer> gameObjects) : _gameObjects(gameObjects) {}

void Scene::Load() {
    for (auto& __gameObject : _gameObjects) {
        auto gameObject = Object::InstantiateT<GameObject>(*__gameObject.gameObject, __gameObject.transform.position, Transform());
        gameObject->transform->scale = __gameObject.transform.scale;
    }
}

void Scene::Unload(){
    while (!instantiationQueue.empty()) instantiationQueue.pop();
    while (!destroyQueue.empty()) destroyQueue.pop();
    while (!awakeEventQueue.empty()) awakeEventQueue.pop();
    while (!awakeEventQueue.empty()) awakeEventQueue.pop();
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
        for (auto& component : gameObject->components) { if (component->enabled) component->Update(); }
        for (auto& component : gameObject->components) { if (component->enabled) component->LateUpdate(); }
    }

    while (!instantiationQueue.empty()) {
        //awakeEventQueue.emplace(instantiationQueue.front().get());
        for (auto& component : instantiationQueue.front()->components) component->Awake();
        startEventQueue.emplace(instantiationQueue.front().get());
        gameObjects.emplace_back(instantiationQueue.front());
        instantiationQueue.pop();
    }

    while (!destroyQueue.empty()) {
        for (int i = 0; i < gameObjects.size(); i++) {
            if (*gameObjects[i] == *destroyQueue.front()) {
                for (auto& component : gameObjects[i]->components)component->OnDestroy();
                gameObjects[i].reset();
                gameObjects.erase(gameObjects.begin() + i);
                goto WhileLoop;
            }

            for (int j = 0; j < gameObjects[i]->components.size(); j++) {
                if (*gameObjects[i]->components[j] == *destroyQueue.front()) {
                    gameObjects[i]->components[j]->OnDestroy();
                    gameObjects[i]->components[j].reset();
                    gameObjects[i]->components.erase(gameObjects[i]->components.begin() + j);
                    goto WhileLoop;
                }
            }
        }
    WhileLoop:
        destroyQueue.pop();
    }
}
