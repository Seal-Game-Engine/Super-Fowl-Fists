#include "GameObject.h"
#include "Transform.h"
#include <system_error>
using namespace SealEngine;

//constructors
GameObject::GameObject();
GameObject::GameObject(std::string name){
	this->name = name;
	Transform transform;
	transform.gameObject();
	componentsList.emplace_back(Transform());
}

bool GameObject::activeSelf() const { return _activeSelf; }
//Object GameObject::Object::Instantiate(Object) {}
GameObject GameObject::Find(std::string name) { return GameObject(name); }
GameObject* GameObject::FindWithTag(std::string tag) { return nullptr; }
std::vector<GameObject> GameObject::FindGameObjectsWithTag(std::string tag) { return std::vector<GameObject>(); } //need SceneManager
bool GameObject::CompareTag(std::string tag) { return this->tag == tag; }
void GameObject::SetActive(bool value) { _activeSelf = value; }

template <class T>
	requires std::is_base_of<MonoBehaviour, T>::value
T AddComponent() { componentsList.pushback(T); }
template <class T>
	requires std::is_base_of<MonoBehaviour, T>::value
T GetComponent() { }
template <class T>
	requires std::is_base_of<MonoBehaviour, T>::value
bool TryGetComponent(T& component) { return std::find(componentsList.begin(), compon.end(), c)
}

//Component
template <class T>
	requires std::is_base_of<MonoBehaviour, T>::value
T GetComponentInParent() { return T(); }
template <class T>
	requires std::is_base_of<MonoBehaviour, T>::value
T GetComponentInChild() { return T(); }

//Component(s)
template <class T>
	requires std::is_base_of<MonoBehaviour, T>::value
std::vector<T> GetComponentsInParent() { return std::vector<T>(); }
template <class T>
	requires std::is_base_of<MonoBehaviour, T>::value
std::vector<T> GetComponentsInChild() { return std::vector<T>(); }