#include "GlobalGameScene.h"
#include "EventManagers/TutorialEventManager.h"
#include "EventManagers/GameEventManager.h" 
#include "Prefab.h"
#include "Parallax.h"
using State = AnimatorController::AnimationState;

#pragma region Shared Assets
const Texture2D Font_Texture = Texture2D("Assets/Font.png", Texture2D::FilterMode::Nearest, 16, 8, 128);
const GameObject MainCamera = GameObject(
	"Main Camera", "MainCamera",
	std::make_shared<Camera>(Camera::Projection::Orthographic, 2.5f)
);

#pragma region GameEventManager
const GameObject GameEventManagerObject = GameObject(		//Game Interactions (ie: pause)
	"GameEventManager", "Untagged",
	std::make_shared<Image>(&Prefab::PauseScreen[0]),
	//std::make_shared<Image>(&PauseMessage[0]),
	std::make_shared<GameEventManager>(),
	std::make_shared<AudioSource>()
);

#pragma endregion
#pragma region Environment
const GameObject Ground_Object = GameObject(
	"Ground", "Ground",
	std::make_shared<BoxCollider2D>(Vector2(1600, 1))
);
const GameObject Wall_Object = GameObject(
	"Wall", "Untagged",
	std::make_shared<BoxCollider2D>(Vector2(1, 1600))
);
const Texture2D Lv0_Platform_Texture = Texture2D("Assets/Game_Lv0_Platform.png", Texture2D::FilterMode::Nearest);
const GameObject Lv0_Platform_Object = GameObject(
	"Platform", "Ground",
	std::make_shared<BoxCollider2D>(Vector2(1, 0.1)),
	std::make_shared<SpriteRenderer>(&Lv0_Platform_Texture[0])
);
#pragma endregion

#pragma region UI
#pragma region TikeMyson UI
const Texture2D TikeMyson_UI_Texture = Texture2D("Assets/TikeMyson_UI.png", Texture2D::FilterMode::Nearest, 4, 1, 40);
const AnimationClip TikeMyson_UI_Texture_Clip = AnimationClip({
	{TikeMyson_UI_Texture[0], 0.1f},
	{TikeMyson_UI_Texture[1], 0.1f},
	{TikeMyson_UI_Texture[2], 0.1f},
	{TikeMyson_UI_Texture[3], 0.1f},
	}, true);
const AnimatorController TikeMyson_UI_Controller = AnimatorController({
	State("Mini_Idle", &TikeMyson_UI_Texture_Clip, {}) });
const GameObject TikeMyson_UI_Object = GameObject(
	"Background", "TikeMysonUi",
	std::make_shared<Image>(&TikeMyson_UI_Texture[0]),
	std::make_shared<Animator>(&TikeMyson_UI_Controller)
);
const GameObject UI_Text_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<Text>("100", &Font_Texture)
);

#pragma endregion
#pragma region Chicken UI
const Texture2D Chicken_UI_Texture = Texture2D("Assets/Chicken_UI.png", Texture2D::FilterMode::Nearest, 4, 1, 40);
const AnimationClip Chicken_UI_Texture_Clip = AnimationClip({
	{Chicken_UI_Texture[0], 0.1f},
	{Chicken_UI_Texture[1], 0.1f},
	{Chicken_UI_Texture[2], 0.1f},
	{Chicken_UI_Texture[3], 0.1f},
	}, true);
const AnimatorController Chicken_UI_Controller = AnimatorController({
	State("Mini_Idle", &Chicken_UI_Texture_Clip, {}) });
const GameObject Chicken_UI_Object = GameObject(
	"Background", "ChickenUi",
	std::make_shared<Image>(&Chicken_UI_Texture[0]),
	std::make_shared<Animator>(&Chicken_UI_Controller)
);
#pragma endregion
#pragma endregion
#pragma endregion Shared Assets

#pragma region TutorialScene 

#pragma region TutorialScene Assets
const Texture2D TutorialScene_Texture = Texture2D("Assets/Game_Tutorial.png", Texture2D::FilterMode::Nearest);
//const Texture2D TutorialText = Texture2D("Assets/TutorialText.png", Texture2D::FilterMode::Nearest);
const Texture2D TutorialScene_Background_Texture = Texture2D("Assets/Game_Tutorial_Background.png", Texture2D::FilterMode::Nearest, 5);
const AnimationClip TutorialScene_Background_Idle = AnimationClip({
	{ TutorialScene_Background_Texture[0], 0.1f },
	{ TutorialScene_Background_Texture[1], 0.1f },
	{ TutorialScene_Background_Texture[2], 0.1f },
	{ TutorialScene_Background_Texture[3], 0.1f },
	{ TutorialScene_Background_Texture[4], 0.1f },
	}, true);
const AnimatorController TutorialScene_Background_Controller = AnimatorController({
	State("Idle", &TutorialScene_Background_Idle, {}) });

