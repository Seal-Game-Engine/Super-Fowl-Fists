#include "Animator.h"
#include "../Clock.h"
#include "../GameObject.h"
#include <map>
using namespace SealEngine;



void Animator::SetAnimatorController(const AnimatorController* animatorController) {
	this->animatorController = animatorController;
	if (!animatorController) return;

	HandleStateEnter(&animatorController->states[0]);
}

bool Animator::GetBool(const std::string& name) { return boolMap[name]; }
float Animator::GetFloat(const std::string& name) { return floatMap[name]; }
int Animator::GetInteger(const std::string& name) { return intMap[name]; }

void Animator::SetBool(const std::string& name, bool value) { boolMap[name] = value; }
void Animator::SetFloat(const std::string& name, float value) { floatMap[name] = value; }
void Animator::SetInteger(const std::string& name, int value) { intMap[name] = value; }

void Animator::Play(const std::string& name) {
	HandleStateEnter(&animatorController->map.find(name)->second);
}

Animator::Animator(const AnimatorController* animatorController) {
	SetAnimatorController(animatorController);
}

void Animator::Awake() { renderer = gameObject->GetComponent<SpriteRenderer>(); }

void Animator::Update() {
	if (!animatorController) return;
	if (!renderer)renderer = gameObject->GetComponent<SpriteRenderer>();

	float clipElapsedTime = (Time::time() - clipBeginTime) / currentState->clip->length();

	for (auto& transition : currentState->transitions) {
		if (Time::timeScale > 0 && (!transition.hasExitTime || transition.hasExitTime && clipElapsedTime >= transition.exitTime) && transition.condition(*this)) {
			HandleStateExit(transition);
			break;
		}
	}

	if (Time::time() >= nextFrameTime) {
		if (++currentFrame == currentState->clip->frames.size()) currentFrame = currentState->clip->loopTime ? 0 : (int)currentState->clip->frames.size() - 1;

		if (renderer) renderer->sprite = &currentState->clip->frames[currentFrame].sprite;
		nextFrameTime = Time::time() + currentState->clip->frames[currentFrame].duration;
	}
}

void Animator::HandleStateEnter(const AnimatorController::AnimationState* state) {
	currentState = state;
	currentFrame = 0;
	clipBeginTime = Time::time();

	if (renderer) renderer->sprite = &currentState->clip->frames[currentFrame].sprite;
	nextFrameTime = Time::time() + currentState->clip->frames[currentFrame].duration;
}

void Animator::HandleStateExit(const AnimatorController::AnimationState::Transition& transition) {
	Play(transition.targetState);
}