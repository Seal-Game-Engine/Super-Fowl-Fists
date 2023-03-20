#pragma once

#include <GL/freeglut.h>
#include <string>
#include <vector>
#include "Object.h"
namespace SealEngine { class Sprite; }

namespace SealEngine {
	class Texture2D : public Object {
	public:
		Texture2D(std::string textureSource, int columns = 1, int rows = 1);

		const int width() const;
		const int height() const;
		const GLuint textureName() const;

		const Sprite& operator[](int);

	private:
		int _width, _height, _channelCount;
		int _columns, _rows;
		std::vector<Sprite> sprites;
		GLuint _textureName;
	};
}
