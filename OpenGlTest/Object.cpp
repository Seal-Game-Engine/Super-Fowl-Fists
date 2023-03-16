#include "Object.h"
using namespace SealEngine;

int Object::GetInstanceId() const { return _instanceId; }
const std::string& Object::ToString() const { return name; }

void Object::Destroy(Object object, float delayDuration) {
}

void Object::DestroyImmediate(Object object, bool allowDestroyingAssets) {
}

void Object::DontDestroyOnLoad(Object target) {
}

template<class T>
	requires std::is_base_of<Object, T>::value
T Object::FindFirstObjectByType(FindObjectsInactive findObjectsInactive) {
	return T();
}

template<class T>
	requires std::is_base_of<Object, T>::value
std::vector<T> Object::FindObjectsByType(FindObjectsInactive findObjectsInactive) {
	return std::vector<T>();
}


Object::operator bool() const { return true; }
bool Object::operator==(const Object& obj) const { return GetInstanceId() == obj.GetInstanceId(); }
bool Object::operator!=(const Object& obj) const { return !this->operator==(obj); }


