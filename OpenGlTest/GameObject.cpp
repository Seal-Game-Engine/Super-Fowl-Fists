#include "GameObject.h"
#include <system_error>
using namespace SealEngine;

bool GameObject::activeSelf() const { return _activeSelf; }

//Object GameObject::Object::Instantiate(Object) {}
GameObject GameObject::Find(std::string name) {}
GameObject* GameObject::FindWithTag(std::string tag) { return nullptr; }
std::vector<GameObject> GameObject::FindGameObjectsWithTag(
	std::string) {
	return std::vector<GameObject>();
}
bool GameObject::CompareTag(std::string tag) { return this->tag == tag; }
void GameObject::SetActive(bool value) { _activeSelf = value; }

