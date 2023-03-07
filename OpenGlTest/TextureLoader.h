#pragma once

#include <GL/freeglut.h>
#include <string>

namespace SealEngine {
	class TextureLoader {
	public:
		void Load(char*, GLuint&);
		void Bind(GLuint);

		unsigned char* image;
		int width, height;
	};
}
