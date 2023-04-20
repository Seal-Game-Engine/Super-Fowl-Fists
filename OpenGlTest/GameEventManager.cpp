#include "GameEventManager.h"
using namespace InputSystem;

void GameEventManager::Awake(){
	pausePanel = gameObject->GetComponent<SpriteRenderer>();
	pausePanel->enabled = false;
}

void GameEventManager::Update() {
	if (Inputs::GetKeyDown(KeyCode::Escape) || Inputs::GetKeyDown(KeyCode::P))TogglePause();
}

std::shared_ptr<GameEventManager> GameEventManager::Clone() const { return std::shared_ptr<GameEventManager>(Clone_impl()); }

void GameEventManager::TogglePause(){
	_isPaused = !_isPaused;
	pausePanel->enabled = _isPaused;
	Time::timeScale = _isPaused ? 0 : 1;
}

GameEventManager* GameEventManager::Clone_impl() const { return new GameEventManager(*this); }
