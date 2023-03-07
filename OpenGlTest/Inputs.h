#pragma once
#include "IMessageHandler.h"

#include "Vector3.h"

namespace SealEngine::InputSystem {

	class Inputs : public IMessageHandler {
	public:
		bool TryHandleMessage(const UINT, const WPARAM, const LPARAM) override;

		static bool GetKeyDown(const WPARAM);
		static bool GetKeyUp(const WPARAM);
		static bool GetKey(const WPARAM);

		void mouseButtonDown(const WPARAM, double, double);
		void mouseButtonUp();
		void mouseWheel(const WPARAM, const double);

		static Vector3 GetMousePosition();

		static float prev_MouseX;
		static float prev_MouseY;

		bool Mouse_Translate;
		bool Mouse_Rotate;

	private:
		static UINT _uMessage;
		static WPARAM _wParam;
		static LPARAM _lParam;

		static bool keys[256];
	};
}
