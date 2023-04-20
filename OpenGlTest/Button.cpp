#include "Button.h"
#include "GameObject.h"
#include "Inputs.h"
#include "SceneManager.h"
using namespace SealEngine;

void Button::Update(){
	if (InputSystem::Inputs::GetKeyDown(InputSystem::KeyCode::Return)) {
		static int sceneId = 0;
		sceneId = ++sceneId % 2;
		SceneManager::LoadScene(sceneId);
		return;
	}

	if (!renderer) renderer = gameObject->GetComponent<SpriteRenderer>();

	transform()->position = SealEngine::InputSystem::Inputs::GetMousePosition();

	if (SealEngine::InputSystem::Inputs::GetKey(SealEngine::InputSystem::KeyCode::P))
		transform()->position = transform()->position;
}
