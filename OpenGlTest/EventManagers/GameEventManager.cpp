#include "GameEventManager.h"
#include "../Prefab.h"
#include "../GameplayData.h"
#include "../Player.h"
#include <functional>
#include <numeric>
#include <random>
using namespace InputSystem;

GameEventManager* GameEventManager::instance = nullptr;

void GameEventManager::Awake() {
	instance = this;

	pausePanels = gameObject->GetComponents<Image>();
	for (auto& panel : pausePanels) panel->enabled = false;

	GameObject* TikeMyson_Ui = GameObject::FindWithTag("TikeMysonUi");
	GameObject* Chicken_Ui = GameObject::FindWithTag("ChickenUi");

	Instantiate(Prefab::BossObject, Vector2(2.5f, 0));

	GameObject* playerObject = nullptr;
	switch (GameplayData::playerCount) {
		case 1:
			switch (std::rand() % 2) {
				case 0: 
					playerObject = InstantiateT(Prefab::TikeMyson_Object);
					Chicken_Ui->SetActive(false);
					break;
				case 1: 
					playerObject = InstantiateT(Prefab::Chicken_Object); 
					TikeMyson_Ui->SetActive(false);
					Chicken_Ui->transform->position = TikeMyson_Ui->transform->position;
					break;
			};
			playerObject->GetComponent<Player>()->controlScheme = Player::ControlScheme::Solo;
			_playerObjects.emplace_back(playerObject);
			break;
		case 2:
			playerObject = InstantiateT(Prefab::TikeMyson_Object, Vector2(-2.5f, 0));
			playerObject->GetComponent<Player>()->controlScheme = Player::ControlScheme::Player1;
			_playerObjects.emplace_back(playerObject);
			playerObject = InstantiateT(Prefab::Chicken_Object, Vector2(-1.5f, 0));
			playerObject->GetComponent<Player>()->controlScheme = Player::ControlScheme::Player2;
			_playerObjects.emplace_back(playerObject);
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

void GameEventManager::LateUpdate() {
	if(!Camera::mainCamera || _playerObjects.empty()) return;
	Vector2 midPosition = std::accumulate(_playerObjects.begin(), _playerObjects.end(), Vector2::zero(), [](const Vector2& accumulator, const GameObject* playerObject) { return accumulator + playerObject->transform->position; }) / _playerObjects.size();
	Camera::mainCamera->transform()->position = Vector2::Lerp(Camera::mainCamera->transform()->position, midPosition + Vector2::up(), 3 * 0.75f * Time::deltaTime());
}

GameEventManager* GameEventManager::_Clone() const { return new GameEventManager(*this); }
