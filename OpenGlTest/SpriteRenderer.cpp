#include "SealPackages.h"
#include "SpriteRenderer.h"
#include "Texture2D.h"
#include "Transform.h"
#include <array>
using namespace SealEngine;

void SpriteRenderer::Awake() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}

void SpriteRenderer::Update()
{
}

void SpriteRenderer::LateUpdate() {
	glPushMatrix();
	{
		glTranslated(transform().position.x(), transform().position.y(), transform().position.z());
		glRotatef(transform().rotation.x(), 1, 0, 0);
		glRotatef(transform().rotation.y(), 0, 1, 0);
		glRotatef(transform().rotation.z(), 0, 0, 1);
		glScalef(transform().scale.x(), transform().scale.y(), transform().scale.z());

		glBindTexture(GL_TEXTURE_2D, sprite->texture->textureId());
		glColor4f(1, 1, 1, 1);

		//Rendering
		glBegin(GL_QUADS);
		{
			Rect rect = sprite->rect;
			//std::vector<Vector2> vertices = sprite->vertices();

			std::array<Vector3, 4> vertices{
				Vector3(-0.5f, 0.5f, 1),
				Vector3(0.5f, 0.5f, 1),
				Vector3(0.5f, -0.5f, 1),
				Vector3(-0.5f, -0.5f, 1),
			};

			// Vertex3f for 3D
			glTexCoord2f(rect.minVertex().x(), rect.minVertex().y());
			glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z());

			glTexCoord2f(rect.maxVertex().x(), rect.minVertex().y());
			glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z());

			glTexCoord2f(rect.maxVertex().x(), rect.maxVertex().y());
			glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z());

			glTexCoord2f(rect.minVertex().x(), rect.maxVertex().y());
			glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z());
		}
		glEnd();

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();
}