#include "GameObject.h"
#include "Transform.h"
#include "SceneManager.h"
#include "Scene.h"
using namespace SealEngine;

//constructors
GameObject::GameObject()
	: Object("GameObject") {
	auto _transform = std::make_shared<Transform>();
	_transform->gameObject = this;
	transform = _transform.get();
	components.emplace_back(_transform);
}
GameObject::GameObject(const std::string& name, const std::string& tag)
	: Object(name), tag(tag) {
	auto _transform = std::make_shared<Transform>();
	_transform->gameObject = this;
	transform = _transform.get();
	components.emplace_back(_transform);
}
GameObject::GameObject(const std::string& name, const std::string& tag, std::vector<std::shared_ptr<MonoBehaviour>> components)
	: Object(name), tag(tag), components(std::move(components)) {
	auto _transform = std::make_shared<Transform>();
	_transform->gameObject = this;
	transform = _transform.get();
	this->components.emplace_back(_transform);

	for (auto& component : this->components) {
		component->gameObject = this;
	}
}

GameObject::GameObject(const GameObject& obj)
	: Object(obj), isStatic(obj.isStatic), tag(obj.tag), _activeSelf(obj._activeSelf) {

	for (auto& component : obj.components) {
		std::shared_ptr<MonoBehaviour> comp = component->Clone();
		comp->gameObject = this;
		components.emplace_back(comp);
	}
	transform = GetComponent<Transform>();
}

bool GameObject::activeSelf() const { return _activeSelf; }

GameObject* GameObject::Find(const std::string& name) {
	for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
		if (!gameObject->activeSelf()) continue;
		if (gameObject->name == name) return gameObject.get();
	}
	return nullptr; 
}
GameObject* GameObject::FindWithTag(const std::string& tag) { 
	for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
		if (!gameObject->activeSelf()) continue;
		if (gameObject->CompareTag(tag)) return gameObject.get();
	}
	return nullptr;
}

std::vector<GameObject*> GameObject::FindGameObjectsWithTag(const std::string& tag) {
	std::vector<GameObject*> gameObjectsFound{};
	for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
		if (gameObject->CompareTag(tag))
			gameObjectsFound.emplace_back(gameObject.get());
	}
	return gameObjectsFound;
}
bool GameObject::CompareTag(std::string tag) { return this->tag == tag; }
void GameObject::SetActive(bool value) { SceneManager::GetActiveScene()->actionQueue.emplace([=] { _activeSelf = value; }); }
