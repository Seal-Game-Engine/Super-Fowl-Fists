#pragma once
#include <array>
#include "../SealEngine.h"
using namespace SealEngine;

class MenuEventManager : public MonoBehaviour{
public:
	static MenuEventManager* instance;

	void Awake() override;
	void Update() override;

private:
	int selectionId = 0;
	std::array<Vector2, 5> selectionPositions = { Vector2(1, 1), Vector2(1, 0), Vector2(1, -1), Vector2(2, 1), Vector2(2, 0), };

	enum class MenuPage { MainMenu, LevelSelectMenu };
	MenuPage _currentPage = MenuPage::MainMenu;



	MenuEventManager* _Clone() const;
};