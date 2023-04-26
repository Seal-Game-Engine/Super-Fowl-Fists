#include "Button.h"
#include "GameObject.h"
#include "Input.h"
#include "SceneManager.h"
using namespace SealEngine;

void Button::Update(){
	if (InputSystem::Input::GetKeyDown(InputSystem::KeyCode::Return)) {
		static int sceneId = 0;
		sceneId = ++sceneId % 2;
		SceneManager::LoadScene(sceneId);
		return;
	}

	if (!renderer) renderer = gameObject->GetComponent<SpriteRenderer>();

	transform()->position = SealEngine::InputSystem::Input::GetMousePosition();

	if (SealEngine::InputSystem::Input::GetKey(SealEngine::InputSystem::KeyCode::P))
		transform()->position = transform()->position;
}
