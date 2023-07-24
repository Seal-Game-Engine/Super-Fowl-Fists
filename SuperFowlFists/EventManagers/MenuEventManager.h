#pragma once
#include <array>
#include <vector>
#include "../SealEngine.h"
using namespace SealEngine;

class MenuEventManager : public MonoBehaviour{
public:
	static MenuEventManager* instance;

	enum class MenuPage { MainMenu, LevelSelectMenu };
	void LoadMenu(MenuPage menuPage);

	void Awake() override;
	void Start() override;
	void Update() override;

private:
	MenuPage _currentPage = MenuPage::MainMenu;

	std::vector<GameObject*> _mainMenuObjects{};
	std::vector<GameObject*> _levelSelectObjects{};

	MenuEventManager* _Clone() const override { return new MenuEventManager(*this); };
};