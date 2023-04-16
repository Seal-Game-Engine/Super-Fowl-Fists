#include "AssetManager.h"
using State = AnimatorController::AnimationState;

#include "Player.h"

const Texture2D AssetManager::Hector_Run = Texture2D("Assets/Hector_Run.png", Texture2D::FilterMode::Nearest, 4, 3);

const AnimationClip AssetManager::Hector_Idle = AnimationClip({
	{ Hector_Run[1], 0.05f },
	{ Hector_Run[5], 0.05f },
	{ Hector_Run[1], 0.05f },
	{ Hector_Run[9], 0.05f },
}, true);
const AnimationClip AssetManager::Hector_IdleN = AnimationClip({
	{ Hector_Run[0], 0.05f },
	{ Hector_Run[4], 0.05f },
	{ Hector_Run[0], 0.05f },
	{ Hector_Run[8], 0.05f },
}, true);

const AnimatorController AssetManager::Hector_Controller = AnimatorController({
	State("Idle", &Hector_Idle, {
		{"IdleN", false, 1, [](auto& animator) { return animator.GetInteger("y") >= 0; } },
	}),
	State("IdleN", &Hector_IdleN, {
		{"Idle", false, 1, [](auto& animator) { return animator.GetInteger("y") < 0; } },
	}),
});

const Texture2D AssetManager::Xwing = Texture2D("Assets/X-wing.png", Texture2D::FilterMode::Nearest, 3, 2);
const AnimationClip AssetManager::Xwing_Idle = AnimationClip({
	{ Xwing[0], 0.05f },
	{ Xwing[3], 0.05f },
}, true);
const AnimationClip AssetManager::Xwing_Left = AnimationClip({
	{ Xwing[1], 0.05f },
	{ Xwing[4], 0.05f },
}, true);
const AnimationClip AssetManager::Xwing_Right = AnimationClip({
	{ Xwing[2], 0.05f },
	{ Xwing[5], 0.05f },
}, true);
const AnimatorController AssetManager::Xwing_Controller = AnimatorController({
	State("Idle", &Xwing_Idle, {
		{ "Left", false, 1, [](auto& animator) { return animator.GetInteger("x") < 0; } },
		{ "Right", false, 1, [](auto& animator) { return animator.GetInteger("x") > 0; } },
	}),
	State("Left", &Xwing_Left, {
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") >= 0; } },
	}),
	State("Right", &Xwing_Right, {
		{ "Idle", false, 1, [](auto& animator) { return animator.GetInteger("x") <= 0; } },
	}),
});;
const GameObject AssetManager::XwingObject = GameObject(
	"Player",
	/*std::vector<MonoBehaviour>{
	SpriteRenderer(&AssetManager::Xwing[0], false, false),
		Animator(&AssetManager::Xwing_Controller),
		Player(),*/
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<SpriteRenderer>(&AssetManager::Xwing[0], false, false),
			std::make_shared<Animator>(&AssetManager::Xwing_Controller),
			std::make_shared<Player>(),
});

const Texture2D AssetManager::Projectile_Blue = Texture2D("Assets/Projectile_Blue.png", Texture2D::FilterMode::Nearest, 3, 1);
const AnimationClip AssetManager::Projectile_Blue_Idle = AnimationClip({
	{ Projectile_Blue[0], 0.1f },
	{ Projectile_Blue[1], 0.1f },
	{ Projectile_Blue[2], 0.1f },
}, true);;
const AnimatorController AssetManager::Projectile_Blue_Controller = AnimatorController({
	State("Idle", &Projectile_Blue_Idle),
});;

const Texture2D AssetManager::SpaceBackground = Texture2D("Assets/SpaceBackground.png", Texture2D::FilterMode::Nearest);

const Texture2D AssetManager::Font = Texture2D("Assets/font.png", Texture2D::FilterMode::Nearest, 16, 8);
const Texture2D AssetManager::GreenSlime = Texture2D("Assets/GreenSlime.png", Texture2D::FilterMode::Nearest, 4, 2);
const AnimationClip AssetManager::GreenSlime_Idle = AnimationClip({
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
const AnimatorController AssetManager::GreenSlime_Controller = AnimatorController({
	State("Idle", &GreenSlime_Idle, {
		//{.targetState = "Run", .hasExitTime = false, .condition = [&]() { return false; } },
	}),
});

const Texture2D AssetManager::Googleplex = Texture2D("Assets/Googleplex.png", Texture2D::FilterMode::Linear);
