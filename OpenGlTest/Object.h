#pragma once
#include <string>
#include <vector>
#include "Transform.h"

namespace SealEngine {
	class Object {
	public:
		enum class FindObjectsInactive { Exclude, Include };

		std::string name;
		int GetInstanceId() const;
		const std::string& ToString() const;

		static void Destroy(Object, float = 0.0f);
		static void DestroyImmediate(Object, bool = false);
		static void DontDestroyOnLoad(Object);

		template<class T>
			requires std::is_base_of<Object, T>::value
		static T FindFirstObjectByType(FindObjectsInactive = FindObjectsInactive::Exclude);

		template<class T>
			requires std::is_base_of<Object, T>::value
		static std::vector<T> FindObjectsByType(FindObjectsInactive = FindObjectsInactive::Exclude);

		static Object Instantiate(Object);
		static Object Instantiate(Object, Transform, bool = true);
		static Object Instantiate(Object, Vector3, Transform);
		//todo: check gameobject's version

		Object();

		operator bool() const;
		bool operator!=(const Object&)const;
		bool operator==(const Object&)const;

	private:
		int _instanceId;
	};
}

