#pragma once
#include <windows.h>
#include <memory>
#include <vector>
#include "SceneManager.h"
#include "SealEngine.h"
//#include "IMessageHandler.h"
using namespace SealEngine::InputSystem;

namespace SealEngine {
	class ApplicationManager {
	public:
		static void DestroyGlWindow();
		static bool SetupWindow(int colorBits, bool fullscreenflag);
		static bool TryToggleFullScreen();

		static bool isFullScreen;
		static HDC	deviceContextHandler;		// Private GDI Device Context

		static SceneManager* Scene;
		static Inputs* Input;
		static int NewMain(_In_ HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ LPSTR lpCmdLine, _In_ int nCmdShow);

		static std::vector<std::unique_ptr<IMessageHandler>> messageHandlers;

	private:
		static LRESULT CALLBACK WndProc(_In_ HWND, _In_ UINT, _In_ WPARAM, _In_ LPARAM);
		static bool isActive;

		static HGLRC renderingContextHandler;		// Permanent Rendering Context
		static HWND windowHandler;		// Holds Our Window Handle
		static HINSTANCE instanceHandler;		// Holds The Instance Of The Application

		static wchar_t windowClassName[];
		static wchar_t windowTitle[];
	};
}