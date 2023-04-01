#include "Parallax.h"
#include "AssetManager.h"
#include "ApplicationManager.h"

Parallax::Parallax() : sprite(AssetManager::SpaceBackground[0]) {}

void Parallax::Update() {
    float height = (float)ApplicationManager::height / 200;
    float width = (float)sprite.texture->width() / sprite.texture->height() * height;
    glPushMatrix();
    {
        glBindTexture(GL_TEXTURE_2D, sprite.texture->textureId());
        //glScalef(3, 3, 1);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        {
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

void Parallax::Scroll(Vector2 direction){
    rect.SetMinVertex(
        rect.minVertex().x() + direction.x() * speed * Time::deltaTime(),
        rect.minVertex().y() + direction.y() * speed * Time::deltaTime()
    );

    rect.SetMaxVertex(
        rect.maxVertex().x() + direction.x() * speed * Time::deltaTime(),
        rect.maxVertex().y() + direction.y() * speed * Time::deltaTime()
    );
}
