#pragma once
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include "IClonable.h"
#include "Vector3.h"
#include "SceneManager.h"
//#include "Scene.h"
namespace SealEngine { class Transform; }

namespace SealEngine {
	class Object : public IClonable {
	public:
		enum class FindObjectsInactive { Exclude, Include };

		std::string name;
		int GetInstanceId() const;
		const std::string& ToString() const;

		template<class T, typename std::enable_if_t<std::is_base_of<Object, T>::value, bool> = true>
		static T* FindFirstObjectByType(FindObjectsInactive = FindObjectsInactive::Exclude) {
			T* target = nullptr;

			auto& gameObjects = SceneManager::GetActiveScene()->gameObjects;
			for (int i = 0; i < gameObjects.size(); i++) {
				if (target = dynamic_cast<T*>(gameObjects[i].get())) break;

				for (int j = 0; j < gameObjects[i]->components.size(); j++)
					if (target = dynamic_cast<T*>(gameObjects[i]->components[j].get())) break;
			}
			return target;
		}

		template<class T, typename std::enable_if_t<std::is_base_of<Object, T>::value, bool> = true>
		static std::vector<T> FindObjectsByType(FindObjectsInactive = FindObjectsInactive::Exclude) {
			return std::vector<T>(); 
		}

		static Object* Instantiate(const Object& obj);
		//static Object Instantiate(Object, Transform, bool = true);
		static Object* Instantiate(const Object& obj, const Vector3& position, Transform parent);

		template<class T, typename std::enable_if_t<std::is_base_of<Object, T>::value, bool> = true>
		static T* InstantiateT(const T& obj) { return dynamic_cast<T*>(Instantiate(obj)); }

		template<class T, typename std::enable_if_t<std::is_base_of<Object, T>::value, bool> = true>
		static T* InstantiateT(const T& obj, const Vector3& position, Transform parent) { return dynamic_cast<T*>(Instantiate(obj, position, parent)); }

		//todo: check gameobject's version
		static void Destroy(Object& obj, float = 0.0f);
		static void DestroyImmediate(Object, bool = false);
		static void DontDestroyOnLoad(Object);


		Object();
		Object(const std::string& name);
		Object(const Object& obj);
		std::shared_ptr<Object> Clone() const;

		operator bool() const;
		virtual bool operator!=(const Object&)const;
		virtual bool operator==(const Object&)const;

	private:
		const int _instanceId;

		static int _instanceIdCounter;

		Object* Clone_impl() const override { return new Object(*this); }
	};
}

