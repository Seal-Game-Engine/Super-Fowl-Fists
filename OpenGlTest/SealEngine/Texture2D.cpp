#include "Texture2D.h"
#include "Sprite.h"
using namespace SealEngine;

std::queue<Texture2D::TextureInitializer> Texture2D::uninitializedTextures{};

Texture2D::Texture2D(const std::string textureSource, const FilterMode filterMode, int columns, int rows) {
	sprites.reserve((size_t)columns * rows);

	//todo: figure out pixels per unit
	//int spriteWidth = width() / columns;
	//int spriteHeight = height() / rows;
	float spriteWidth = 1.0f / columns;
	float spriteHeight = 1.0f / rows;

	for (int rowId = 0; rowId < rows; rowId++)
		for (int columnId = 0; columnId < columns; columnId++)
			sprites.emplace_back(*this, Rect(columnId * spriteWidth, rowId * spriteHeight, spriteWidth, spriteHeight), Vector2(0, 0), 32);

	uninitializedTextures.push({ *this, textureSource, filterMode });
}

const int Texture2D::width() const { return _width; }
const int Texture2D::height() const { return _height; }
const GLuint& Texture2D::textureId() const { return _textureId; }

const Sprite& Texture2D::operator[](int i) const { return sprites[i]; }

void Texture2D::LoadTexture(const std::string& textureSource, const FilterMode filterMode) {
	glGenTextures(1, &_textureId);
	glBindTexture(GL_TEXTURE_2D, textureId());

	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, (GLint)filterMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, (GLint)filterMode);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);

	auto image = SOIL_load_image(textureSource.data(), &_width, &_height, &_channelCount, SOIL_LOAD_RGBA);
	glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, width(), height(), 0, GL_RGBA, GL_UNSIGNED_BYTE, image);
	SOIL_free_image_data(image);

	for (auto& sprite : sprites) { sprite.LoadVertices(); }
}
void Texture2D::LoadUninitializedTextures() {
	while (!uninitializedTextures.empty()) {
		auto& textureInitializer = uninitializedTextures.front();
		textureInitializer.texture.LoadTexture(textureInitializer.textureSource, textureInitializer.filterMode);
		uninitializedTextures.pop();
	}
}
