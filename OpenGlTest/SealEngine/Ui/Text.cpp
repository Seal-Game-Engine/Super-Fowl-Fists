#include "Text.h"
#include "../Camera.h"
#include "../Transform.h"
#include "../Rect.h"
#include "../Sprite.h"
using namespace SealEngine::Ui;

Text::Text(const std::string& text, const Texture2D* fontTexture, int fontSize, Alignment alignment)
	:text(text), fontTexture(fontTexture), fontSize(fontSize), alignment(alignment) {}

void Text::OnGui(){
	if (!Camera::mainCamera) return;

	glPushMatrix();
	{
		glTranslatef(transform()->position.x(), transform()->position.y(), transform()->position.z());
		glRotatef(transform()->rotation.x(), 1, 0, 0);
		glRotatef(transform()->rotation.y(), 0, 1, 0);
		glRotatef(transform()->rotation.z(), 0, 0, 1);
		glScalef(transform()->scale.x() * fontSize, transform()->scale.y() * fontSize, transform()->scale.z() * fontSize);

		glBindTexture(GL_TEXTURE_2D, fontTexture->textureId());
		glColor4f(1, 1, 1, 1);

		for (int i = 0; i < text.size(); i++) {
			int character = text[i];
			glBegin(GL_QUADS);
			{
				const Rect rect = (*fontTexture)[character].rect();
				const Rect textureRect = (*fontTexture)[character].textureRect();
				const Vector2 offset = Vector2(textureRect.size().x() * ((float)i - ((float)text.size() - 1) / 2), 0); //minus 1 to remove \n

				// Vertex3f for 3D
				glTexCoord2f(rect.minVertex().x(), rect.minVertex().y());
				glVertex2f(textureRect.minVertex().x() + offset.x(), textureRect.maxVertex().y() + offset.y());

				glTexCoord2f(rect.maxVertex().x(), rect.minVertex().y());
				glVertex2f(textureRect.maxVertex().x() + offset.x(), textureRect.maxVertex().y() + offset.y());

				glTexCoord2f(rect.maxVertex().x(), rect.maxVertex().y());
				glVertex2f(textureRect.maxVertex().x() + offset.x(), textureRect.minVertex().y() + offset.y());

				glTexCoord2f(rect.minVertex().x(), rect.maxVertex().y());
				glVertex2f(textureRect.minVertex().x() + offset.x(), textureRect.minVertex().y() + offset.y());
			}
			glEnd();
		}
		glBindTexture(GL_TEXTURE_2D, 0);
	}
	glPopMatrix();
}
