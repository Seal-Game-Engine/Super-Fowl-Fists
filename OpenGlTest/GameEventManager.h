#pragma once
#include "SealEngine.h"
#include <vector>
using namespace SealEngine;

class GameEventManager : public MonoBehaviour{
public:
	std::vector<SpriteRenderer*> pausePanels{};

	void Awake() override;
	void Update() override;

private:
	void TogglePause();

	bool _isPaused = false;

	GameEventManager* Clone_impl() const override;
};

