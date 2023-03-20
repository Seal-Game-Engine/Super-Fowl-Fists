#include "Texture2D.h"
#include <SOIL2.h>
#include "Sprite.h"
using namespace SealEngine;

Texture2D::Texture2D(std::string textureSource, int columns, int rows)
	: _columns(columns), _rows(rows) {
	glGenTextures(1, &_textureName);
	glBindTexture(GL_TEXTURE_2D, _textureName);

	auto image = SOIL_load_image(textureSource.c_str(), &_width, &_height, &_channelCount, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	//todo: generate sprites vector
	sprites.reserve(columns * rows);
	for (int rowId = 0; rowId < rows; rowId++) {
		for (int columnId = 0; columnId < columns; columnId++) {
			sprites.push_back(Sprite(*this, Vector2(0.5f, 0.5f), 16));
		}
	}
}

const int Texture2D::width() const { return _width; }
const int Texture2D::height() const { return _height; }

const GLuint Texture2D::textureName() const { return _textureName; }

const Sprite& Texture2D::operator[](int i) { return sprites[i]; }
