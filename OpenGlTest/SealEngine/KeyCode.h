// https://docs.microsoft.com/en-us/windows/win32/inputdev/virtual-key-codes
#pragma once
#include "SealPackages.h"

namespace SealEngine {
	namespace InputSystem {
		enum class KeyCode : WPARAM {
			Idle = NULL,

			// Mouse
			MouseLeft = VK_LBUTTON,
			MouseRight = VK_RBUTTON,
			MouseMiddle = VK_MBUTTON,
			MouseX1 = VK_XBUTTON1,
			MouseX2 = VK_XBUTTON2,

#pragma region Alphabets
			A = 0x41,
			B = 0x42,
			C = 0x43,
			D = 0x44,
			E = 0x45,
			F = 0x46,
			G = 0x47,
			H = 0x48,
			I = 0x49,
			J = 0x4A,
			K = 0x4B,
			L = 0x4C,
			M = 0x4D,
			N = 0x4E,
			O = 0x4F,
			P = 0x50,
			Q = 0x51,
			R = 0x52,
			S = 0x53,
			T = 0x54,
			U = 0x55,
			V = 0x56,
			W = 0x57,
			X = 0x58,
			Y = 0x59,
			Z = 0x5A,
#pragma endregion

#pragma region Numbers
			Alpha0 = 0x30,
			Alpha1 = 0x31,
			Alpha2 = 0x32,
			Alpha3 = 0x33,
			Alpha4 = 0x34,
			Alpha5 = 0x35,
			Alpha6 = 0x36,
			Alpha7 = 0x37,
			Alpha8 = 0x38,
			Alpha9 = 0x39,
#pragma endregion

#pragma region FunctionKeys
			F1 = VK_F1,
			F2 = VK_F2,
			F3 = VK_F3,
			F4 = VK_F4,
			F5 = VK_F5,
			F6 = VK_F6,
			F7 = VK_F7,
			F8 = VK_F8,
			F9 = VK_F9,
			F10 = VK_F10,
			F11 = VK_F11,
			F12 = VK_F12,
#pragma endregion

#pragma region WhiteSpaces
			Backspace = VK_BACK,
			Tab = VK_TAB,
			Return = VK_RETURN,
			Space = VK_SPACE,
#pragma endregion

#pragma region Commands
			LeftShift = VK_LSHIFT,
			RightShift = VK_RSHIFT,
			LeftControl = VK_LCONTROL,
			RightControl = VK_RCONTROL,
			LeftAlt = VK_LMENU,
			RightAlt = VK_RMENU,
			CapsLock = VK_CAPITAL,
			Escape = VK_ESCAPE,
			Pause = VK_PAUSE,
			Print = VK_PRINT,
			PrintScreen = VK_SNAPSHOT,
			Execute = VK_EXECUTE,
			Insert = VK_INSERT,
			Delete = VK_DELETE,
			Help = VK_HELP,
#pragma endregion

#pragma Navigation
			PageUp = VK_PRIOR,
			PageDown = VK_NEXT,
			End = VK_END,
			Home = VK_HOME,
			Select = VK_SELECT,

			LeftArrow = VK_LEFT,
			RightArrow = VK_RIGHT,
			UpArrow = VK_UP,
			DownArrow = VK_DOWN,
#pragma endregion

#pragma region Symbols
			Plus = VK_OEM_PLUS,
			Minus = VK_OEM_MINUS,
			Comma = VK_OEM_COMMA,
			Period = VK_OEM_PERIOD,
			Slash = VK_OEM_2,
#pragma endregion

			//Exclaim	= Exclamation mark key '!'.
			//DoubleQuote	Double quote key '"'.
			//Hash	Hash key '#'.
			//Dollar	Dollar sign key '$'.
			//Percent	Percent '%' key.
			//Ampersand	Ampersand key '&'.
			//Quote	Quote key '.
			//LeftParen	Left Parenthesis key '('.
			//RightParen	Right Parenthesis key ')'.
			//Asterisk	Asterisk key '*'.
			/*Colon	Colon ':' key.
			Semicolon	Semicolon ';' key.
			Less	Less than '<' key.
			Equals	Equals '=' key.
			Greater	Greater than '>' key.
			Question	Question mark '?' key.
			At	At key '@'.
			LeftBracket	Left square bracket key '['.
			Backslash	Backslash key '\'.
			RightBracket	Right square bracket key ']'.
			Caret	Caret key '^'.
			Underscore	Underscore '_' key.
			BackQuote*/
		};
	}
}
