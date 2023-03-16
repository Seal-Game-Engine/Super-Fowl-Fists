#include "Texture2D.h"
#include <SOIL2.h>
using namespace SealEngine;

Texture2D::Texture2D(int width, int height) : _width(width), _height(height) {}

void Texture2D::Load(char* fileName, GLuint& textureId) {
	glGenTextures(1, &textureId);
	glBindTexture(GL_TEXTURE_2D, textureId);
	
	image = SOIL_load_image(fileName, &_width, &_height, 0, SOIL_LOAD_RGBA);

	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
}

//called on draw
void Texture2D::Bind(GLuint textureId) {
	glBindTexture(GL_TEXTURE_2D, textureId);
}

const int Texture2D::width() const { return _width; }
const int Texture2D::height() const { return _height; }
