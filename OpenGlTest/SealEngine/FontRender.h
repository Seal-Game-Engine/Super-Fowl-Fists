#pragma once
#include <string>
#include <vector>
#include "Vector2.h"
#include "Vector3.h"
using namespace SealEngine;

//i want to make a font rendering class that can be used by the engine and the game
class FontRender
{
	public:

	struct Font{
		std::string name;
		std::string path;
		std::vector<unsigned char> data;
		int size;
		int lineHeight;
		int base;
		int scaleW;
		int scaleH;
		int pages;
		int packed;
		int outline;
		int outlineThickness;
		int padding[4];
		int spacing[2];
		int outlinePadding;
		int outlineSpacing;
		int outlineSize;
		int outlineColor;
	};

	struct Text{
		std::string name;
		std::string fontName;
		std::string text;
		Vector2 position;
		float scale;
		Vector3 color;
		bool centered;
		bool isUI;
		bool is3D;
	};

	FontRender();
	~FontRender();

	static void Init();// initialize the font rendering system
	static void Shutdown();// shutdown the font rendering system

	static void LoadFont(std::string fontName, std::string fontPath);// load a font from a file
	static void UnloadFont(std::string fontName);// unload a font from memory

	static void LoadText(std::string textName, std::string fontName, std::string text);// load a text from a font
	static void UnloadText(std::string textName);// unload a text from memory

	static void RenderText(std::string textName);// render text
	static void RenderText(std::string textName, Vector2 position);// render text at position
	static void RenderText(std::string text, Vector2 position, float scale);// render text at position with scale
	static void RenderText(std::string text, Vector2 position, float scale, Vector3 color);// render text at position with scale and color
	static void RenderText(std::string text, Vector2 position, float scale, Vector3 color, bool centered);// render text at position with scale and color and centered
	static void RenderText(std::string text, Vector2 position, float scale, Vector3 color, bool centered, bool isUI);// render text at position with scale and color and centered and isUI
	static void RenderText(std::string text, Vector2 position, float scale, Vector3 color, bool centered, bool isUI, bool is3D);// render text at position with scale and color and centered and isUI and is3D
	
	private:
		static std::vector<Font> fonts;
		static std::vector<Text> texts;
};

