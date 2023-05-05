#pragma once
#include <map>
#include <functional>

#include "../Object.h"
#include "AnimationClip.h"
namespace SealEngine { class Animator; }

namespace SealEngine {
	class AnimatorController : public Object {
	public:
		class AnimationState {
		public:
			struct Transition {
				const std::string targetState;
				bool hasExitTime = false;
				float exitTime = 1;
				std::function<bool(Animator&)> condition = [](const Animator&) { return true; };
			};

			const std::string& name;
			const AnimationClip* clip;
			std::vector<Transition> transitions{};


			AnimationState(const std::string& name, const AnimationClip* clip, std::vector<Transition> transitions = std::vector<Transition>{});
		};

		class AnimationBlendState : public AnimationState {
		public:
			std::vector<std::tuple<const AnimationClip*, Vector2>> clips{};

			AnimationBlendState(const std::string& name, std::vector<std::tuple<const AnimationClip*, Vector2>> clips, std::vector<Transition> transitions = std::vector<Transition>{});
		};

		std::vector<AnimationState> states{};

		AnimatorController(std::vector<AnimationState> states);

		std::map<std::string, AnimationState> map;
	};
}
