#include "Button.h"
#include "../SceneManager.h"
#include "../GameObject.h"
#include "../Camera.h"
#include "../Input.h"
using namespace SealEngine;
using namespace SealEngine::Ui;

#include "../../AssetManager.h"

Button::Button(std::function<void(Button*)> onClick, std::function<void(Button*)> onSelected, std::function<void(Button*)> onDeselected)
	:onClick(onClick), onSelected(onSelected), onDeselected(onDeselected) {}

void Button::Awake() {
	_image = gameObject->GetComponent<IRenderer>();
}

void Button::Update() {
	if (!_image) _image = gameObject->GetComponent<IRenderer>();
	if (!_image) return;

	Rect buttonRect = _image->sprite->textureRect();
	buttonRect.SetSize(buttonRect.size().x() * transform()->scale.x(), buttonRect.size().y() * transform()->scale.y());
	buttonRect.SetCenter(transform()->position.x(), transform()->position.y());
	Vector2 mousePosition = Camera::mainCamera->ScreenToWorldPoint(InputSystem::Input::mousePosition());

	bool mouseIsHovering =
		mousePosition.x() >= buttonRect.minVertex().x() &&
		mousePosition.x() <= buttonRect.maxVertex().x() &&
		mousePosition.y() >= buttonRect.minVertex().y() &&
		mousePosition.y() <= buttonRect.maxVertex().y();

	if (!_isSelected && mouseIsHovering) { _isSelected = true; onSelected(this); }
	else if (_isSelected && !mouseIsHovering) { _isSelected = false; onDeselected(this); }

	if (Input::GetKeyDown(KeyCode::MouseLeft) && _isSelected) onClick(this);
}

void Button::OnGui() {}