#pragma region TutorialBoxes
const Texture2D TutorialScene_Help_Walk_Texture = Texture2D("Assets/TutorialText_Walk.png", Texture2D::FilterMode::Nearest, 5);
const AnimationClip TutorialScene_Help_Walk_Idle = AnimationClip({
	{ TutorialScene_Help_Walk_Texture[0], 0.1f },
	{ TutorialScene_Help_Walk_Texture[1], 0.1f },
	{ TutorialScene_Help_Walk_Texture[2], 0.1f },
	{ TutorialScene_Help_Walk_Texture[3], 0.1f },
	}, true);
const AnimatorController TutorialScene_Help_Walk_Controller = AnimatorController({
	State("Idle", &TutorialScene_Help_Walk_Idle, {}) });
const GameObject TutorialScene_Help_Walk_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<SpriteRenderer>(&TutorialScene_Help_Walk_Texture[0]),
	std::make_shared<Animator>(&TutorialScene_Help_Walk_Controller)
);

const Texture2D TutorialScene_Help_Fight_Texture = Texture2D("Assets/TutorialText_Fight.png", Texture2D::FilterMode::Nearest, 4);
const AnimationClip TutorialScene_Help_Fight_Idle = AnimationClip({
	{ TutorialScene_Help_Fight_Texture[0], 0.1f },
	{ TutorialScene_Help_Fight_Texture[1], 0.1f },
	{ TutorialScene_Help_Fight_Texture[2], 0.1f },
	{ TutorialScene_Help_Fight_Texture[3], 0.1f },
	}, true);
const AnimatorController TutorialScene_Help_Fight_Controller = AnimatorController({
	State("Idle", &TutorialScene_Help_Fight_Idle, {}) });
const GameObject TutorialScene_Help_Fight_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<SpriteRenderer>(&TutorialScene_Help_Fight_Texture[0]),
	std::make_shared<Animator>(&TutorialScene_Help_Fight_Controller)
);

const Texture2D TutorialScene_Help_Buff_Texture = Texture2D("Assets/TutorialText_Buff.png", Texture2D::FilterMode::Nearest, 4);
const AnimationClip TutorialScene_Help_Buff_Idle = AnimationClip({
	{ TutorialScene_Help_Buff_Texture[0], 0.1f },
	{ TutorialScene_Help_Buff_Texture[1], 0.1f },
	{ TutorialScene_Help_Buff_Texture[2], 0.1f },
	{ TutorialScene_Help_Buff_Texture[3], 0.1f },
	}, true);
const AnimatorController TutorialScene_Help_Buff_Controller = AnimatorController({
	State("Idle", &TutorialScene_Help_Buff_Idle, {}) });
const GameObject TutorialScene_Help_Buff_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<SpriteRenderer>(&TutorialScene_Help_Buff_Texture[0]),
	std::make_shared<Animator>(&TutorialScene_Help_Buff_Controller)
);

const Texture2D TutorialScene_Help_Ult_Texture = Texture2D("Assets/TutorialText_Ult.png", Texture2D::FilterMode::Nearest, 4);
const AnimationClip TutorialScene_Help_Ult_Idle = AnimationClip({
	{ TutorialScene_Help_Ult_Texture[0], 0.1f },
	{ TutorialScene_Help_Ult_Texture[1], 0.1f },
	{ TutorialScene_Help_Ult_Texture[2], 0.1f },
	{ TutorialScene_Help_Ult_Texture[3], 0.1f },
	}, true);
const AnimatorController TutorialScene_Help_Ult_Controller = AnimatorController({
	State("Idle", &TutorialScene_Help_Ult_Idle, {}) });
const GameObject TutorialScene_Help_Ult_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<SpriteRenderer>(&TutorialScene_Help_Ult_Texture[0]),
	std::make_shared<Animator>(&TutorialScene_Help_Ult_Controller)
);
#pragma endregion
const GameObject TutorialScene_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<SpriteRenderer>(&TutorialScene_Background_Texture[0]),
	std::make_shared<Animator>(&TutorialScene_Background_Controller),
	std::make_shared<SpriteRenderer>(&TutorialScene_Texture[0])
);
//const GameObject TutorialUIObject = GameObject(
//	"TutorialText", "Untagged",
//	std::vector<std::shared_ptr<MonoBehaviour>>{
//	std::make_shared<Image>(&TutorialText[0]),
//	std::make_shared<SpriteRenderer>(&TutorialScene_Texture[0])
//});
#pragma endregion

#pragma region TutorialScene Properties
Scene GlobalGameScene::TutorialScene = Scene({
	//{&Prefab::Students_Object, Transform(Vector2(0,0))},
	{&TutorialScene_Object, Transform(Vector2(14,0))},
	{&TutorialScene_Help_Walk_Object, Transform(Vector2(0,-1))},
	{&TutorialScene_Help_Fight_Object, Transform(Vector2(7,-1))},
	{&TutorialScene_Help_Buff_Object, Transform(Vector2(14,-1))},
	{&TutorialScene_Help_Ult_Object, Transform(Vector2(21,-1))},
	{&Wall_Object, Transform(Vector2(-2.8,0))},
	{&Wall_Object, Transform(Vector2(28,0))},
	{&GameEventManagerObject, Transform()},
	{&Ground_Object, Transform(Vector2(0, -4))},
	{&MainCamera, Transform()},

	{ &TikeMyson_UI_Object, Transform(Vector2(-2.5, -1.9)) },
	{ &Chicken_UI_Object, Transform(Vector2(2.5,-1.9)) },
	{ &UI_Text_Object, Transform(Vector2(-1.7,-1.64)) },
	{ &UI_Text_Object, Transform(Vector2(-1.7,-2.08)) },
	{ &UI_Text_Object, Transform(Vector2(3.3,-1.64)) },
	{ &UI_Text_Object, Transform(Vector2(3.3,-2.08)) },

	});
