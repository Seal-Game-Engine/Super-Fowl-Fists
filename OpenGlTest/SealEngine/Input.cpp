#include "SealPackages.h"
#include "Input.h"
#include "Vector2.h"
#include "Vector3.h"
#include "SceneManager.h"
using namespace SealEngine;
using namespace SealEngine::InputSystem;

UINT Input::_uMessage = 0;
KeyCode Input::_wParam = (KeyCode)NULL;
LPARAM Input::_lParam = NULL;

float Input::prev_MouseX = 0;
float Input::prev_MouseY = 0;

bool Input::keysHold[256];
bool Input::keysDown[256];
bool Input::keysUp[256];
std::queue<int> Input::keysToggled{};
bool Input::_anyKeyDown = false;

bool Input::TryHandleMessage(const UINT uMessage, const WPARAM wParam, const LPARAM lParam) {
	_uMessage = uMessage;
	_wParam = (KeyCode)wParam;
	_lParam = lParam;

	switch (uMessage) {
	case WM_KEYDOWN:
		if (!keysHold[wParam]) {
			keysDown[wParam] = true;
			keysToggled.push(wParam);
			_anyKeyDown = true;
		}
		keysHold[wParam] = true;
		break;
	case WM_KEYUP:
		if (keysHold[wParam]) {
			keysUp[wParam] = true;
			keysToggled.push(wParam);
		}
		keysHold[wParam] = false;
		break;

	case WM_LBUTTONDOWN:
		break;

	case WM_RBUTTONDOWN:
		break;

	case WM_MBUTTONDOWN:
		break;

	case WM_LBUTTONUP:
	case WM_RBUTTONUP:
	case WM_MBUTTONUP:
		break;

	case WM_MOUSEMOVE:
		//prev_MouseX = GET_X_LPARAM(_lParam) - prev_MouseX;
		//prev_MouseY = GET_Y_LPARAM(_lParam) - prev_MouseY;
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

//pass in LOWORD(lParam) for x, HIWORD(lParam) for y
void Input::mouseButtonDown(const WPARAM wParam, double x, double y) {
	prev_MouseX = x;
	prev_MouseY = y;

	switch (wParam) {
	case MK_LBUTTON:
		Mouse_Rotate = true;
		break;
	case MK_RBUTTON:
		Mouse_Translate = true;
		break;
	case MK_MBUTTON:
		break;
	}
}

void Input::mouseButtonUp() {
	Mouse_Rotate = false;
	Mouse_Translate = false;

}

//pass in GET_WHEEL_DELTA_WPARAM(wParam)
void Input::mouseWheel(const WPARAM wParam, const double delta) {
	float newDelta = GET_WHEEL_DELTA_WPARAM(wParam);
	delta / 100;//x += ?
}

Vector2 Input::GetMousePosition() {
	int x = 0, y = 0;//mouse position

	//lecture
	GLdouble modelViewMatrix[16];
	GLdouble projectionMatrix[16];
	GLint viewPort[4];
	Vector3 windowVector = Vector3::zero();
	GLdouble winX, winY, winZ;
	Vector3 positionVector = Vector3::zero();
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);
	glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
	glGetIntegerv(GL_VIEWPORT, viewPort);
	//windowVector = Vector3(
	winX = x;
	winY = (float)viewPort[3] - y;
	glReadPixels(x, (int)viewPort[3] - y, 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	gluUnProject(winX, winY, winZ, modelViewMatrix, projectionMatrix, viewPort, &posX, &posY, &posZ);
	//end class



	//int x, y;
	//glutMotionFunc([](int _x, int _y) { prev_MouseX = _x; prev_MouseY = _y; });

	//int o = GetSystemMetrics(SM_CXSCREEN);

	float factor = 1100 / -(float)SceneManager::camDist;

	POINT mousePosition{};
	return GetCursorPos(&mousePosition)
		? Vector2((float)(mousePosition.x - (float)GetSystemMetrics(SM_CXSCREEN) / 2) / factor, (float)(-mousePosition.y + GetSystemMetrics(SM_CYSCREEN) / 2) / factor)
		: Vector2::zero();
}
