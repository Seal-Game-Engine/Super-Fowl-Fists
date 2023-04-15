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

int Object::_instanceIdCounter = 0;
Object::Object() : _instanceId(_instanceIdCounter++) {}
Object::Object(const std::string& name) : _instanceId(_instanceIdCounter++), name(name) {}

Object::operator bool() const { return true; }
bool Object::operator==(const Object& obj) const { return GetInstanceId() == obj.GetInstanceId(); }
bool Object::operator!=(const Object& obj) const { return !this->operator==(obj); }


