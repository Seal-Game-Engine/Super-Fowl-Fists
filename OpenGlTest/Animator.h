#pragma once
#include "MonoBehaviour.h"
#include "AnimatorController.h"
#include "SpriteRenderer.h"
#include <map>

namespace SealEngine {
	class Animator : public MonoBehaviour {
	public:
		enum AnimatorUpdateMode { Normal, UnscaledTime };
		AnimatorUpdateMode updateMode;

		void SetAnimatorController(const AnimatorController* animatorController);

		bool GetBool(const std::string& name) const;
		float GetFloat(const std::string& name) const;
		int GetInteger(const std::string& name) const;

		void SetBool(const std::string& name, bool value);
		void SetFloat(const std::string& name, float value);
		void SetInteger(const std::string& name, int value);

		void Play(const std::string& name);

		void Update() override;
		SpriteRenderer* renderer = nullptr;

	private:
		const AnimatorController* animatorController = nullptr;
		const AnimatorController::AnimationState* currentState;
		int currentFrame = 0;
		float nextFrameTime = 0;
		float clipBeginTime = 0;


		void HandleStateEnter(const AnimatorController::AnimationState* state);
		void HandleStateExit(const AnimatorController::AnimationState::Transition& transition);

		std::map<std::string, int> intMap;
		std::map<std::string, bool> boolMap;
		std::map<std::string, float> floatMap;
	};
}

