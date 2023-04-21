#include "SealPackages.h"
#include "Inputs.h"
#include "Vector2.h"
#include "SceneManager.h"
using namespace SealEngine;
using namespace SealEngine::InputSystem;

UINT Inputs::_uMessage = 0;
KeyCode Inputs::_wParam = (KeyCode)NULL;
LPARAM Inputs::_lParam = NULL;

float Inputs::prev_MouseX = 0;
float Inputs::prev_MouseY = 0;

bool Inputs::keysHold[256];
bool Inputs::keysDown[256];
bool Inputs::keysUp[256];
bool Inputs::_anyKeyDown = false;

bool Inputs::TryHandleMessage(const UINT uMessage, const WPARAM wParam, const LPARAM lParam) {
    _uMessage = uMessage;
    _wParam = (KeyCode)wParam;
    _lParam = lParam;

    switch (uMessage) {
        case WM_KEYDOWN:
            if (!keysHold[wParam]) {
                keysDown[wParam] = true;
                _anyKeyDown = true;
            }
            keysHold[wParam] = true;
            break;
        case WM_KEYUP:
            if (keysHold[wParam]) keysUp[wParam] = true;
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

void Inputs::ResetOnNextFrame() {
    for (int i = 0; i < 256; i++) {
        keysDown[i] = false;
        keysUp[i] = false;
    }
    _anyKeyDown = false;
}

bool Inputs::GetKeyDown(const KeyCode wParam) {
    return keysDown[(int)wParam];
}

bool Inputs::GetKeyUp(const KeyCode wParam) {
    return keysUp[(int)wParam];
}

bool Inputs::GetKey(const KeyCode wParam) {
    return keysHold[(int)wParam];
}

bool InputSystem::Inputs::anyKeyDown() { return _anyKeyDown; }

//pass in LOWORD(lParam) for x, HIWORD(lParam) for y
void Inputs::mouseButtonDown(const WPARAM wParam, double x, double y) {
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

void Inputs::mouseButtonUp() {
    Mouse_Rotate = false;
    Mouse_Translate = false;

}

//pass in GET_WHEEL_DELTA_WPARAM(wParam)
void Inputs::mouseWheel(const WPARAM wParam, const double delta) {
    float newDelta = GET_WHEEL_DELTA_WPARAM(wParam);
    delta / 100;//x += ?
}

Vector2 Inputs::GetMousePosition() {
    //int x, y;
    //glutMotionFunc([](int _x, int _y) { prev_MouseX = _x; prev_MouseY = _y; });

    //int o = GetSystemMetrics(SM_CXSCREEN);

    float factor = 1100 / -(float)SceneManager::camDist;

    POINT mousePosition{};
    return GetCursorPos(&mousePosition)
        ? Vector2((float)(mousePosition.x - (float)GetSystemMetrics(SM_CXSCREEN) / 2) / factor, (float)(-mousePosition.y + GetSystemMetrics(SM_CYSCREEN) / 2) / factor)
        : Vector2::zero();
}
