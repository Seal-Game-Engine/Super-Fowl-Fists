#include "SealPackages.h"
#include "Input.h"
#include "Vector2.h"
#include "Vector3.h"
#include "SceneManager.h"
#include "ApplicationManager.h"
using namespace SealEngine;
using namespace SealEngine::InputSystem;

UINT Input::_uMessage = 0;
WPARAM Input::_wParam = NULL;
LPARAM Input::_lParam = NULL;

bool Input::keysHold[256];
bool Input::keysDown[256];
bool Input::keysUp[256];
std::queue<int> Input::keysToggled{};
bool Input::_anyKeyDown = false;

bool Input::TryHandleMessage(const HWND hWindow, const UINT uMessage, const WPARAM wParam, const LPARAM lParam) {
	_uMessage = uMessage;
	_wParam = wParam;
	_lParam = lParam;

	switch (uMessage) {
	case WM_LBUTTONDOWN:
		goto KeyDown;
	case WM_RBUTTONDOWN:
		goto KeyDown;
	case WM_MBUTTONDOWN:
		_wParam = (WPARAM)KeyCode::MouseMiddle;
		goto KeyDown;
	case WM_KEYDOWN:
	KeyDown:
		if (!keysHold[_wParam]) {
			keysDown[_wParam] = true;
			keysToggled.push(_wParam);
			_anyKeyDown = true;
		}
		keysHold[_wParam] = true;
		break;

	case WM_LBUTTONUP:
		_wParam = (WPARAM)KeyCode::MouseLeft;
		goto KeyUp;
	case WM_RBUTTONUP:
		_wParam = (WPARAM)KeyCode::MouseRight;
		goto KeyUp;
	case WM_MBUTTONUP:
		_wParam = (WPARAM)KeyCode::MouseMiddle;
		goto KeyUp;
	case WM_KEYUP:
	KeyUp:
		if (keysHold[_wParam]) {
			keysUp[_wParam] = true;
			keysToggled.push(_wParam);
		}
		keysHold[_wParam] = false;
		break;

	case WM_MOUSEWHEEL:
		break;
	default:
		return false;
	}
	return true;
}

void Input::ResetOnNextFrame() {
	while (!keysToggled.empty()) {
		keysDown[keysToggled.front()] = false;
		keysUp[keysToggled.front()] = false;
		keysToggled.pop();
	}
	_anyKeyDown = false;
}

bool Input::GetKeyDown(const KeyCode wParam) { return keysDown[(int)wParam]; }
bool Input::GetKeyUp(const KeyCode wParam) { return keysUp[(int)wParam]; }
bool Input::GetKey(const KeyCode wParam) { return keysHold[(int)wParam]; }

float Input::GetAxisRaw(const Axis axis) {
	switch (axis) {
	case Axis::Horizontal:
		return
			(Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::LeftArrow) ? -1 : 0) +
			(Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::RightArrow) ? 1 : 0);
	case Axis::Vertical:
		return
			(Input::GetKey(KeyCode::W) || Input::GetKey(KeyCode::UpArrow) ? 1 : 0) +
			(Input::GetKey(KeyCode::S) || Input::GetKey(KeyCode::DownArrow) ? -1 : 0);
	}
	return 0;
}

bool Input::anyKeyDown() { return _anyKeyDown; }

Vector2 Input::mousePosition() {
	POINT mousePosition{};
	GetCursorPos(&mousePosition);
	return Vector2(mousePosition.x, mousePosition.y);
}

//pass in GET_WHEEL_DELTA_WPARAM(wParam)
void Input::mouseWheel(const WPARAM wParam, const double delta) {
	float newDelta = GET_WHEEL_DELTA_WPARAM(wParam);
	delta / 100;//x += ?
}