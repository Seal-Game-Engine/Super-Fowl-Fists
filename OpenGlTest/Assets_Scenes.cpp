#include "AssetManager.h"
#include "Assets_Scenes.h"
#include "Parallax.h"
#include "GameEventManager.h"
#include "MenuEventManager.h"
#include "LandingEventManager.h"
using State = AnimatorController::AnimationState;

#pragma region LandingScene

#pragma region LandingScene Assets
const Texture2D LandingScene_Parallax_Texture = Texture2D("Assets/BlocksParallax.png", Texture2D::FilterMode::Nearest);
const Texture2D LandingScene_Title_Texture = Texture2D("Assets/SuperFowlFists.png", Texture2D::FilterMode::Nearest, 2, 1, 128);

const AnimationClip Title_Idle_Clip = AnimationClip({
	{ LandingScene_Title_Texture[0], 0.1f },
	{ LandingScene_Title_Texture[1], 0.1f },
	}, true);
const AnimatorController Title_Controller = AnimatorController({
	State("Idle", &Title_Idle_Clip),
	});

const GameObject TitleObject = GameObject(
	"Title", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Parallax>(&LandingScene_Parallax_Texture[0], Vector2::left(), 0.01),
		std::make_shared<Image>(&LandingScene_Title_Texture[0]),
		std::make_shared<Animator>(&Title_Controller),
});
const GameObject LandingEventManagerObject = GameObject(
	"LandingEventManager", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<LandingEventManager>(),
});
#pragma endregion

#pragma region LandingSceneProperties
Scene Assets_Scenes::LandingScene = Scene({
	#pragma region Ui
	{&TitleObject, Transform()},
	{&LandingEventManagerObject, Transform()},
	#pragma endregion
	{&AssetManager::MainCamera, Transform()},
	});
#pragma endregion

#pragma endregion

#pragma region MenuScene
//const Texture2D MenuText = Texture2D("Assets/MenuText.png", Texture2D::FilterMode::Nearest);
const Texture2D Menu_Image_Texture = Texture2D("Assets/Menu.png", Texture2D::FilterMode::Nearest, 2);
#pragma region Button_1P
const Texture2D Button_1P_Texture = Texture2D("Assets/Button_1Player.png", Texture2D::FilterMode::Nearest, 4);

const AnimationClip Button_1P_Deselected_Clip = AnimationClip({
	{ Button_1P_Texture[0], 0.1f },
	{ Button_1P_Texture[1], 0.1f },
	}, true);
const AnimationClip Button_1P_Selected_Clip = AnimationClip({
	{ Button_1P_Texture[2], 0.1f },
	{ Button_1P_Texture[3], 0.1f },
	}, true);

const AnimatorController Button_1P_Controller = AnimatorController({
	State("Deselected", &Button_1P_Deselected_Clip, {
		{ "Selected", false, 1, [](auto& animator) { return animator.GetBool("selected"); }},
	}),
	State("Selected", &Button_1P_Selected_Clip, {
		{ "Deselected", true, 1, [](auto& animator) { return !animator.GetBool("selected"); }},
	}),
	});

const GameObject Button_1P_Object = GameObject(
	"MenuText", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&Button_1P_Texture[0]),
		std::make_shared<Animator>(&Button_1P_Controller),
		std::make_shared<Button>(
			[](auto) { SceneManager::LoadScene(3); },
			[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", true); },
			[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", false); }
		),
});
#pragma endregion
#pragma region Button_2P
const Texture2D Button_2P_Texture = Texture2D("Assets/Button_2Player.png", Texture2D::FilterMode::Nearest, 4);

const AnimationClip Button_2P_Deselected_Clip = AnimationClip({
{ Button_2P_Texture[0], 0.1f },
{ Button_2P_Texture[1], 0.1f },
	}, true);
const AnimationClip Button_2P_Selected_Clip = AnimationClip({
	{ Button_2P_Texture[2], 0.1f },
	{ Button_2P_Texture[3], 0.1f },
	}, true);

const AnimatorController Button_2P_Controller = AnimatorController({
	State("Deselected", &Button_2P_Deselected_Clip, {
		{ "Selected", false, 1, [](auto& animator) { return animator.GetBool("selected"); }},
	}),
	State("Selected", &Button_2P_Selected_Clip, {
		{ "Deselected", true, 1, [](auto& animator) { return !animator.GetBool("selected"); }},
	}),
	});

const GameObject Button_2P_Object = GameObject(
	"MenuText", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&Button_2P_Texture[0]),
		std::make_shared<Animator>(&Button_2P_Controller),
		std::make_shared<Button>(
			[](auto) { SceneManager::LoadScene(3); },
			[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", true); },
			[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", false); }
		),
});
#pragma endregion

#pragma region Button_Help
const Texture2D Button_Help_Texture = Texture2D("Assets/Button_Help.png", Texture2D::FilterMode::Nearest, 4);

