#pragma once
#include <vector>
#include <string>
#include <array>
#include <memory>

#include "Object.h"
#include "MonoBehaviour.h"
#include "Vector3.h"

using params = int;

namespace SealEngine {
	class GameObject : public Object {
		GameObject();
		GameObject(std::string name);
		GameObject(std::string name, params);

	public:
		std::vector<std::unique_ptr<MonoBehaviour>> componentsList = std::vector<std::unique_ptr<MonoBehaviour>>{};
		bool activeInHierarchy;
		bool activeSelf() const;
		bool isStatic;
		std::string tag;
		// layer
		// scene
		// sceneCullingMask
		// transform;

		// Identifier
		static GameObject Find(std::string name);
		static GameObject* FindWithTag(std::string tag);
		static std::vector<GameObject> FindGameObjectsWithTag(std::string tag);
		bool CompareTag(std::string tag);  // done
		void SetActive(bool value);          // done

		// Components
		template <class T>
			requires std::is_base_of<MonoBehaviour, T>::value
		T AddComponent();
		template <class T>
			requires std::is_base_of<MonoBehaviour, T>::value
		T GetComponent();
		template <class T>
			requires std::is_base_of<MonoBehaviour, T>::value
		bool TryGetComponent(T& component);  

		template <class T>
			requires std::is_base_of<MonoBehaviour, T>::value
		T GetComponentInParent(bool includeInactive = false);
		template <class T>
			requires std::is_base_of<MonoBehaviour, T>::value
		T GetComponentInChild(bool includeInactive = false);

		template <class T>
			requires std::is_base_of<MonoBehaviour, T>::value
		std::vector<T> GetComponentsInParent(bool includeInactive = false);  //
		template <class T>
			requires std::is_base_of<MonoBehaviour, T>::value
		std::vector<T> GetComponentsInChild(bool includeInactive = false);  //


	private:
		bool _activeSelf;
	};
}  // namespace SealEngine
