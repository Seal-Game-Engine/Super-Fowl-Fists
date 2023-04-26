#include "MenuEventManager.h"

void MenuEventManager::Update() {
	using namespace InputSystem;
	if (Input::GetKeyDown(KeyCode::W) || Input::GetKeyDown(KeyCode::UpArrow)) selectionId = --selectionId % selectionPositions.size();
	if (Input::GetKeyDown(KeyCode::S) || Input::GetKeyDown(KeyCode::DownArrow))selectionId = ++selectionId % selectionPositions.size();

	if (Input::GetKeyDown(KeyCode::Space) || Input::GetKeyDown(KeyCode::Return)) {
		switch (selectionId) {
		case 0:
			SceneManager::LoadScene(3); break;
		case 1:
			SceneManager::LoadScene(2); break;
		case 2:
			SceneManager::Quit(); break;
		case 3:
			SceneManager::LoadScene(4); break;
		}
	}

	if (Input::GetKeyDown(KeyCode::Escape)) SceneManager::LoadScene(0);

	transform()->position = selectionPositions[selectionId];
}

MenuEventManager* MenuEventManager::Clone_impl() const { return new MenuEventManager(*this); }
