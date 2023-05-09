#pragma once
#include "../SealEngine.h"
#include <vector>
using namespace SealEngine;
using namespace SealEngine::Ui;

class GameEventManager : public MonoBehaviour{
public:
	std::vector<Image*> pausePanels{};

	void Awake() override;
	void Update() override;

private:
	void TogglePause();

	bool _isPaused = false;

	GameEventManager* _Clone() const override;
};

