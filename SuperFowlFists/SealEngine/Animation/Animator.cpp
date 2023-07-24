#include "Animator.h"
#include "../Clock.h"
#include "../GameObject.h"
#include <map>
using namespace SealEngine;

Animator::Animator(const AnimatorController* animatorController) :MonoBehaviour("Animator") {
	SetAnimatorController(animatorController);
}

void Animator::SetAnimatorController(const AnimatorController* animatorController) {
	this->animatorController = animatorController;
	if (!animatorController) return;

	HandleStateEnter(&animatorController->states[0]);
}

bool Animator::GetBool(const std::string& name) { return _boolMap[name]; }
float Animator::GetFloat(const std::string& name) { return _floatMap[name]; }
int Animator::GetInteger(const std::string& name) { return _intMap[name]; }

void Animator::SetBool(const std::string& name, bool value) { _boolMap[name] = value; }
void Animator::SetFloat(const std::string& name, float value) { _floatMap[name] = value; }
void Animator::SetInteger(const std::string& name, int value) { _intMap[name] = value; }

void Animator::Play(const std::string& name) {
	if (animatorController->map.count(name) == 0) return;
	HandleStateEnter(&animatorController->map.find(name)->second);
}


void Animator::Awake() { _renderer = gameObject->GetComponent<IRenderer>(); }

void Animator::Update() {
	if (!animatorController) return;
	if (!_renderer) _renderer = gameObject->GetComponent<IRenderer>();

	float clipElapsedTime = (Time::time() - _clipBeginTime) / _currentState->clip->length();

	for (auto& transition : _currentState->transitions) {
		if (Time::timeScale > 0 && (!transition.hasExitTime || transition.hasExitTime && clipElapsedTime >= transition.exitTime) && transition.condition(*this)) {
			HandleStateExit(transition);
			break;
		}
	}

	if (Time::time() >= _nextFrameTime) {
		if (++_currentFrame == _currentState->clip->frames.size()) _currentFrame = _currentState->clip->loopTime ? 0 : (int)_currentState->clip->frames.size() - 1;

		if (_renderer) _renderer->sprite = &_currentState->clip->frames[_currentFrame].sprite;
		_nextFrameTime = Time::time() + _currentState->clip->frames[_currentFrame].duration;
	}
}

void Animator::HandleStateEnter(const AnimatorController::AnimationState* state) {
	_currentState = state;
	_currentFrame = 0;
	_clipBeginTime = Time::time();

	if (_renderer) _renderer->sprite = &_currentState->clip->frames[_currentFrame].sprite;
	_nextFrameTime = Time::time() + _currentState->clip->frames[_currentFrame].duration;
}

void Animator::HandleStateExit(const AnimatorController::AnimationState::Transition& transition) {
	Play(transition.targetState);
}