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

		bool GetBool(const std::string_view name) const;
		float GetFloat(const std::string_view name) const;
		int GetInteger(const std::string_view name) const;

		void SetBool(const std::string_view name, bool value);
		void SetFloat(const std::string_view name, float value);
		void SetInteger(const std::string_view name, int value);

		void Play(const std::string_view name);

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

		std::map<std::string_view, int> intMap;
		std::map<std::string_view, bool> boolMap;
		std::map<std::string_view, float> floatMap;
	};
}

