#include "Scene.h"
using namespace SealEngine;

void Scene::Refresh() {
    for (auto& gameObject : gameObjects) {
        for (auto& component : gameObject->components) component->Update();
        for (auto& component : gameObject->components) component->LateUpdate();
    }
}
