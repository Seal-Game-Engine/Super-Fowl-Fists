#pragma once
#include <array>
#include "SealEngine.h"
using namespace SealEngine;

class MenuEventManager : public MonoBehaviour{
public:
	void Update() override;

private:
	int selectionId = 0;
	std::array<Vector2, 4> selectionPositions{ Vector2(1, 1), Vector2(1, 0), Vector2(1, -1), Vector2(2, 1) };

	MenuEventManager* Clone_impl() const;
};