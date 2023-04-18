#include "ApplicationManager.h";
#include "Inputs.h"
#include "Time.h"
#include "LandingScene.h"

using namespace SealEngine;

wchar_t ApplicationManager::windowClassName[] = L"OpenGL";
wchar_t ApplicationManager::windowTitle[] = L"Game Engine Lesson";

bool ApplicationManager::isActive = true;
bool ApplicationManager::isFullScreen = true;

HDC	ApplicationManager::deviceContextHandler = NULL;		// Private GDI Device Context
HGLRC ApplicationManager::renderingContextHandler = NULL;		// Permanent Rendering Context
HWND ApplicationManager::windowHandler = NULL;		// Holds Our Window Handle
HINSTANCE ApplicationManager::instanceHandler = NULL;

//const std::unique_ptr<SceneManager> ApplicationManager::sceneManager = std::unique_ptr<SceneManager>();
SceneManager* ApplicationManager::sceneManager = new SceneManager;

int ApplicationManager::width = 0, ApplicationManager::height = 0;

std::vector<std::unique_ptr<IMessageHandler>> ApplicationManager::messageHandlers = std::vector<std::unique_ptr<IMessageHandler>>();

// Handle For This Window, Message For This Window, Additional Message Information, Additional Message Information
LRESULT CALLBACK ApplicationManager::WndProc(HWND hWindow, UINT message, WPARAM wParam, LPARAM lParam) {
	for (auto& messageHandler : messageHandlers) messageHandler->TryHandleMessage(message, wParam, lParam);

	switch (message) {
		case WM_ACTIVATE:
			ApplicationManager::isActive = !HIWORD(wParam);
			break;

		case WM_SYSCOMMAND:							// Intercept System Commands
			switch (wParam) {					// Check System Calls
				case SC_SCREENSAVE:					// Screensaver Trying To Start?
				case SC_MONITORPOWER:				// Monitor Trying To Enter Powersave?
					break;
			}
			break;

		//case WM_CLOSE:
		case WM_DESTROY:
			PostQuitMessage(0);
			break;

		default:
			return DefWindowProc(hWindow, message, wParam, lParam);
	}
	return 0;
}

