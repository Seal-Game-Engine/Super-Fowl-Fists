#include "Button.h"
#include "GameObject.h"
#include "Inputs.h"
using namespace SealEngine;

void Button::Update(){
	if (!renderer) renderer = gameObject->GetComponent<SpriteRenderer>();

	transform()->position = SealEngine::InputSystem::Inputs::GetMousePosition();

	if (SealEngine::InputSystem::Inputs::GetKey(SealEngine::InputSystem::KeyCode::P))
		transform()->position = transform()->position;
}
