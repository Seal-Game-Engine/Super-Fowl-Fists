#include "AnimatorController.h"
using namespace SealEngine;

AnimatorController::AnimationState::AnimationState(const std::string& name, const AnimationClip* clip, std::vector<Transition> transitions)
	: name(name), clip(clip), transitions(transitions) {}

AnimatorController::AnimationBlendState::AnimationBlendState(const std::string& name, std::vector<std::tuple<const AnimationClip*, Vector2>> clips, std::vector<Transition> transitions)
	: clips(clips), AnimationState(name, nullptr, transitions) {}

AnimatorController::AnimatorController(std::vector<AnimationState> states) : states(states) {
	for (auto& state : states) map.emplace(state.name, state);
}