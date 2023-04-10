#include "GameObject.h"
#include "Transform.h"
using namespace SealEngine;

//constructors
GameObject::GameObject() : transform() {
	transform.gameObject = this;
	componentsList.emplace_back(transform);
}
GameObject::GameObject(std::string name) : transform() {
	this->name = name;
	transform.gameObject = this;
	componentsList.emplace_back(transform);
}

bool GameObject::activeSelf() const { return _activeSelf; }
//Object GameObject::Object::Instantiate(Object) {}
GameObject GameObject::Find(std::string name) { return GameObject(name); }
GameObject* GameObject::FindWithTag(std::string tag) { return nullptr; }
std::vector<GameObject> GameObject::FindGameObjectsWithTag(std::string tag) { return std::vector<GameObject>(); } //need SceneManager
bool GameObject::CompareTag(std::string tag) { return this->tag == tag; }
void GameObject::SetActive(bool value) { _activeSelf = value; }

template <class T>
	//requires std::is_base_of<MonoBehaviour, T>::value
T GameObject::AddComponent() { componentsList.push_back(T()); }
template <class T>
	//requires std::is_base_of<MonoBehaviour, T>::value
T GameObject::GetComponent() { }
template <class T>
	//requires std::is_base_of<MonoBehaviour, T>::value
bool GameObject::TryGetComponent(T& component) {
	/*return std::find(componentsList.begin(), componentsList.end(), [](const MonoBehaviour& _component) {
		component = dynamic_cast<T>(_component);
		return component;
		});*/
		return true;
}

//Component
template <class T>
	//requires std::is_base_of<MonoBehaviour, T>::value
T GameObject::GetComponentInParent(bool includeInactive) { return T(); }
template <class T>
	//requires std::is_base_of<MonoBehaviour, T>::value
T GameObject::GetComponentInChild(bool includeInactive) { return T(); }

//Component(s)
template <class T>
	//requires std::is_base_of<MonoBehaviour, T>::value
std::vector<T> GameObject::GetComponentsInParent(bool includeInactive) { return std::vector<T>(); }
template <class T>
	//requires std::is_base_of<MonoBehaviour, T>::value
std::vector<T> GameObject::GetComponentsInChild(bool includeInactive) { return std::vector<T>(); }
