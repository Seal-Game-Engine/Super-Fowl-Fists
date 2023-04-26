#include "GameEventManager.h"
using namespace InputSystem;

void GameEventManager::Awake(){
	pausePanels = gameObject->GetComponents<SpriteRenderer>();
	for(auto& panel : pausePanels) panel->enabled = false;
}

void GameEventManager::Update() {
	if (!_isPaused && (Input::GetKeyDown(KeyCode::Escape) || Input::GetKeyDown(KeyCode::Return))) TogglePause();

	else if (_isPaused) {
		if (Input::GetKeyDown(KeyCode::Escape)) SceneManager::LoadScene(1);
		if (Input::anyKeyDown()) TogglePause();
	}
}

void GameEventManager::TogglePause(){
	_isPaused = !_isPaused;
	for (auto& panel : pausePanels) panel->enabled = _isPaused;
	Time::timeScale = _isPaused ? 0 : 1;
}

GameEventManager* GameEventManager::Clone_impl() const { return new GameEventManager(*this); }