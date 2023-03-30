#include "AssetManager.h"
using State = AnimatorController::AnimationState;

const Texture2D AssetManager::Hector_Run = Texture2D("Hector_Run.png", Texture2D::FilterMode::Nearest, 4, 3);

const AnimationClip AssetManager::Hector_Idle = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	{ Hector_Run[1], 0.05f },
	{ Hector_Run[5], 0.05f },
	{ Hector_Run[1], 0.05f },
	{ Hector_Run[9], 0.05f },
}, true);
const AnimationClip AssetManager::Hector_IdleN = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	{ Hector_Run[0], 0.05f },
	{ Hector_Run[4], 0.05f },
	{ Hector_Run[0], 0.05f },
	{ Hector_Run[8], 0.05f },
}, true);

const AnimatorController AssetManager::Hector_Controller = AnimatorController(std::vector<State>{
	State("Idle", &Hector_Idle, std::vector<State::Transition>{
		{.targetState = "IdleN", .condition = [](auto animator) { return animator.GetInteger("y") >= 0; } },
	}),
	State("IdleN", &Hector_IdleN, std::vector<State::Transition>{
		{.targetState = "Idle", .condition = [](auto animator) { return animator.GetInteger("y") < 0; } },
	}),
});

const Texture2D AssetManager::GreenSlime = Texture2D("GreenSlime.png", Texture2D::FilterMode::Nearest, 4, 2);
const AnimationClip AssetManager::GreenSlime_Idle = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	{ GreenSlime[1], 0.15f },
	{ GreenSlime[5], 0.15f },
}, true);
const AnimatorController AssetManager::GreenSlime_Controller = AnimatorController(std::vector<State>{
	State("Idle", &GreenSlime_Idle, std::vector<State::Transition>{
		//{.targetState = "Run", .hasExitTime = false, .condition = [&]() { return false; } },
	}),
});

const Texture2D AssetManager::Googleplex = Texture2D("Googleplex.jpg", Texture2D::FilterMode::Linear);