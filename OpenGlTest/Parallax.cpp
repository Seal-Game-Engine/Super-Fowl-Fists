#include "Parallax.h"

void Parallax::LateUpdate() {
    if (!Camera::mainCamera) return;

    _rect.SetMinVertex(
        _rect.minVertex().x() - direction.x() * speed * Time::deltaTime(),
        _rect.minVertex().y() + direction.y() * speed * Time::deltaTime()
    );

    _rect.SetMaxVertex(
        _rect.maxVertex().x() - direction.x() * speed * Time::deltaTime(),
        _rect.maxVertex().y() + direction.y() * speed * Time::deltaTime()
    );
    
    float height = 3;
    //float height = (float)ApplicationManager::height / 200;
    float width = height * (float)sprite->texture->width() * sprite->rect().size().x() / (sprite->texture->height() * sprite->rect().size().y());

    glPushMatrix();
    {
        glBindTexture(GL_TEXTURE_2D, sprite->texture->textureId());
        //glScalef(3, 3, 1);
        glColor3f(1.0, 1.0, 1.0);
        glBegin(GL_QUADS);
        {
            glTexCoord2f(_rect.minVertex().x(), _rect.minVertex().y());
            glVertex2f(-width, height);

            glTexCoord2f(_rect.maxVertex().x(), _rect.minVertex().y());
            glVertex2f(width, height);

            glTexCoord2f(_rect.maxVertex().x(), _rect.maxVertex().y());
            glVertex2f(width, -height);

            glTexCoord2f(_rect.minVertex().x(), _rect.maxVertex().y());
            glVertex2f(-width, -height);
        }
        glEnd();
    }
    glPopMatrix();
}

Parallax::Parallax(const Sprite* sprite, Vector2 direction, float speed) : sprite(sprite), direction(direction), speed(speed), _rect(sprite->rect()) {}

Parallax* Parallax::_Clone() const { return new Parallax(*this); }
