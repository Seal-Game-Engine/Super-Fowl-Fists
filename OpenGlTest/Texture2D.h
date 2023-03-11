#pragma once

#include <GL/freeglut.h>
#include <string>

namespace SealEngine {
	class Texture2D {
	public:
		void Load(char*, GLuint&);
		void Bind(GLuint);

		unsigned char* image;
		int width, height;
	};
}