#pragma endregion

#pragma endregion

#pragma region Lv0Scene

#pragma region Lv0Scene Assets
const Texture2D Lv0Scene_Texture = Texture2D("Assets/Game_Lv0.png", Texture2D::FilterMode::Nearest);
//const Texture2D Lv0Scene_Texture = Texture2D("Assets/Game_Lv0.png", Texture2D::FilterMode::Nearest);
const Texture2D Lv0Scene_Background_Texture = Texture2D("Assets/Game_Lv0_Background.png", Texture2D::FilterMode::Nearest, 3);
const AnimationClip Lv0Scene_Background_Idle = AnimationClip({
	{ Lv0Scene_Background_Texture[0], 0.1f },
	{ Lv0Scene_Background_Texture[1], 0.1f },
	{ Lv0Scene_Background_Texture[2], 0.1f },
	}, true);
const AnimatorController Lv0Scene_Background_Controller = AnimatorController({
	State("Idle", &Lv0Scene_Background_Idle, {}) });

const GameObject Lv0Scene_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<SpriteRenderer>(&Lv0Scene_Background_Texture[0]),
	std::make_shared<Animator>(&Lv0Scene_Background_Controller),
	std::make_shared<SpriteRenderer>(&Lv0Scene_Texture[0])
);
#pragma endregion

#pragma region Lv0Scene Properties
Scene GlobalGameScene::Lv0Scene = Scene({
{&Lv0Scene_Object, Transform()},
{&GameEventManagerObject, Transform()},
{&Ground_Object, Transform(Vector2(0, -2.3))},
{&Lv0_Platform_Object, Transform(Vector2(0,-0.5f))},
{&Wall_Object, Transform(Vector2(-7.5,0))},
{&Wall_Object, Transform(Vector2(7.5,0))},

{&TikeMyson_UI_Object, Transform(Vector2(-2.5,-1.9))},
{&Chicken_UI_Object, Transform(Vector2(2.5,-1.9))},
{&UI_Text_Object, Transform(Vector2(-1.7,-1.64))},
{&UI_Text_Object, Transform(Vector2(-1.7,-2.08))},
{&UI_Text_Object, Transform(Vector2(3.3,-1.64))},
{&UI_Text_Object, Transform(Vector2(3.3,-2.08))},

{&MainCamera, Transform()},
	});
#pragma endregion

#pragma endregion

#pragma region Lv1Scene

#pragma region Lv1Scene Assets
const Texture2D Lv1Scene_Texture = Texture2D("Assets/Game_Lv1.png", Texture2D::FilterMode::Nearest, 2, 1);
//const Texture2D Lv1Scene_Texture = Texture2D("Assets/Game_Lv1.png", Texture2D::FilterMode::Linear);
const AnimationClip Lv1Scene_Idle = AnimationClip({
{ Lv1Scene_Texture[0], 0.1f },
{ Lv1Scene_Texture[1], 0.1f },
	}, true);
const AnimatorController Lv1Scene_Background_Controller = AnimatorController({
	State("Idle", &Lv1Scene_Idle, {}) });
const GameObject Lv1Scene_Object = GameObject(
	"Background", "Untagged",
	std::make_shared<SpriteRenderer>(&Lv1Scene_Texture[0]),
	std::make_shared<Animator>(&Lv1Scene_Background_Controller)
	//std::make_shared<Parallax>(&Lv1Scene_Texture[0], Vector2::left(), 0.1f),
);

#pragma endregion

#pragma region Lv1Scene Properties
Scene GlobalGameScene::Lv1Scene = Scene({
	{ &Lv1Scene_Object, Transform() },
	{ &GameEventManagerObject, Transform() },
	{ &Ground_Object, Transform(Vector2(0, -2.3)) },
	{ &MainCamera, Transform() },

	{ &TikeMyson_UI_Object, Transform(Vector2(-2.5, -1.9)) },
	{ &Chicken_UI_Object, Transform(Vector2(2.5,-1.9)) },
	{ &UI_Text_Object, Transform(Vector2(-1.7,-1.64)) },
	{ &UI_Text_Object, Transform(Vector2(-1.7,-2.08)) },
	{ &UI_Text_Object, Transform(Vector2(3.3,-1.64)) },
	{ &UI_Text_Object, Transform(Vector2(3.3,-2.08)) }
	});
#pragma endregion

#pragma endregion