#include "GameObject.h"
#include "Transform.h"
using namespace SealEngine;

//constructors
GameObject::GameObject() 
	: Object("GameObject"), transform() {
	transform.gameObject = this;
	components.emplace_back(transform);
}
GameObject::GameObject(const std::string& name) 
	: Object(name), transform() {
	transform.gameObject = this;
	components.emplace_back(transform);
}
GameObject::GameObject(const std::string& name, std::vector<MonoBehaviour> components) 
	: Object(name), components(components), transform() {
	transform.gameObject = this;
	this->components.emplace_back(transform);

	for (auto& component : this->components) {
		component.gameObject = this;
	}
}

bool GameObject::activeSelf() const { return _activeSelf; }
//Object GameObject::Object::Instantiate(Object) {}
GameObject GameObject::Find(std::string name) { return GameObject(name); }
GameObject* GameObject::FindWithTag(std::string tag) { return nullptr; }
std::vector<GameObject> GameObject::FindGameObjectsWithTag(std::string tag) { return std::vector<GameObject>(); } //need SceneManager
bool GameObject::CompareTag(std::string tag) { return this->tag == tag; }
void GameObject::SetActive(bool value) { _activeSelf = value; }