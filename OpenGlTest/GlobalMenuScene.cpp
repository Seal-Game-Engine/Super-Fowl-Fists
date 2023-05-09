
#include "GlobalMenuScene.h"
#include "Parallax.h"
#include "GameplayData.h"
#include "EventManagers/GameEventManager.h"
#include "EventManagers/MenuEventManager.h"
#include "EventManagers/LandingEventManager.h"
#include "EventManagers/CreditEventManager.h"
#include "EventManagers/SealLogoEventManager.h"
using State = AnimatorController::AnimationState;
#pragma region Shared Assets
const GameObject MainCamera = GameObject(
	"Main Camera", "MainCamera",
	std::vector<std::shared_ptr<MonoBehaviour>>{
	std::make_shared<Camera>(Camera::Projection::Orthographic, 3),
});
#pragma endregion
#pragma region SealLogoScene
	#pragma region SealLogoScene Asset
		const Texture2D SealLogoScene_Parallax_Texture = Texture2D("Assets/BlocksParallax.png", Texture2D::FilterMode::Nearest);
		const Texture2D SealLogo_Texture = Texture2D("Assets/SealEngineLogo.png", Texture2D::FilterMode::Nearest, 4, 1,  120);
		const AnimationClip SealLogo_Idle_Clip = AnimationClip({
		{ SealLogo_Texture[0], 0.1f },
		{ SealLogo_Texture[1], 0.1f },
		{ SealLogo_Texture[2], 0.1f },
		{ SealLogo_Texture[3], 0.1f },
				}, true);
		const AnimatorController SealLogoScene_Controller = AnimatorController({
			State("Idle", &SealLogo_Idle_Clip),
			});
		const GameObject SealLogoScene_Object = GameObject(
			"Title", "Untagged",
			std::vector<std::shared_ptr<MonoBehaviour>>{
			//std::make_shared<Parallax>(&SealLogoScene_Parallax_Texture[0], Vector2::left(), 0.01),
				std::make_shared<Image>(&SealLogo_Texture[0]),
				std::make_shared<Animator>(&SealLogoScene_Controller),
		});
	#pragma region SealLogoInteractions
		const GameObject SealLogoEventManager_Object = GameObject(
			"LandingEventManager", "Untagged",
			std::vector<std::shared_ptr<MonoBehaviour>>{
			std::make_shared<SealLogoEventManager>(),
		});
	#pragma endregion
	#pragma endregion
	#pragma region SealLogoScene Properties
		Scene GlobalMenuScene::SealLogoScene = Scene({
		#pragma region Ui
		{&SealLogoScene_Object, Transform(Vector2(0, 0.5f))},
		{&SealLogoEventManager_Object, Transform()},
		//{&SealEngineCObject, Transform(Vector2(0, -2.5f))},
		#pragma endregion
		{&MainCamera, Transform()},
			});
	#pragma endregion
#pragma endregion

#pragma region LandingScene

	#pragma region LandingScene Assets

		#pragma region Title
		const Texture2D LandingScene_Parallax_Texture = Texture2D("Assets/BlocksParallax.png", Texture2D::FilterMode::Nearest);
		const Texture2D LandingScene_Title_Texture = Texture2D("Assets/SuperFowlFists.png", Texture2D::FilterMode::Nearest, 2, 1, 96);
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
		#pragma endregion
		#pragma region PressEnter
		const Texture2D LandingScene_Enter_Texture = Texture2D("Assets/PressEnter.png", Texture2D::FilterMode::Nearest, 2);
		const AnimationClip Enter_Idle_Clip = AnimationClip({
		{ LandingScene_Enter_Texture[0], 0.1f },
		{ LandingScene_Enter_Texture[1], 0.1f },
			}, true);
		const AnimatorController Enter_Controller = AnimatorController({
			State("Idle", &Enter_Idle_Clip),
			});
		const GameObject Enter_Object = GameObject(
			"Title", "Untagged",
			std::vector<std::shared_ptr<MonoBehaviour>>{
				std::make_shared<Image>(&LandingScene_Enter_Texture[0]),
				std::make_shared<Animator>(&Enter_Controller),
		});
		#pragma endregion
		#pragma region SealEngine c
		const Texture2D SealEngineC_Texture = Texture2D("Assets/SealEngine.png", Texture2D::FilterMode::Nearest, 1,1,208);
		const GameObject SealEngineCObject = GameObject(
			"Title", "Untagged",
			std::vector<std::shared_ptr<MonoBehaviour>>{
			std::make_shared<Image>(&SealEngineC_Texture[0]),
		});
		#pragma endregion
		#pragma region TitleInteractions
		const GameObject LandingEventManagerObject = GameObject(
			"LandingEventManager", "Untagged",
			std::vector<std::shared_ptr<MonoBehaviour>>{
			std::make_shared<LandingEventManager>(),
		});
		#pragma endregion

	#pragma endregion
	#pragma region LandingSceneProperties
	Scene GlobalMenuScene::LandingScene = Scene({
		#pragma region Ui
		{&TitleObject, Transform(Vector2(0, 0.5f))},
		{&LandingEventManagerObject, Transform()},
		{&Enter_Object, Transform(Vector2(0, -2.0f))},
		{&SealEngineCObject, Transform(Vector2(0, -2.5f))},

		#pragma endregion
		{&MainCamera, Transform()},
		});
	#pragma endregion

#pragma endregion

