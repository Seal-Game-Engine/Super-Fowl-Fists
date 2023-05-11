#include "MenuEventManager.h"

MenuEventManager* MenuEventManager::instance = nullptr;

void MenuEventManager::LoadMenu(MenuPage menuPage){
	for (auto& object : _mainMenuObjects) object->SetActive(false);
	for (auto& object : _levelSelectObjects) object->SetActive(false);

	switch (menuPage) {
	case MenuPage::MainMenu: for (auto& object : _mainMenuObjects) object->SetActive(true); break;
	case MenuPage::LevelSelectMenu: for (auto& object : _levelSelectObjects) object->SetActive(true); break;
	}
	_currentPage = menuPage;
}

void MenuEventManager::Awake(){
	instance = this;
	//AudioSource* _audioSource = nullptr;

	//_audioSource->clip = "../Assets/Sounds/Menu.wav";
	//_audioSource->Play();
	_mainMenuObjects = GameObject::FindGameObjectsWithTag("MainMenuUi");
	_levelSelectObjects = GameObject::FindGameObjectsWithTag("LevelSelectUi");
	LoadMenu(MenuPage::MainMenu);
}

void MenuEventManager::Update() {
	using namespace InputSystem;

	switch (_currentPage)	{
	case MenuPage::MainMenu:
		if (Input::GetKeyDown(KeyCode::Escape)) { SceneManager::LoadScene(0); return; }
		break;
	case MenuPage::LevelSelectMenu:
		if (Input::GetKeyDown(KeyCode::Escape)) LoadMenu(MenuPage::MainMenu); 
		break;
	}
}
