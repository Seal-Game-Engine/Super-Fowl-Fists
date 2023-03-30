#include "Animator.h"
#include "Time.h"
#include <map>
using namespace SealEngine;



void Animator::SetAnimatorController(const AnimatorController* animatorController) {
	this->animatorController = animatorController;
	if (!animatorController) return;

	HandleStateEnter(&animatorController->states[0]);
}

bool Animator::GetBool(const std::string& name) const { return boolMap.at(name); }
float Animator::GetFloat(const std::string& name) const { return floatMap.find(name)->second; }
int Animator::GetInteger(const std::string& name) const { return intMap.find(name)->second; }

void Animator::SetBool(const std::string& name, bool value) {
	if (!boolMap.count(name)) intMap.insert({ name, false });
	boolMap.find(name)->second = value;
}
void Animator::SetFloat(const std::string& name, float value) {
	if (!floatMap.count(name)) intMap.insert({ name, 0 });
	floatMap.find(name)->second = value;
}
void Animator::SetInteger(const std::string& name, int value) {
	if (!intMap.count(name)) intMap.insert({ name, 0 });
	intMap.find(name)->second = value;
}

void Animator::Update() {
	if (!animatorController) return;

	float clipElapsedTime = (Time::time() - clipBeginTime) / currentState->clip->length();

	for (auto& transition : currentState->transitions) {
		if ((!transition.hasExitTime || transition.hasExitTime && clipElapsedTime >= transition.exitTime) && transition.condition(*this)) {
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
	HandleStateEnter(&animatorController->map.find(transition.targetState)->second);
}
