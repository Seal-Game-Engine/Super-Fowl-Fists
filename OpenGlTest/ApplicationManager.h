#pragma once
#include <memory>
#include <vector>
#include "SealPackages.h"
#include "SealEngine.h"
#include "SceneManager.h"
using namespace SealEngine::InputSystem;
namespace SealEngine { class SceneManager; }

namespace SealEngine {
	class ApplicationManager {
	public:
		static void DestroyGlWindow();
		static bool SetupWindow(int colorBits, bool fullscreenflag);
		static bool TryToggleFullScreen();

		static bool isFullScreen;
		static HDC	deviceContextHandler;		// Private GDI Device Context

		//static const std::unique_ptr<SceneManager> Scene;
		static SceneManager* sceneManager;

		static int NewMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow);

		static std::vector<std::unique_ptr<IMessageHandler>> messageHandlers;

		static int width, height;

	private:
		static LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
		static bool isActive;

		static HGLRC renderingContextHandler;		// Permanent Rendering Context
		static HWND windowHandler;		// Holds Our Window Handle
		static HINSTANCE instanceHandler;		// Holds The Instance Of The Application

		static wchar_t windowClassName[];
		static wchar_t windowTitle[];
	};
}
