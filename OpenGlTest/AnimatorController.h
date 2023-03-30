#pragma once
#include "Object.h"
#include <map>
#include <functional>
#include "AnimationClip.h"
namespace SealEngine { class Animator; }

namespace SealEngine {
	class AnimatorController : public Object {
	public:
		class AnimationState {
		public:
			struct Transition {
				const std::string_view targetState;
				bool hasExitTime = false;
				float exitTime = 1;
				std::function<bool(const Animator&)> condition = [](const Animator&) { return true; };
			};

			std::string_view name;
			const AnimationClip* clip;
			std::vector<Transition> transitions;


			AnimationState(const std::string_view name, const AnimationClip* clip, std::vector<Transition> transitions = std::vector<Transition>{});
		};

		class AnimationBlendState : public AnimationState {
		public:
			std::vector<std::tuple<const AnimationClip*, Vector2>> clips;

			AnimationBlendState(const std::string_view name, std::vector<std::tuple<const AnimationClip*, Vector2>> clips, std::vector<Transition> transitions = std::vector<Transition>{});
		};

		std::vector<AnimationState> states;

		AnimatorController(std::vector<AnimationState> states);

		std::map<std::string_view, AnimationState> map;

		

	private:
	};
}