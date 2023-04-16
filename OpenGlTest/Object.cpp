#include "Object.h"
#include "SceneManager.h"
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
Object::Object(const Object& obj) : _instanceId(_instanceIdCounter++), name(obj.name + " (Clone)") {}
std::shared_ptr<Object> Object::Clone() const { return std::shared_ptr<Object>(Clone_impl()); }


Object::operator bool() const { return true; }
bool Object::operator==(const Object& obj) const { return GetInstanceId() == obj.GetInstanceId(); }
bool Object::operator!=(const Object& obj) const { return !this->operator==(obj); }

Object* Object::Instantiate(Object obj) {
	GameObject* gameObject = nullptr;

	if (gameObject = dynamic_cast<GameObject*>(&obj)) {
		//GameObject gameObject = x;
		SceneManager::scenes[SceneManager::currentSceneId]->gameObjects.emplace_back(std::shared_ptr<GameObject>(gameObject));

	}
	//}else if(gameObject = dynamic_cast<MonoBehaviour*>(&obj)->gameObject){


	//	//SceneManager::scenes[SceneManager::currentSceneId]->gameObjects.push_back(x);

	//}
	//SceneManager::scenes[SceneManager::currentSceneId]->gameObjects.push_back(GameObject(Object obj));
	return gameObject;
}
