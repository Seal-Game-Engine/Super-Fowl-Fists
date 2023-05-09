#include "Panel.h"
#include "../Texture2D.h"
#include "../Camera.h"

using namespace SealEngine::Ui;

Panel::Panel(const Sprite* sprite) :IRenderer(sprite) {}

void Panel::OnGui(){
	if (Camera::mainCamera) Render(transform());
}

void Panel::Render(Transform* transform) const {
    float height = Camera::mainCamera->size;
    float width = height * (float)sprite->texture->width() * sprite->rect().size().x() / (sprite->texture->height() * sprite->rect().size().y());

    glPushMatrix();
    {
        glBindTexture(GL_TEXTURE_2D, sprite->texture->textureId());
        //glScalef(3, 3, 1);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        {
            const Rect rect = sprite->rect();

            glTexCoord2f(rect.minVertex().x(), rect.minVertex().y());
            glVertex2f(-width, height);

            glTexCoord2f(rect.maxVertex().x(), rect.minVertex().y());
            glVertex2f(width, height);

            glTexCoord2f(rect.maxVertex().x(), rect.maxVertex().y());
            glVertex2f(width, -height);

            glTexCoord2f(rect.minVertex().x(), rect.maxVertex().y());
            glVertex2f(-width, -height);
        }
        glEnd();
    }
    glPopMatrix();
}
