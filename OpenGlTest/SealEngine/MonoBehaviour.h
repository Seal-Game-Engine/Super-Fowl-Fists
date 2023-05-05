#pragma once
#include <string>
#include <list>
#include <functional>
#include "Object.h"
#include "Physics/Collision2D.h"
namespace SealEngine { 
	class Transform;
	class GameObject;
	class Collider2D;
}

namespace SealEngine {
	class MonoBehaviour : public Object {
	public:
#pragma region Messages
        virtual void Awake() {}
		virtual void Start() {}
		
		void RunCoroutines();
		virtual void Update() {}
		virtual void LateUpdate() {}

		//virtual void OnEnable() {}
		//virtual void OnDisable() {}
		virtual void OnDestroy() {}

		//virtual void FixedUpdate() {}
		virtual void OnCollisionEnter2D(Collision2D collision) {}
		virtual void OnCollisionStay2D(Collision2D collision) {}
		virtual void OnCollisionExit2D(Collision2D collision) {}
		virtual void OnTriggerEnter2D(Collider2D* collider) {}
		virtual void OnTriggerStay2D(Collider2D* collider) {}
		virtual void OnTriggerExit2D(Collider2D* collider) {}

		/*virtual void OnCollisionEnter() {}
		virtual void OnCollisionStay() {}
		virtual void OnCollisionExit() {}
		virtual void OnTriggerEnter() {}
		virtual void OnTriggerStay() {}
		virtual void OnTriggerExit() {}
		virtual void Reset() {}*/
#pragma endregion

		void Invoke(std::function<void()> action, float delayDuration);
		void InvokeRepeating(std::function<void()> action, float delayDuration, float repeatRate);
		void CancelInvoke();

		bool enabled = true;
		bool isActiveAndEnabled();
		GameObject* gameObject = nullptr;
		std::string tag;
		Transform* transform();

		//CompareTag	

		MonoBehaviour() = default;
		MonoBehaviour(const MonoBehaviour& obj) : Object(obj), enabled(obj.enabled) {}
		std::shared_ptr<MonoBehaviour> Clone() const { return std::shared_ptr<MonoBehaviour>(_Clone()); }

	private:
		std::list<std::pair<std::function<void()>, float>> _coroutines{};

		virtual MonoBehaviour* _Clone() const override { return new MonoBehaviour(*this); }
	};
}

