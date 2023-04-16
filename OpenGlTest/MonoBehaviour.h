#pragma once
#include <string>
#include "Object.h"
namespace SealEngine { 
	class Transform;
	class GameObject;
}

namespace SealEngine {
	class MonoBehaviour : public Object {
	public:
#pragma region Messages
        virtual void Awake() {}
		virtual void FixedUpdate() {}
		virtual void LateUpdate() {}

		virtual void OnCollisionEnter() {}
		virtual void OnCollisionEnter2D() {}
		virtual void OnCollisionExit() {}
		virtual void OnCollisionExit2D() {}
		virtual void OnCollisionStay() {}
		virtual void OnCollisionStay2D() {}
		virtual void OnDestroy() {}
		virtual void OnDisable() {}
		virtual void OnEnable() {}
		virtual void OnTriggerEnter() {}
		virtual void OnTriggerEnter2D() {}
		virtual void OnTriggerExit() {}
		virtual void OnTriggerExit2D() {}
		virtual void OnTriggerStay() {}
		virtual void OnTriggerStay2D() {}
		virtual void Reset() {}
		virtual void Start() {}
		virtual void Update() {}
#pragma endregion

		bool enabled = true;
		bool isActiveAndEnabled();
		GameObject* gameObject = nullptr;
		std::string tag;
		Transform* transform();

		//CompareTag	


#pragma region Static
		static void Destroy();
		static void	DestroyImmediate();
		//static void	DontDestroyOnLoad();
		static void	FindAnyObjectByType();
		static void	FindFirstObjectByType();
		static void	FindObjectOfType();
		static void	FindObjectsByType();
		static void	FindObjectsOfType();
		static void	Instantiate();
#pragma endregion

		MonoBehaviour() = default;
		MonoBehaviour(const MonoBehaviour& obj) : Object(obj), enabled(obj.enabled) {}
		std::shared_ptr<MonoBehaviour> Clone() const { return std::shared_ptr<MonoBehaviour>(Clone_impl()); }

		bool operator!=(const MonoBehaviour&);
		bool operator==(const MonoBehaviour&);

	private:
		virtual MonoBehaviour* Clone_impl() const override { return new MonoBehaviour(*this); }
	};
}

