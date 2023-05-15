#pragma once
#include "../SealEngine.h"
#include <vector>
#include "../Boss.h"
#include "../Player.h"
using namespace SealEngine;
using namespace SealEngine::Ui;

class GameEventManager : public MonoBehaviour{
public:
	static GameEventManager* instance;

	void UpdateUi();
	void OnLevelCompleted();
	void OnLevelFailed();

	std::vector<Image*> pausePanels{};

	void Awake() override;
	void Start() override;
	void Update() override;
	void LateUpdate() override;

private:
	void TogglePause();

	Text* _bossHpText = nullptr;
	Text* _p1HpText = nullptr;
	Text* _p2HpText = nullptr;

	bool _isPaused = false;
	bool _levelCompleted = false;
	Boss* _bossObject = nullptr;
	std::vector<Player*> _playerObjects{};
	GameEventManager* _Clone() const override;
};

