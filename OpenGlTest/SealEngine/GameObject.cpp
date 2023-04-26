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
GameObject::GameObject(const std::string& name)
	: Object(name) {
	auto _transform = std::make_shared<Transform>();
	_transform->gameObject = this;
	transform = _transform.get();
	components.emplace_back(_transform);
}
GameObject::GameObject(const std::string& name, std::vector<MonoBehaviour> components)
	: Object(name){//}, components(components), transform() {

	//this->components.emplace_back(transform);

	/*for (auto& component : this->components) {
		component.gameObject = this;
	}*/
	/*transform.gameObject = this;
	this->components.emplace_back(transform);

	for (auto& component : components) {
		this->components.emplace_back(component);
	}
	for (auto& component : this->components) {
		component->gameObject = this;
	}*/
}
GameObject::GameObject(const std::string& name, std::vector<std::shared_ptr<MonoBehaviour>> components)
	: Object(name), components(std::move(components)) {
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
GameObject GameObject::Find(std::string name) { return GameObject(name); }
GameObject* GameObject::FindWithTag(std::string tag) { return nullptr; }
std::vector<GameObject*> GameObject::FindGameObjectsWithTag(const std::string& tag) {
	std::vector<GameObject*> gameObjectsFound{};
	for (auto& _gameObject : SceneManager::scenes[SceneManager::currentSceneId]->gameObjects) {
		if (_gameObject->tag == tag)
			gameObjectsFound.emplace_back(_gameObject.get());
	}
	return gameObjectsFound;
}
bool GameObject::CompareTag(std::string tag) { return this->tag == tag; }
void GameObject::SetActive(bool value) { _activeSelf = value; }

//template<>
//Player* GameObject::GetComponent()
//{
//	Player* component = nullptr;
//	for (auto& _component : components) if (component = dynamic_cast<Player*>(_component.get())) break;
//	/*for (auto& _component : components) {
//		MonoBehaviour* temp = &_component;
//		component = dynamic_cast<T*>(&_component);
//		if (component)  break;
//	}*/
//	return component;
//}
