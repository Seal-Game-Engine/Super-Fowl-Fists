#include "TutorialEventManager.h"

void TutorialEventManager::Update(){
	using namespace InputSystem;
	if (Input::GetKeyDown(KeyCode::Escape) || Input::GetKeyDown(KeyCode::Return))SceneManager::LoadScene(1);
}

TutorialEventManager* TutorialEventManager::_Clone() const { return new TutorialEventManager(*this); }
