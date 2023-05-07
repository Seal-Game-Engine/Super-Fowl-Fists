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
	const Texture2D MenuImage = Texture2D("Assets/Menu.png", Texture2D::FilterMode::Nearest, 2);
	const Texture2D Button_1P = Texture2D("Assets/Button_1Player.png", Texture2D::FilterMode::Nearest, 4);
	const AnimationClip Button_1P_Idle = AnimationClip({
		{ Button_1P[0], 0.1f },
		{ Button_1P[1], 0.1f },
		}, true);
	const AnimationClip Button_1P_Selected = AnimationClip({
		{ Button_1P[2], 0.1f },
		{ Button_1P[3], 0.1f },
		}, true);

	const AnimatorController Button_1P_Controller = AnimatorController({
		State("Deselected", &Button_1P_Idle, {
			{ "Selected", false, 1, [](auto& animator) { return animator.GetBool("selected"); }},
		}),
		State("Selected", &Button_1P_Selected, {
			{ "Deselected", true, 1, [](auto& animator) { return !animator.GetBool("selected"); }},
		}),
		});
	const Texture2D Button_2P = Texture2D("Assets/Button_2Player.png", Texture2D::FilterMode::Nearest, 4);
	const Texture2D Button_Help = Texture2D("Assets/Button_Help.png", Texture2D::FilterMode::Nearest, 4);
	const Texture2D Button_Credits = Texture2D("Assets/Button_Credit.png", Texture2D::FilterMode::Nearest, 4);
	const Texture2D Button_Quit = Texture2D("Assets/Button_Quit.png", Texture2D::FilterMode::Nearest, 4);

	const GameObject MenuOptionsObject = GameObject(
		"MenuOptions", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		//std::make_shared<Image>(&AssetManager::MenuOptions[0]),
		std::make_shared<Panel>(&MenuImage[0]),
	});
	const GameObject SinglePlayerButtonObject = GameObject(
		"MenuText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&Button_1P[0]),
			std::make_shared<Animator>(&Button_1P_Controller),
			std::make_shared<Button>(
				[] { SceneManager::LoadScene(3); },
				[] { }
				//[] { SceneManager::LoadScene(3); }
				),
	});

	const GameObject TwoPlayerButtonObject = GameObject(
		"MenuText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&Button_2P[0]),
			std::make_shared<Button>([] {
			SceneManager::LoadScene(5);
				}),
	});

	const GameObject HelpButtonObject = GameObject(
		"MenuText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&Button_Help[0]),
			std::make_shared<Button>([] {
			SceneManager::LoadScene(5);
				}),
	});

	const GameObject CreditsButtonObject = GameObject(
		"MenuText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&Button_Credits[0]),
			std::make_shared<Button>([] {
			SceneManager::LoadScene(5);
				}),
	});

	const GameObject QuitButtonObject = GameObject(
		"MenuText", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&Button_Quit[0]),
			std::make_shared<Button>([] {
			SceneManager::LoadScene(5);
				}),
	});
	const GameObject MenuEventManagerObject = GameObject(
		"MenuEventManager", "Untagged",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<Image>(&AssetManager::GreenSlime[1]),
			std::make_shared<Animator>(&AssetManager::GreenSlime_Controller),
			std::make_shared<MenuEventManager>(),
	});

	Scene Assets_Scenes::MenuScene = Scene({
	#pragma region Ui
		{&MenuOptionsObject, Transform()},
		{&SinglePlayerButtonObject, Transform(Vector3(0, 0, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
		{&TwoPlayerButtonObject, Transform(Vector3(0, -1, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
		{&HelpButtonObject, Transform(Vector3(-1.3, -2, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
		{&CreditsButtonObject, Transform(Vector3(0, -2, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
		{&QuitButtonObject, Transform(Vector3(1.3, -2, 0), Vector3::zero(), Vector3(0.14f, 0.14f, 1))},
		{&MenuEventManagerObject, Transform()},
	#pragma endregion

		{&AssetManager::MainCamera, Transform()},
		//{&GalaxyBackgroundObject, Transform()},
		});
#pragma endregion