#include "Animator.h"
#include "Time2.h"
#include "GameObject.h"
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

Animator::Animator(const AnimatorController* animatorController) {
	SetAnimatorController(animatorController);
}

std::shared_ptr<Animator> SealEngine::Animator::Clone() const { return std::shared_ptr<Animator>(Clone_impl()); }

void Animator::Awake(){
	renderer = gameObject->GetComponent<SpriteRenderer>();
}

void Animator::Update() {
	if (!animatorController) return;

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
	HandleStateEnter(&animatorController->map.find(transition.targetState)->second);
}

Animator* SealEngine::Animator::Clone_impl() const { return new Animator(*this); }