void ApplicationManager::DestroyGlWindow() {
	if (isFullScreen) {
		ChangeDisplaySettings(NULL, 0);
		ShowCursor(TRUE);
	}

	if (renderingContextHandler) {
		if (!wglMakeCurrent(NULL, NULL))
			MessageBoxW(NULL, L"Release Of DC And RC Failed.", L"SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		if (!wglDeleteContext(renderingContextHandler))
			MessageBoxW(NULL, L"Release Rendering Context Failed.", L"SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		renderingContextHandler = nullptr;
	}

	if (deviceContextHandler && !ReleaseDC(windowHandler, deviceContextHandler)) {
		MessageBoxW(NULL, L"Release Device Context Failed.", L"SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		deviceContextHandler = nullptr;
	}

	if (windowHandler && !DestroyWindow(windowHandler)) {
		MessageBoxW(NULL, L"Could Not Release hWnd.", L"SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		windowHandler = nullptr;
	}

	if (!UnregisterClassW(windowClassName, instanceHandler)) {
		MessageBoxW(NULL, L"Could Not Unregister Class.", L"SHUTDOWN ERROR", MB_OK | MB_ICONINFORMATION);
		instanceHandler = nullptr;
	}
}

bool ApplicationManager::SetupWindow(int colorBits, bool fullscreenflag) {
	int fullscreenWidth = GetSystemMetrics(SM_CXSCREEN);
	int fullscreenHeight = GetSystemMetrics(SM_CYSCREEN);
	int width = fullscreenWidth;
	int height = fullscreenHeight;
	isFullScreen = fullscreenflag;

	instanceHandler = GetModuleHandle(NULL);				// Grab An Instance For Our Window

#pragma region Standard WindowsClass
	//WNDCLASS windowClass{
	//	.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
	//	.lpfnWndProc = WndProc,				// WndProc Handles Messages
	//	.cbClsExtra = 0,									// No Extra Window Data
	//	.cbWndExtra = 0,									// No Extra Window Data
	//	.hInstance = instanceHandler,						// Set The Instance
	//	.hIcon = LoadIcon(NULL, IDI_WINLOGO),			// Load The Default Icon
	//	.hCursor = LoadCursor(NULL, IDC_ARROW),			// Load The Arrow Pointer
	//	.hbrBackground = NULL,							// No Background Required For GL
	//	.lpszMenuName = NULL,									// We Don't Want A Menu
	//	.lpszClassName = szWindowClass								// Set The Class Name
	//};
	//if (!RegisterClass(&windowClass)) {
	//	MessageBox(NULL, L"Failed To Register The Window Class.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
	//	return false;
	//}
#pragma endregion

#pragma region Extended WindowsClass
	WNDCLASSEXW windowClassEx{
		//.cbSize = sizeof(WNDCLASSEX),
		//.style = CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
		//.lpfnWndProc = WndProc,
		//.cbClsExtra = 0,
		//.cbWndExtra = 0,
		//.hInstance = instanceHandler,
		//.hIcon = LoadIcon(windowClassEx.hInstance, IDI_APPLICATION),//.hIcon = LoadIcon(NULL, IDI_WINLOGO),
		//.hCursor = LoadCursor(NULL, IDC_ARROW),
		//.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1),//NULL
		//.lpszMenuName = NULL,
		//.lpszClassName = windowClassName,
		//.hIconSm = LoadIcon(windowClassEx.hInstance, IDI_APPLICATION)

		sizeof(WNDCLASSEX),
		CS_HREDRAW | CS_VREDRAW | CS_OWNDC,
		WndProc,
		0,
		0,
		instanceHandler,
		LoadIcon(windowClassEx.hInstance, IDI_APPLICATION),//.hIcon = LoadIcon(NULL, IDI_WINLOGO),
		LoadCursor(NULL, IDC_ARROW),
		(HBRUSH)(COLOR_WINDOW + 1),//NULL
		NULL,
		windowClassName,
		LoadIcon(windowClassEx.hInstance, IDI_APPLICATION)
	};
	if (!RegisterClassExW(&windowClassEx)) {
		MessageBoxW(NULL, L"Call to RegisterClassEx failed!", L"Windows Desktop Guided Tour", NULL);
		return false;
	}
#pragma endregion

	DWORD dwStyle;				// Window Style
	DWORD dwExStyle;				// Window Extended Style

	if (ApplicationManager::isFullScreen) {
		ShowCursor(TRUE);									// Hide Mouse Pointer
		dwStyle = WS_POPUP;			// must handle Gsync situations: Windows Style
		dwExStyle = WS_EX_APPWINDOW;								// Window Extended Style
	} else {
		dwStyle = WS_OVERLAPPEDWINDOW;							// Windows Style
		dwExStyle = WS_EX_APPWINDOW | WS_EX_WINDOWEDGE;			// Window Extended Style
	}

#pragma region WindowRect
	RECT WindowRect{
		/*.left = 0,
		.top = 0,
		.right = width,
		.bottom = height*/

		0,
		0,
		width,
		height
	};
	AdjustWindowRectEx(&WindowRect, dwStyle, FALSE, dwExStyle);// Adjust Window To True Requested Size
#pragma endregion

	windowHandler = CreateWindowExW(
		dwExStyle, //WS_EX_OVERLAPPEDWINDOW,
		windowClassName,
		windowTitle,
		dwStyle | WS_CLIPSIBLINGS | WS_CLIPCHILDREN,// Required Window Style
		0, 0,// Window Position
		WindowRect.right - WindowRect.left, WindowRect.bottom - WindowRect.top,
		NULL,// No Parent Window
		NULL,// No Menu
		instanceHandler,
		NULL// Dont Pass Anything To WM_CREATE
	);
	if (!windowHandler) {
		//DestroyGlWindow(windowHandler);						// Reset The Display
		MessageBoxW(NULL, L"Window Creation Error.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;								// Return FALSE
	}

	PIXELFORMATDESCRIPTOR pixelFormatDescriptor = {
			sizeof(PIXELFORMATDESCRIPTOR),				// Size Of This Pixel Format Descriptor
			1,											// Version Number
			PFD_DRAW_TO_WINDOW | PFD_SUPPORT_OPENGL | PFD_DOUBLEBUFFER,	// Must Support Double Buffering
			PFD_TYPE_RGBA,								// Request An RGBA Format
			colorBits,										// Select Our Color Depth
			0, 0, 0, 0, 0, 0,							// Color Bits Ignored
			0,											// No Alpha Buffer
			0,											// Shift Bit Ignored
			0,											// No Accumulation Buffer
			0, 0, 0, 0,									// Accumulation Bits Ignored
			32,											// 16Bit Z-Buffer (Depth Buffer)//todo:expose var
			0,											// No Stencil Buffer
			0,											// No Auxiliary Buffer
			PFD_MAIN_PLANE,								// Main Drawing Layer
			0,											// Reserved
			0, 0, 0										// Layer Masks Ignored
	};

#pragma region ErrorChecks
	if (!(deviceContextHandler = GetDC(windowHandler))) {
		MessageBoxW(NULL, L"Can't Create A GL Device Context.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	int	PixelFormat;
	if (!(PixelFormat = ChoosePixelFormat(deviceContextHandler, &pixelFormatDescriptor))) {
		MessageBoxW(NULL, L"Can't Find A Suitable PixelFormat.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	if (!SetPixelFormat(deviceContextHandler, PixelFormat, &pixelFormatDescriptor)) {
		MessageBoxW(NULL, L"Can't Set The PixelFormat.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	if (!(renderingContextHandler = wglCreateContext(deviceContextHandler))) {
		MessageBoxW(NULL, L"Can't Create A GL Rendering Context.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}

	if (!wglMakeCurrent(deviceContextHandler, renderingContextHandler)) {
		MessageBoxW(NULL, L"Can't Activate The GL Rendering Context.", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
#pragma endregion

	ShowWindow(windowHandler, SW_SHOW);						// Show The Window
	//UpdateWindow(windowHandler);
	SetForegroundWindow(windowHandler);
	SetFocus(windowHandler);
	return true;
}

bool ApplicationManager::TryToggleFullScreen() {
	DestroyGlWindow();
	isFullScreen = !isFullScreen;
	return SetupWindow(256, isFullScreen);
}

bool GetActionLOLL() {
	if (InputSystem::Inputs::GetKeyDown(KeyCode::Escape)) return false;
	return true;
}

int ApplicationManager::NewMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	int colorBits = 256;
	instanceHandler = hInstance;
	width = GetSystemMetrics(SM_CXSCREEN);
	height = GetSystemMetrics(SM_CYSCREEN);

	if (!SetupWindow(colorBits, true)) return 1;

	//Scene = std::unique_ptr<SceneManager>(new SceneManager);
	sceneManager->ResizeGl(width, height);
	if (!sceneManager->InitGl()) {
		MessageBoxW(NULL, L"Initialization Failed", L"ERROR", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
	messageHandlers.emplace_back(sceneManager);
	messageHandlers.emplace_back(new Inputs);

	sceneManager->scenes.push_back(std::make_unique<LandingScene>());
	sceneManager->LoadScene(0);

	MSG msg;
	while (true) {
		for (auto& messageHandler : messageHandlers) messageHandler->ResetOnNextFrame();

		if (PeekMessage(&msg, NULL, 0, 0, PM_REMOVE)) {
			if (msg.message == WM_QUIT) break;

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		Time::OnNextFrame();
		sceneManager->RefreshScene();


		if (!GetActionLOLL()) break;
	}

	DestroyGlWindow();
	return msg.wParam;
}

//Create
//1. init local var (width etc)
//
//2. window class extended, try register class
//
//3. window rect
//4. init style and fullscreen settings
//5. adjust window rect with style
//
//6. window creation and storage into window handler
//
//7. pixel format and bug checks
//
//8. functions on window
//
//9. Scene init and program loop

//Destroy
//1. restore display settings
//2. rendering context restore
//3. device context restore
//4. destroy window handler
//5. unregister window class

//Obsolete code
//DEVMODE dmScreenSettings;								// Device Mode
//memset(&dmScreenSettings, 0, sizeof(dmScreenSettings));	// Makes Sure Memory's Cleared
//dmScreenSettings.dmSize = sizeof(dmScreenSettings);		// Size Of The Devmode Structure
//dmScreenSettings.dmFields = DM_BITSPERPEL | DM_PELSWIDTH | DM_PELSHEIGHT;
//dmScreenSettings.dmBitsPerPel = colorBits;					// Selected Bits Per Pixel
//dmScreenSettings.dmPelsWidth = width;				// Selected Screen Width
//dmScreenSettings.dmPelsHeight = height;				// Selected Screen Height

//todo: tidy up from bug check, see if func vars need to be static
