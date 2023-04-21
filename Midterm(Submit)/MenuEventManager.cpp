#include "MenuEventManager.h"

void MenuEventManager::Update() {
	using namespace InputSystem;
	if (Inputs::GetKeyDown(KeyCode::W) || Inputs::GetKeyDown(KeyCode::UpArrow)) selectionId = --selectionId % selectionPositions.size();
	if (Inputs::GetKeyDown(KeyCode::S) || Inputs::GetKeyDown(KeyCode::DownArrow))selectionId = ++selectionId % selectionPositions.size();

	if (Inputs::GetKeyDown(KeyCode::Space) || Inputs::GetKeyDown(KeyCode::Return)) {
		switch (selectionId) {
		case 0:
			SceneManager::LoadScene(3); break;
		case 1:
			SceneManager::LoadScene(2); break;
		case 2:
			SceneManager::Quit(); break;
		}
	}

	if (Inputs::GetKeyDown(KeyCode::Escape)) SceneManager::LoadScene(0);

	transform()->position = selectionPositions[selectionId];
}

MenuEventManager* MenuEventManager::Clone_impl() const { return new MenuEventManager(*this); }
