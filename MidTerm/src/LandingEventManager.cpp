#include "LandingEventManager.h"

void LandingEventManager::Update(){
	using namespace InputSystem;

	if (Inputs::GetKeyDown(KeyCode::Return)) SceneManager::LoadScene(1);
	if (Inputs::GetKeyDown(KeyCode::Escape)) SceneManager::Quit();
}

std::shared_ptr<LandingEventManager> LandingEventManager::Clone() const { return std::shared_ptr<LandingEventManager>(Clone_impl()); }

LandingEventManager* LandingEventManager::Clone_impl() const { return new LandingEventManager(*this); }
