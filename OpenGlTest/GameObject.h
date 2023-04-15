#pragma once
#include <vector>
#include <string>
#include <array>

#include "Object.h"
#include "MonoBehaviour.h"
#include "Vector3.h"
#include "Transform.h"

namespace SealEngine {
	class GameObject : public Object {
	public:
		GameObject();
		GameObject(const std::string& name);
		GameObject(const std::string& name, std::vector<MonoBehaviour> components);

		std::vector<MonoBehaviour> components = std::vector<MonoBehaviour>{};
		bool activeInHierarchy();
		bool activeSelf() const;
		bool isStatic = false;
		std::string tag;
		// layer
		// scene
		// sceneCullingMask
		Transform transform;

		// Identifier
		static GameObject Find(std::string name);
		static GameObject* FindWithTag(std::string tag);
		static std::vector<GameObject> FindGameObjectsWithTag(std::string tag);
		bool CompareTag(std::string tag);  // done
		void SetActive(bool value);          // done

		// Components
		template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
		T AddComponent() {
			components.push_back(T());
		}

		template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
		T GetComponent() {
		}

		template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
		bool TryGetComponent(T& component) {
			/*return std::find(componentsList.begin(), componentsList.end(), [](const MonoBehaviour& _component) {
		component = dynamic_cast<T>(_component);
		return component;
		});*/
			return true;
		}

		template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
		T GetComponentInParent(bool includeInactive = false) {
			return T();
		}


		template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
		T GetComponentInChild(bool includeInactive = false) {
			return T();
		}

		template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
		std::vector<T> GetComponentsInParent(bool includeInactive = false) {
			return std::vector<T>();
		
		}

		template<class T, typename std::enable_if_t<std::is_base_of<MonoBehaviour, T>::value, bool> = true>
		std::vector<T> GetComponentsInChild(bool includeInactive = false) {
			return std::vector<T>();
		}


	private:
		bool _activeSelf = true;
	};
}  // namespace SealEngine
