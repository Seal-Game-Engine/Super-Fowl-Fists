#include "Scene.h"
#include "GameObject.h"
using namespace SealEngine;

Scene::Scene(std::vector<GameObjectInitializer> gameObjects) : _gameObjects(gameObjects) {}

void Scene::DontDestroyOnLoad(GameObject* target) {
    if (SceneManager::IsDontDestroyOnLoad(target)) return;

    for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
        if (*gameObject.get() != *target) continue;

        SceneManager::dontDestroyOnLoadObjects.emplace_back(gameObject);
        return;
    }
}

void Scene::Load() {
    for (auto& __gameObject : _gameObjects) {
        auto gameObject = Object::InstantiateT<GameObject>(*__gameObject.gameObject, __gameObject.transform.position);
        gameObject->transform->scale = __gameObject.transform.scale;
    }
    for (auto& __gameObject : SceneManager::dontDestroyOnLoadObjects) _dontDestroyOnLoadQueue.emplace(__gameObject);
}

void Scene::Unload(){
    while (!instantiationQueue.empty()) instantiationQueue.pop();
    while (!destroyQueue.empty()) destroyQueue.pop();
    while (!_awakeEventQueue.empty()) _awakeEventQueue.pop();
    while (!_startEventQueue.empty()) _startEventQueue.pop();
    for (auto& gameObject : gameObjects) {
        if (!SceneManager::IsDontDestroyOnLoad(gameObject.get()))
            for (auto& component : gameObject->components) component->OnDestroy();
    }
    gameObjects.clear();
    _uiElements.clear();
}

void Scene::RefreshWorld() {
    while (!_awakeEventQueue.empty()) {
        for (auto& component : _awakeEventQueue.front()->components) component->Awake();
        _awakeEventQueue.pop();
    }
    while (!_startEventQueue.empty()) {
        for (auto& component : _startEventQueue.front()->components) component->Start();
        _startEventQueue.pop();
    }

    for (auto& gameObject : gameObjects) {
        if (!gameObject->activeSelf()) continue;
        for (auto& component : gameObject->components) { if (component->enabled) component->RunCoroutines(); }
        for (auto& component : gameObject->components) { if (component->enabled) component->Update(); }
        for (auto& component : gameObject->components) { if (component->enabled) component->LateUpdate(); }
    }    
}

void Scene::RefreshGui(){
    for (auto& uiElement : _uiElements) if (uiElement->gameObject->activeSelf() && uiElement->enabled) uiElement->OnGui();
}

void Scene::RefreshHierarchy() {
    while (!destroyQueue.empty()) {
        for (int i = 0; i < gameObjects.size(); i++) {
            if (*gameObjects[i] == *destroyQueue.front()) {
                for (auto& component : gameObjects[i]->components) component->OnDestroy();
                for (auto& uiElement : gameObjects[i]->GetComponents<Ui::UiElement>()) _uiElements.remove(uiElement);
                if (SceneManager::IsDontDestroyOnLoad(gameObjects[i].get())) SceneManager::dontDestroyOnLoadObjects.remove(gameObjects[i]);
                gameObjects[i].reset();
                gameObjects.erase(gameObjects.begin() + i);
                goto WhileLoop;
            }

            for (int j = 0; j < gameObjects[i]->components.size(); j++) {
                if (*gameObjects[i]->components[j] == *destroyQueue.front()) {
                    gameObjects[i]->components[j]->OnDestroy();
                    if (auto uiElement = dynamic_cast<Ui::UiElement*>(gameObjects[i]->components[j].get())) _uiElements.remove(uiElement);
                    gameObjects[i]->components[j].reset();
                    gameObjects[i]->components.erase(gameObjects[i]->components.begin() + j);
                    goto WhileLoop;
                }
            }
        }
    WhileLoop:
        destroyQueue.pop();
    }

    while (!instantiationQueue.empty()) {
        _awakeEventQueue.emplace(instantiationQueue.front().get());
        _startEventQueue.emplace(instantiationQueue.front().get());
        gameObjects.emplace_back(instantiationQueue.front());
        auto uiElements = instantiationQueue.front()->GetComponents<Ui::UiElement>();
        _uiElements.insert(_uiElements.end(), uiElements.begin(), uiElements.end());
        instantiationQueue.pop();
    }
    while (!_dontDestroyOnLoadQueue.empty()) {
        gameObjects.emplace_back(_dontDestroyOnLoadQueue.front());
        auto uiElements = _dontDestroyOnLoadQueue.front()->GetComponents<Ui::UiElement>();
        _uiElements.insert(_uiElements.end(), uiElements.begin(), uiElements.end());
        _dontDestroyOnLoadQueue.pop();
    }
}
