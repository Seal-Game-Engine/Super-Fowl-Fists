#include "GameEventManager.h"
#include "../Prefab.h"
#include "../GameplayData.h"
#include "../Player.h"
#include <functional>
#include <numeric>
#include <random>
using namespace InputSystem;

GameEventManager* GameEventManager::instance = nullptr;

void GameEventManager::UpdateUi(){
	if (_bossObject) _bossHpText->text = std::to_string((int)_bossObject->currentHp);

	switch (GameplayData::playerCount) {
	case 1:		
		_p1HpText->text = std::to_string((int)_playerObjects[0]->currentHp);
		break;
	case 2:
		_p1HpText->text = std::to_string((int)_playerObjects[0]->currentHp);
		_p2HpText->text = std::to_string((int)_playerObjects[1]->currentHp);
		break;
	}

	for (auto& player : _playerObjects) if (player->isAlive())return;
	OnLevelFailed();
}

void GameEventManager::OnLevelCompleted(){
	_levelCompleted = true;
	Time::timeScale = 0;
	pausePanels[0]->sprite = &Prefab::WinScreen[0];
	pausePanels[0]->enabled = true;
}
void GameEventManager::OnLevelFailed() {
	_levelCompleted = true;
	Time::timeScale = 0;
	pausePanels[0]->sprite = &Prefab::LoseScreen[0];
	pausePanels[0]->enabled = true;
}

void GameEventManager::Awake() {
	instance = this;
	pausePanels = gameObject->GetComponents<Image>();
	for (auto& panel : pausePanels) panel->enabled = false;

	GameObject* TikeMyson_Ui = GameObject::FindWithTag("TikeMysonUi");
	GameObject* Chicken_Ui = GameObject::FindWithTag("ChickenUi");

	auto texts = Scene::FindObjectsByType<Text>();
	_bossHpText = texts[0];
	_p1HpText = texts[1];
	_p2HpText = texts[3];

	switch (GameplayData::level) {
	case 1:
		_bossObject = InstantiateT(Prefab::Sensei_Object, Vector2(2.5f, 0))->GetComponent<Boss>();
		break;
	case 2:
		_bossObject = InstantiateT(Prefab::BossObject, Vector2(2.5f, 0))->GetComponent<Boss>();
		break;
	default:
		_bossHpText->gameObject->SetActive(false);
		break;
	}

	Player* playerObject = nullptr;
	switch (GameplayData::playerCount) {
	case 1:
		switch (std::rand() % 2) {
		case 0:
			playerObject = InstantiateT(Prefab::TikeMyson_Object, Vector2(-2.5, 0))->GetComponent<Player>();
			playerObject->controlScheme = Player::ControlScheme::Solo;
			Chicken_Ui->SetActive(false);
			break;
		case 1:
			playerObject = InstantiateT(Prefab::Chicken_Object, Vector2(-1.5, 0))->GetComponent<Player>();
			playerObject->controlScheme = Player::ControlScheme::Solo;
			TikeMyson_Ui->SetActive(false);
			Chicken_Ui->transform->position = TikeMyson_Ui->transform->position;
			break;
		};
		_playerObjects.emplace_back(playerObject);
		_p2HpText->gameObject->SetActive(false);
		break;
	case 2:
		playerObject = InstantiateT(Prefab::TikeMyson_Object, Vector2(-1.5, 0))->GetComponent<Player>();
		playerObject->controlScheme = Player::ControlScheme::Player1;
		_playerObjects.emplace_back(playerObject);
		playerObject = InstantiateT(Prefab::Chicken_Object, Vector2(-1.5, 0))->GetComponent<Player>();
		playerObject->controlScheme = Player::ControlScheme::Player2;
		_playerObjects.emplace_back(playerObject);
		break;
	}

	UpdateUi();
}

void GameEventManager::Start() {
	AudioSource* _audioSource = gameObject->GetComponent<AudioSource>();


	switch (GameplayData::level) {
		case 0:
			_audioSource->clip = "Assets/Sounds/Menu.wav";

			break;
		case 1:
			_audioSource->clip = "Assets/Sounds/LastSamurai_MasterWu.wav";

			break;
		case 2:
			_audioSource->clip = "Assets/Sounds/CombatPlan_MK1.wav";

			break;
	}
	_audioSource->Play();
}

void GameEventManager::Update() {
	if (_levelCompleted) {
		if (Input::GetKeyDown(KeyCode::Escape) || Input::GetKeyDown(KeyCode::Return)) { 
			SceneManager::LoadScene(1); 
			Time::timeScale = 1;
		}
		return;
	}

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
	Vector2 midPosition = std::accumulate(_playerObjects.begin(), _playerObjects.end(), Vector2::zero(), [](const Vector2& accumulator, Player* playerObject) { return accumulator + playerObject->transform()->position; }) / _playerObjects.size();
	Camera::mainCamera->transform()->position = Vector2::Lerp(Camera::mainCamera->transform()->position, midPosition + Vector2::up(), 3 * 0.75f * Time::deltaTime());
}

GameEventManager* GameEventManager::_Clone() const { return new GameEventManager(*this); }
