#pragma once
#include <map>

#include "../MonoBehaviour.h"
#include "../IRenderer.h"
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

		Animator(const AnimatorController* animatorController = nullptr);
		Animator(const Animator& obj) : MonoBehaviour(obj) {
			SetAnimatorController(obj.animatorController);
		}

		void Awake() override;
		void Update() override;

	private:
		const AnimatorController::AnimationState* _currentState = nullptr;
		IRenderer* _renderer = nullptr;
		int _currentFrame = 0;
		float _nextFrameTime = 0;
		float _clipBeginTime = 0;

		void HandleStateEnter(const AnimatorController::AnimationState* state);
		void HandleStateExit(const AnimatorController::AnimationState::Transition& transition);

		std::map<std::string, int> _intMap;
		std::map<std::string, bool> _boolMap;
		std::map<std::string, float> _floatMap;

		Animator* _Clone() const override { return new Animator(*this); }
	};
}

