#pragma once

#include <GL/freeglut.h>
#include <string>
#include "Object.h"

namespace SealEngine {
	class Texture2D : public Object {
	public:
		Texture2D(int, int);

		void Load(char*, GLuint&);
		void Bind(GLuint);

		unsigned char* image;
		const int width() const;
		const int height() const;

	private:
		int _width, _height;
	};
}
