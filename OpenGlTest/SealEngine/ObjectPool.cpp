#include "ObjectPool.h"
#include "Object.h"
using namespace SealEngine;

GameObject* ObjectPool::Get() {
    if (_objects.empty())
        return Object::InstantiateT(objectOriginal);
    else {
        auto object = _objects.top();
        _objects.pop();
        return object;
    }
}

void ObjectPool::Release(GameObject* object) { _objects.push(object); }

ObjectPool::ObjectPool(const GameObject& objectOriginal) :objectOriginal(objectOriginal) {}
