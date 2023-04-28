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
		static T* FindFirstObjectByType(FindObjectsInactive findObjectsInactive = FindObjectsInactive::Exclude) {
			T* target = nullptr;

			for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
				if (findObjectsInactive == FindObjectsInactive::Exclude && !gameObject->activeSelf()) continue;
				if (target = dynamic_cast<T*>(gameObject.get())) return target;

				for (auto& component : gameObject->components) {
					if (!component->enabled) continue;
					if (target = dynamic_cast<T*>(component.get())) return target;
				}
			}
			return nullptr;
		}

		template<class T, typename std::enable_if_t<std::is_base_of<Object, T>::value, bool> = true>
		static std::vector<T*> FindObjectsByType(FindObjectsInactive findObjectsInactive = FindObjectsInactive::Exclude) {
			std::vector<T*> targets{};

			for (auto& gameObject : SceneManager::GetActiveScene()->gameObjects) {
				if (findObjectsInactive == FindObjectsInactive::Exclude && !gameObject->activeSelf()) continue;
				if (auto target = dynamic_cast<T*>(gameObject.get())) targets.emplace_back(target);

				for (auto& component : gameObject->components) {
					if (!component->enabled) continue;
					if (auto target = dynamic_cast<T*>(component.get())) targets.emplace_back(target);
				}
			}
			return targets;
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

		Object* _Clone() const override { return new Object(*this); }
	};
}