#pragma region MenuScene
//const Texture2D MenuText = Texture2D("Assets/MenuText.png", Texture2D::FilterMode::Nearest);
	#pragma region MenuScene Assets
		#pragma region Menu
		const Texture2D Menu_Image_Texture = Texture2D("Assets/Menu.png", Texture2D::FilterMode::Nearest, 2);
		const AnimationClip Menu_Image_Idle_Clip = AnimationClip({
			{ Menu_Image_Texture[0], 0.1f },
			{ Menu_Image_Texture[1], 0.1f },
			}, true);
		const AnimatorController Menu_Image_Controller = AnimatorController({State("Idle", &Menu_Image_Idle_Clip)});
			const GameObject Menu_Image_Object = GameObject(
				"MenuOptions", "Untagged",
				std::vector<std::shared_ptr<MonoBehaviour>>{
				//std::make_shared<Image>(&AssetManager::MenuOptions[0]),
				std::make_shared<Panel>(&Menu_Image_Texture[0]),
					std::make_shared<Animator>(&Menu_Image_Controller)
			});
		#pragma endregion
		#pragma region Button_1P
		const Texture2D Button_1P_Texture = Texture2D("Assets/Button_1Player.png", Texture2D::FilterMode::Nearest, 4, 1, 256);

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
					[](auto) { GameplayData::playerCount = 1; SceneManager::LoadScene(4); },
					[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", true); },
					[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", false); }
				),
		});
		#pragma endregion
		#pragma region Button_2P
		const Texture2D Button_2P_Texture = Texture2D("Assets/Button_2Player.png", Texture2D::FilterMode::Nearest, 4, 1, 256);

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
					[](auto) { GameplayData::playerCount = 2; SceneManager::LoadScene(5); },
					[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", true); },
					[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", false); }
				),
		});
		#pragma endregion
		#pragma region Button_Help
		const Texture2D Button_Help_Texture = Texture2D("Assets/Button_Help.png", Texture2D::FilterMode::Nearest, 4, 1, 256);

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
					[](auto) { SceneManager::LoadScene(6); },
					[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", true); },
					[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", false); }
				),
		});
		#pragma endregion
		#pragma region Button_Credits
		const Texture2D Button_Credits_Texture = Texture2D("Assets/Button_Credit.png", Texture2D::FilterMode::Nearest, 4, 1, 256);

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
						[](auto) { SceneManager::LoadScene(2); },
						[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", true); },
						[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", false); }
					),
			});
			#pragma endregion
		#pragma region Button_Quit
			const Texture2D Button_Quit_Texture = Texture2D("Assets/Button_Quit.png", Texture2D::FilterMode::Nearest, 4, 1, 256);
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
						[](auto) { SceneManager::Quit(); },
						[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", true); },
						[](Button* button) { button->gameObject->template GetComponent<Animator>()->SetBool("selected", false); }
					),
			});
			#pragma endregion
		#pragma region MenuInteractions
		const GameObject MenuEventManager_Object = GameObject(
			"MenuEventManager", "Untagged",
			std::vector<std::shared_ptr<MonoBehaviour>>{
				std::make_shared<MenuEventManager>(),
		});
		#pragma endregion
	#pragma endregion
	#pragma region MenuScene Properties
	Scene GlobalMenuScene::MenuScene = Scene({
		#pragma region Ui
		{&Menu_Image_Object, Transform()},
		{&Button_1P_Object, Transform(Vector2(0, -0.5))},
		{&Button_2P_Object, Transform(Vector2(0, -1.3))},
		{&Button_Help_Object, Transform(Vector2(-1.3, -2))},
		{&Button_Credits_Object, Transform(Vector2(0, -2))},
		{&Button_Quit_Object, Transform(Vector2(1.3, -2))},
		{&MenuEventManager_Object, Transform()},
		{&TitleObject, Transform(Vector3(0, 1.5f, 0), Vector3::zero(), Vector3(0.75f, 0.75f, 1))},
		#pragma endregion
		{&MainCamera, Transform()},
		});
	#pragma endregion

#pragma endregion

#pragma region CreditScene
	#pragma region CreditScene Assets
		#pragma region Credit
			const Texture2D Credit_Image_Texture = Texture2D("Assets/Game_Credit.png", Texture2D::FilterMode::Nearest);
			const AnimationClip Credit_Image_Idle_Clip = AnimationClip({
				{ Credit_Image_Texture[0], 0.1f },
				//{ Credit_Image_Texture[1], 0.1f },
				}, true);
			const AnimatorController Credit_Image_Controller = AnimatorController({ State("Idle", &Credit_Image_Idle_Clip) });
			const GameObject Credit_Image_Object = GameObject(
				"MenuOptions", "Untagged",
				std::vector<std::shared_ptr<MonoBehaviour>>{
				std::make_shared<Panel>(&Credit_Image_Texture[0]),
					std::make_shared<Animator>(&Credit_Image_Controller)
			});
		#pragma endregion
		#pragma region CreditInteractions
				const GameObject CreditSceneManager_Object = GameObject(
					"MenuEventManager", "Untagged",
					std::vector<std::shared_ptr<MonoBehaviour>>{
					std::make_shared<CreditEventManager>(),
				});
			#pragma endregion
	#pragma endregion
	#pragma region CreditScene Properties
				Scene GlobalMenuScene::CreditScene = Scene({
					#pragma region Ui
					{&Credit_Image_Object, Transform()},
					{&CreditSceneManager_Object, Transform()},
				#pragma endregion
					{&MainCamera, Transform()},
					});
	#pragma endregion
#pragma endregion
