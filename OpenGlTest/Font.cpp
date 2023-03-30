#include "Font.h"
#include <freeglut/freeglut.h>
#include "AssetManager.h"
#include <array>

void Font::RenderText(std::string text, Vector2 position, float scale) {
    glPushMatrix();
    {
        glTranslated(position.x(), position.y(), 0);
        //glRotatef(transform().rotation.x(), 1, 0, 0);
        //glRotatef(transform().rotation.y(), 0, 1, 0);
        //glRotatef(transform().rotation.z(), 0, 0, 1);
        //glScalef(transform().scale.x(), transform().scale.y(), transform().scale.z());

        glBindTexture(GL_TEXTURE_2D, AssetManager::Font.textureId());
        glColor4f(1, 1, 1, 1);

        //Rendering
        glBegin(GL_QUADS);
        {
            //std::vector<Vector2> vertices = sprite->vertices();

            std::array<Vector2, 4> vertices{
                Vector2(-0.5f, 0.5f),
                Vector2(0.5f, 0.5f),
                Vector2(0.5f, -0.5f),
                Vector2(-0.5f, -0.5f),
            };

            for (auto c : text) {
                Sprite ch = AssetManager::Font[(int)c];
                Rect rect = ch.rect;

                // Vertex3f for 3D
                glTexCoord2f(rect.minVertex().x(), rect.minVertex().y());
                glVertex2f(vertices[0].x(), vertices[0].y());

                glTexCoord2f(rect.maxVertex().x(), rect.minVertex().y());
                glVertex2f(vertices[1].x(), vertices[1].y());

                glTexCoord2f(rect.maxVertex().x(), rect.maxVertex().y());
                glVertex2f(vertices[2].x(), vertices[2].y());

                glTexCoord2f(rect.minVertex().x(), rect.maxVertex().y());
                glVertex2f(vertices[3].x(), vertices[3].y());

                vertices[0] += Vector2::right();
                vertices[1] += Vector2::right();
                vertices[2] += Vector2::right();
                vertices[3] += Vector2::right();
            }
        }
        glEnd();

        glBindTexture(GL_TEXTURE_2D, 0);
    }
    glPopMatrix();
}
