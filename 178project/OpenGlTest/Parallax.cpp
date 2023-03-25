#include "Parallax.h"

Parallax::Parallax() {

}

void Parallax::drawSquare(float width, float height) {
	glColor3f(1, 1, 1);
	//textureLoader.Bind();
	glBegin(GL_POLYGON);
	{
		glTexCoord2f(xMin, yMin);
		glVertex3f(-width / height, -1, -8);

		glTexCoord2f(xMax, yMin);
		glVertex3f(width / height, -1, -8);

		glTexCoord2f(xMax, yMax);
		glVertex3f(width / height, 1, -8);

		glTexCoord2f(xMin, yMax);
		glVertex3f(-width / height, 1, -8);
	}
	glEnd();
}

void Parallax::initParallax() {
	//textureLoader.Load();
}

void Parallax::scroll(bool doScroll, std::string Dir, float speed) {
	if (!doScroll) return;
	if (clock() - startTime > 16) {
		if (Dir == "x") { xMin += speed; xMax += speed; }
		//todo: notes to myself, replace Dir with Vector2 or smthg
		startTime = clock();
	}
}
