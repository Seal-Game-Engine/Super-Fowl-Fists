#pragma once
#include <string>
#include <queue>
#include <tuple>
#include "SealPackages.h"
#include "Object.h"
namespace SealEngine { class Sprite; }

namespace SealEngine {
	class Texture2D : public Object {
	public:
		enum class FilterMode : GLint { Nearest = GL_NEAREST, Linear = GL_LINEAR };

		const int width() const;
		const int height() const;
		const GLuint& textureId() const;

		static void LoadUninitializedTextures();

		Texture2D(const std::string textureSource, const FilterMode filterMode, int columns = 1, int rows = 1);

		const Sprite& operator[](int) const;

	private:
		int _width = 0, _height = 0, _channelCount = 0;
		GLuint _textureId = 0;
		std::vector<Sprite> sprites;

		void LoadTexture(const std::string& textureSource, const FilterMode filterMode);

		struct TextureInitializer
		{
			Texture2D& texture;
			const std::string textureSource;
			const FilterMode filterMode;
		};
		static std::queue<TextureInitializer> uninitializedTextures;
	};
}
