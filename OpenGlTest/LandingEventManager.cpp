#include "LandingEventManager.h"

void LandingEventManager::Update(){
	using namespace InputSystem;

	if (Inputs::GetKeyDown(KeyCode::Return)) SceneManager::LoadScene(1);
	if (Inputs::GetKeyDown(KeyCode::Escape)) {}
}
