#include "TutorialEventManager.h"

void TutorialEventManager::Update(){
	using namespace InputSystem;
	if (Input::GetKeyDown(KeyCode::Escape) || Input::GetKeyDown(KeyCode::Return))SceneManager::LoadScene(1);
}

TutorialEventManager* TutorialEventManager::Clone_impl() const { return new TutorialEventManager(*this); }