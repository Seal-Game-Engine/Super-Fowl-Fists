#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class AssetManager {
public:
	static const Texture2D Hector_Run;
	static const AnimationClip Hector_Idle;
	static const AnimationClip Hector_IdleN;
	static const AnimatorController Hector_Controller;

	static const Texture2D Xwing;
	static const AnimationClip Xwing_Idle;
	static const AnimationClip Xwing_Left;
	static const AnimationClip Xwing_Right;
	static const AnimatorController Xwing_Controller;
	static const GameObject XwingObject;

	static const Texture2D Projectile_Blue;
	static const AnimationClip Projectile_Blue_Idle;
	static const AnimatorController Projectile_Blue_Controller;
	static const GameObject ProjectileObject_Blue;

	static const Texture2D GreenSlime;
	static const AnimationClip GreenSlime_Idle;
	static const AnimatorController GreenSlime_Controller;

	static const Texture2D Googleplex;

	static const Texture2D SpaceBackground;

	static const Texture2D Font;
};