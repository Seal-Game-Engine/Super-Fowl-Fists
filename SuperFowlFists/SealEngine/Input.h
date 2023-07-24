#pragma once
#include "IMessageHandler.h"
#include "KeyCode.h"
#include <queue>
#include <string>
namespace SealEngine { struct Vector2; }

namespace SealEngine {
    namespace InputSystem {
        class Input : public IMessageHandler {
        public:
            bool TryHandleMessage(const HWND, const UINT, const WPARAM, const LPARAM) override;
            void ResetOnNextFrame() override;

            static bool GetKeyDown(const KeyCode);
            static bool GetKeyUp(const KeyCode);
            static bool GetKey(const KeyCode);

            enum class Axis { Horizontal, Vertical, MouseX, MouseY };
            static float GetAxisRaw(const Axis axis);

            static bool anyKeyDown();
            static Vector2 mousePosition();

            void mouseWheel(const WPARAM, const double);

        private:
            static UINT _uMessage;
            static WPARAM _wParam;
            static LPARAM _lParam;

            static bool keysHold[256];
            static bool keysDown[256];
            static bool keysUp[256];

            static std::queue<int> keysToggled;

            static bool _anyKeyDown;
        };
    }
}
