#pragma once
#include "../SealEngine.h"
#include <vector>
#include "../Player.h"
using namespace SealEngine;
using namespace SealEngine::Ui;

class GameEventManager : public MonoBehaviour{
public:
	static GameEventManager* instance;

	void UpdateUi();
	void OnLevelCompleted();

	std::vector<Image*> pausePanels{};

	void Awake() override;
	void Update() override;
	void LateUpdate() override;

private:
	void TogglePause();

	Text* p1HpText = nullptr;
	Text* p2HpText = nullptr;

	bool _isPaused = false;
	bool _levelCompleted = false;
	std::vector<Player*> _playerObjects{};
	GameEventManager* _Clone() const override;
};

