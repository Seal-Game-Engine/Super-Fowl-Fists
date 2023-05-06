#include "SealPackages.h"
#include "SpriteRenderer.h"
#include "Texture2D.h"
#include "Transform.h"
#include <array>
using namespace SealEngine;

SpriteRenderer::SpriteRenderer(const Sprite* sprite, bool flipX, bool flipY)
	: sprite(sprite), flipX(flipX), flipY(flipY) {}

SpriteRenderer::SpriteRenderer(const SpriteRenderer& obj) : MonoBehaviour(obj), sprite(obj.sprite), flipX(obj.flipX), flipY(obj.flipY) {}

void SpriteRenderer::Update() {
}

void SpriteRenderer::LateUpdate() {
	glPushMatrix();
	{
		glTranslatef(transform()->position.x(), transform()->position.y(), transform()->position.z());
		glRotatef(transform()->rotation.x(), 1, 0, 0);
		glRotatef(transform()->rotation.y(), 0, 1, 0);
		glRotatef(transform()->rotation.z(), 0, 0, 1);
		glScalef(transform()->scale.x(), transform()->scale.y(), transform()->scale.z());

		glBindTexture(GL_TEXTURE_2D, sprite->texture->textureId());
		glColor4f(1, 1, 1, 1);

		//Rendering
		glBegin(GL_QUADS);
		{
			Rect rect = sprite->rect;
			std::array<Vector2, 4> vertices = sprite->vertices();

			// Vertex3f for 3D
			glTexCoord2f(rect.minVertex().x(), rect.minVertex().y());
			glVertex2f(vertices[0].x(), vertices[0].y());

			glTexCoord2f(rect.maxVertex().x(), rect.minVertex().y());
			glVertex2f(vertices[1].x(), vertices[1].y());

			glTexCoord2f(rect.maxVertex().x(), rect.maxVertex().y());
			glVertex2f(vertices[2].x(), vertices[2].y());

			glTexCoord2f(rect.minVertex().x(), rect.maxVertex().y());
			glVertex2f(vertices[3].x(), vertices[3].y());
		}
		glEnd();

		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();
}