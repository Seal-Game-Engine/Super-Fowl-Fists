#include "SpriteRenderer.h"
using namespace SealEngine;

void SpriteRenderer::Awake() {
}

void SpriteRenderer::LateUpdate() {
	//sprite.texture.Bind();

	glPushMatrix();
	{
		glTranslated(transform.position.x(), transform.position.y(), transform.position.z());
		glRotatef(transform.rotation.x(), 1, 0, 0);
		glRotatef(transform.rotation.y(), 0, 1, 0);
		glRotatef(transform.rotation.z(), 0, 0, 1);
		glScalef(transform.scale.x(), transform.scale.y(), transform.scale.z());

		//glColor3f(1, 1, 1);

		//Rendering
		glBegin(GL_POLYGON);
		{
			std::vector<Vector2> vertices = sprite.vertices();

			float xMin = 0, xMax = 1.0 / 4, yMin = 0, yMax = 1.0 / 4;

			// Vertex3f for 3D
			glTexCoord2f(xMin, yMin);
			glVertex2f(vertices[0].x(), vertices[0].y());

			glTexCoord2f(xMax, yMin);
			glVertex2f(vertices[1].x(), vertices[1].y());

			glTexCoord2f(xMax, yMax);
			glVertex2f(vertices[2].x(), vertices[2].y());

			glTexCoord2f(xMin, yMax);
			glVertex2f(vertices[3].x(), vertices[3].y());
		}
		glEnd();
	}
	glPopMatrix();
}