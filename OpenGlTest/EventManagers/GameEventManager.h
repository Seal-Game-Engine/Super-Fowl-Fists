#pragma once
#include "../SealEngine.h"
#include <vector>
using namespace SealEngine;
using namespace SealEngine::Ui;

class GameEventManager : public MonoBehaviour{
public:
	static GameEventManager* instance;

	std::vector<Image*> pausePanels{};

	void Awake() override;
	void Update() override;
	void LateUpdate() override;

private:
	void TogglePause();

	bool _isPaused = false;
	std::vector<GameObject*> _playerObjects{};
	GameEventManager* _Clone() const override;
};