const AnimationClip Button_Help_Deselected_Clip = AnimationClip({
{ Button_Help_Texture[0], 0.1f },
{ Button_Help_Texture[1], 0.1f },
	}, true);
const AnimationClip Button_Help_Selected_Clip = AnimationClip({
	{ Button_Help_Texture[2], 0.1f },
	{ Button_Help_Texture[3], 0.1f },
	}, true);

const AnimatorController Button_Help_Controller = AnimatorController({
	State("Deselected", &Button_Help_Deselected_Clip, {
		{ "Selected", false, 1, [](auto& animator) { return animator.GetBool("selected"); }},
	}),
	State("Selected", &Button_Help_Selected_Clip, {
		{ "Deselected", true, 1, [](auto& animator) { return !animator.GetBool("selected"); }},
	}),
	});

const GameObject Button_Help_Object = GameObject(
	"MenuText", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Image>(&Button_Help_Texture[0]),
		std::make_shared<Animator>(&Button_Help_Controller),
		std::make_shared<Button>(
			[](auto) { SceneManager::LoadScene(3); },
			[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", true); },
			[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", false); }
		),
});
#pragma endregion
#pragma region Button_Credits
const Texture2D Button_Credits_Texture = Texture2D("Assets/Button_Credit.png", Texture2D::FilterMode::Nearest, 4);

const AnimationClip Button_Credits_Deselected_Clip = AnimationClip({
	{ Button_Credits_Texture[0], 0.1f },
	{ Button_Credits_Texture[1], 0.1f },
	}, true);
const AnimationClip Button_Credits_Selected_Clip = AnimationClip({
	{ Button_Credits_Texture[2], 0.1f },
	{ Button_Credits_Texture[3], 0.1f },
	}, true);

	const AnimatorController Button_Credits_Controller = AnimatorController({
		State("Deselected", &Button_Credits_Deselected_Clip, {
			{ "Selected", false, 1, [](auto& animator) { return animator.GetBool("selected"); }},
		}),
		State("Selected", &Button_Credits_Selected_Clip, {
			{ "Deselected", true, 1, [](auto& animator) { return !animator.GetBool("selected"); }},
		}),
		});

	const GameObject Button_Credits_Object = GameObject(
		"MenuText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&Button_Credits_Texture[0]),
			std::make_shared<Animator>(&Button_Credits_Controller),
			std::make_shared<Button>(
				[](auto) { SceneManager::LoadScene(3); },
				[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", true); },
				[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", false); }
			),
	});
	#pragma endregion
	#pragma region Button_Quit
	const Texture2D Button_Quit_Texture = Texture2D("Assets/Button_Quit.png", Texture2D::FilterMode::Nearest, 4);
	const AnimationClip Button_Quit_Deselected_Clip = AnimationClip({
	{ Button_Quit_Texture[0], 0.1f },
	{ Button_Quit_Texture[1], 0.1f },
		}, true);
	const AnimationClip Button_Quit_Selected_Clip = AnimationClip({
		{ Button_Quit_Texture[2], 0.1f },
		{ Button_Quit_Texture[3], 0.1f },
		}, true);

	const AnimatorController Button_Quit_Controller = AnimatorController({
		State("Deselected", &Button_Quit_Deselected_Clip, {
			{ "Selected", false, 1, [](auto& animator) { return animator.GetBool("selected"); }},
		}),
		State("Selected", &Button_Quit_Selected_Clip, {
			{ "Deselected", true, 1, [](auto& animator) { return !animator.GetBool("selected"); }},
		}),
		});
	const GameObject Button_Quit_Object = GameObject(
		"MenuText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&Button_Quit_Texture[0]),
			std::make_shared<Animator>(&Button_Quit_Controller),
			std::make_shared<Button>(
				[](auto) { SceneManager::LoadScene(3); },
				[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", true); },
				[](auto button) { button->gameObject->GetComponent<Animator>()->SetBool("selected", false); }
			),
	});
	#pragma endregion

	const GameObject MenuOptions_Object = GameObject(
		"MenuOptions", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		//std::make_shared<Image>(&AssetManager::MenuOptions[0]),
		std::make_shared<Panel>(&Menu_Image_Texture[0]),
	});

const GameObject MenuEventManager_Object = GameObject(
	"MenuEventManager", "Untagged",
	std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<MenuEventManager>(),
});

Scene Assets_Scenes::MenuScene = Scene({
#pragma region Ui
	{&MenuOptions_Object, Transform()},
	{&Button_1P_Object, Transform(Vector3(0, 0, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
	{&Button_2P_Object, Transform(Vector3(0, -1, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
	{&Button_Help_Object, Transform(Vector3(-1.3, -2, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
	{&Button_Credits_Object, Transform(Vector3(0, -2, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
	{&Button_Quit_Object, Transform(Vector3(1.3, -2, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
	{&MenuEventManager_Object, Transform()},
#pragma endregion

{&AssetManager::MainCamera, Transform()},
//{&GalaxyBackgroundObject, Transform()},
	});
#pragma endregion