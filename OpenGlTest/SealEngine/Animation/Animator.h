#pragma once
#include <map>

#include "../MonoBehaviour.h"
#include "../SpriteRenderer.h"
#include "AnimatorController.h"

namespace SealEngine {
	class Animator : public MonoBehaviour {
	public:
		enum AnimatorUpdateMode { Normal, UnscaledTime };
		AnimatorUpdateMode updateMode = Normal;

		void SetAnimatorController(const AnimatorController* animatorController);

		bool GetBool(const std::string& name);
		float GetFloat(const std::string& name);
		int GetInteger(const std::string& name);

		void SetBool(const std::string& name, bool value);
		void SetFloat(const std::string& name, float value);
		void SetInteger(const std::string& name, int value);

		void Play(const std::string& name);

		const AnimatorController* animatorController = nullptr;
		SpriteRenderer* renderer = nullptr;

		Animator() = default;
		Animator(const AnimatorController* animatorController);
		Animator(const Animator& obj) : MonoBehaviour(obj) {
			SetAnimatorController(obj.animatorController);
		}

		void Awake() override;
		void Update() override;

	private:
		const AnimatorController::AnimationState* currentState = nullptr;
		int currentFrame = 0;
		float nextFrameTime = 0;
		float clipBeginTime = 0;


		void HandleStateEnter(const AnimatorController::AnimationState* state);
		void HandleStateExit(const AnimatorController::AnimationState::Transition& transition);

		std::map<std::string, int> intMap;
		std::map<std::string, bool> boolMap;
		std::map<std::string, float> floatMap;

		Animator* _Clone() const override { return new Animator(*this); }
	};
}

