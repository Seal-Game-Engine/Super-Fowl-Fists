#include "AssetManager.h"
using State = AnimatorController::AnimationState;

const Texture2D AssetManager::Hector_Run = Texture2D("Assets/Hector_Run.png", Texture2D::FilterMode::Nearest, 4, 3);

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
		{"IdleN", false, 1, [](auto& animator) { return animator.GetInteger("y") >= 0; } },
	}),
	State("IdleN", &Hector_IdleN, std::vector<State::Transition>{
		{"Idle", false, 1, [](auto& animator) { return animator.GetInteger("y") < 0; } },
	}),
});

const Texture2D AssetManager::Xwing = Texture2D("Assets/X-wing.png", Texture2D::FilterMode::Nearest, 3, 2);
const AnimationClip AssetManager::Xwing_Idle = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	{ Xwing[0], 0.05f },
	{ Xwing[3], 0.05f },
}, true);
const AnimationClip AssetManager::Xwing_Left = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	{ Xwing[1], 0.05f },
	{ Xwing[4], 0.05f },
}, true);
const AnimationClip AssetManager::Xwing_Right = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	{ Xwing[2], 0.05f },
	{ Xwing[5], 0.05f },
}, true);
const AnimatorController AssetManager::Xwing_Controller = AnimatorController(std::vector<State>{
	State("Idle", &Xwing_Idle, std::vector<State::Transition>{
		{ "Left", false, 1, [](auto& animator) { return animator.GetInteger("x") < 0; } },
		{ "Right", false, 1, [](auto& animator) { return animator.GetInteger("x") > 0; } },
	}),
	State("Left", &Xwing_Left, std::vector<State::Transition>{
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") >= 0; } },
	}),
	State("Right", &Xwing_Right, std::vector<State::Transition>{
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") <= 0; } },
	}),
});;

const Texture2D AssetManager::Projectile_Blue = Texture2D("Assets/Projectile_Blue.png", Texture2D::FilterMode::Nearest, 3, 1);
const AnimationClip AssetManager::Projectile_Blue_Idle = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	{ Projectile_Blue[0], 0.1f },
	{ Projectile_Blue[1], 0.1f },
	{ Projectile_Blue[2], 0.1f },
}, true);;
const AnimatorController AssetManager::Projectile_Blue_Controller = AnimatorController(std::vector<State>{
	State("Idle", &Projectile_Blue_Idle),
});;

const Texture2D AssetManager::SpaceBackground = Texture2D("Assets/SpaceBackground.png", Texture2D::FilterMode::Nearest);

const Texture2D AssetManager::Font = Texture2D("Assets/font.png", Texture2D::FilterMode::Nearest, 16, 8);
const Texture2D AssetManager::GreenSlime = Texture2D("Assets/GreenSlime.png", Texture2D::FilterMode::Nearest, 4, 2);
const AnimationClip AssetManager::GreenSlime_Idle = AnimationClip(std::vector<AnimationClip::AnimationFrame>{
	//{ GreenSlime[1], 0.15f },
	//{ GreenSlime[5], 0.15f },
	{ Font[0], 1.0f},
	{ Font[16], 1.0f },
	{ Font[32], 1.0f },
	{ Font[48], 1.0f },
	{ Font[64], 1.0f },
	{ Font[80], 1.0f },
	{ Font[96], 1.0f },
	{ Font[112], 1.0f },
}, true);
const AnimatorController AssetManager::GreenSlime_Controller = AnimatorController(std::vector<State>{
	State("Idle", &GreenSlime_Idle, std::vector<State::Transition>{
		//{.targetState = "Run", .hasExitTime = false, .condition = [&]() { return false; } },
	}),
});

const Texture2D AssetManager::Googleplex = Texture2D("Assets/Googleplex.png", Texture2D::FilterMode::Linear);
