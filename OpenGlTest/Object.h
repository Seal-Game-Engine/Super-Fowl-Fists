#pragma once
#include <string>
#include <vector>
#include <memory>
#include <type_traits>
#include "IClonable.h"
#include "Vector3.h"
namespace SealEngine { class Transform; }

namespace SealEngine {
	class Object : public IClonable {
	public:
		enum class FindObjectsInactive { Exclude, Include };

		std::string name;
		int GetInstanceId() const;
		const std::string& ToString() const;

		static void Destroy(Object, float = 0.0f);
		static void DestroyImmediate(Object, bool = false);
		static void DontDestroyOnLoad(Object);

		template<class T, typename std::enable_if_t<std::is_base_of<Object, T>::value, bool> = true>
		static T FindFirstObjectByType(FindObjectsInactive = FindObjectsInactive::Exclude) { 
			return T();
		}

		template<class T, typename std::enable_if_t<std::is_base_of<Object, T>::value, bool> = true>
		static std::vector<T> FindObjectsByType(FindObjectsInactive = FindObjectsInactive::Exclude) {
			return std::vector<T>(); 
		}

		static Object* Instantiate(Object);
		static Object Instantiate(Object, Transform, bool = true);
		static Object Instantiate(Object, Vector3, Transform);
		//todo: check gameobject's version

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

		virtual Object* Clone_impl() const override { return new Object(*this); }
	};
}

