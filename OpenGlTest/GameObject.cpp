#include "GameObject.h"
#include <system_error>

bool GameObject::activeSelf() const {return _activeSelf;}
void GameObject::Instantiate(objectId, Vector3, std::vector<MonoBehaviour>){}
GameObject GameObject::FindWithTag(std::string) {}
bool GameObject::CompareTag(std::string tag) {return this->tag == tag;}
void GameObject::SetActive(bool value) {_activeSelf=value;}
template <class T>
requires std::is_base_of<MonoBehaviour,T>
T GameObject::GetComponent() {
}
template<class T>
T GameObject::AddComponent() {

}
