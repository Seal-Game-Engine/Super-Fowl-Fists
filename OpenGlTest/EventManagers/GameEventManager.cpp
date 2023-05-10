#include "GameEventManager.h"
#include "../Prefab.h"
#include "../GameplayData.h"
#include "../Player.h"
using namespace InputSystem;

void GameEventManager::Awake(){
	pausePanels = gameObject->GetComponents<Image>();
	for(auto& panel : pausePanels) panel->enabled = false;

	Instantiate(Prefab::BossObject, Vector2(2.5f, 0));

	switch (GameplayData::playerCount) {
	case 1:
		InstantiateT(Prefab::TikeMyson_Object)->GetComponent<Player>()->controlScheme = Player::ControlScheme::Solo;
		break;
	case 2:
		InstantiateT(Prefab::TikeMyson_Object, Vector2(-2.5f, 0))->GetComponent<Player>()->controlScheme = Player::ControlScheme::Player1;
		InstantiateT(Prefab::Chicken_Object, Vector2(-1.5f, 0))->GetComponent<Player>()->controlScheme = Player::ControlScheme::Player2;//Chicken here
		break;
	}
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
	Time::timeScale = _isPaused ? 0.0f : 1.0f;
}

GameEventManager* GameEventManager::_Clone() const { return new GameEventManager(*this); }
