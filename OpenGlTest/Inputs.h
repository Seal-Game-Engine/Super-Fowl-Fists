#pragma once
#include "IMessageHandler.h"
#include "KeyCode.h"
namespace SealEngine { struct Vector2; }

namespace SealEngine {
	namespace InputSystem {
		class Inputs : public IMessageHandler {
		public:
			bool TryHandleMessage(const UINT, const WPARAM, const LPARAM) override;
			void ResetOnNextFrame() override;

			static bool GetKeyDown(const KeyCode);
			static bool GetKeyUp(const KeyCode);
			static bool GetKey(const KeyCode);

			void mouseButtonDown(const WPARAM, double, double);
			void mouseButtonUp();
			void mouseWheel(const WPARAM, const double);

			static Vector2 GetMousePosition();

			static float prev_MouseX;
			static float prev_MouseY;

			bool Mouse_Translate;
			bool Mouse_Rotate;

		private:
			static UINT _uMessage;
			static KeyCode _wParam;
			static LPARAM _lParam;

			static bool keys[256];
		};
	}
}
