#pragma once
#include <vector>
#include <string>
#include <array>
#include <type_traits>

#include "Object.h"
#include "MonoBehaviour.h"
#include "Vector3.h"
#include "Transform.h"

using params = int;

namespace SealEngine {
	class GameObject : public Object {
	public:
		GameObject();
		GameObject(std::string name);
		GameObject(std::string name, params);

		std::vector<MonoBehaviour> componentsList = std::vector<MonoBehaviour>{};
		template<typename T> class my_template;
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
		template <typename T, typename std::enable_if<std::is_base_of<MonoBehaviour, T>::value>::type* = nullptr >
			//requires std::is_base_of<MonoBehaviour, T>::value
		T AddComponent();
		template <class T>
			//requires std::is_base_of<MonoBehaviour, T>::value
		T GetComponent();
		template <class T>
			//requires std::is_base_of<MonoBehaviour, T>::value
		bool TryGetComponent(T& component);

		template <class T>
			//requires std::is_base_of<MonoBehaviour, T>::value
		T GetComponentInParent(bool includeInactive = false);
		template <class T>
			//requires std::is_base_of<MonoBehaviour, T>::value
		T GetComponentInChild(bool includeInactive = false);

		template <class T>
			//requires std::is_base_of<MonoBehaviour, T>::value
		std::vector<T> GetComponentsInParent(bool includeInactive = false);  //
		template <class T>
			//requires std::is_base_of<MonoBehaviour, T>::value
		std::vector<T> GetComponentsInChild(bool includeInactive = false);  //


	private:
		bool _activeSelf = true;
	};
}  // namespace SealEngine
