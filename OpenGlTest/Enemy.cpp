#include "Enemy.h"

void Enemy::Draw()
{
	glPushMatrix();
	{
		glTranslated(transform.position.x(), transform.position.y(), transform.position.z());
		glRotatef(transform.rotation.x(), 1, 0, 0);
		glRotatef(transform.rotation.y(), 0, 1, 0);
		glRotatef(transform.rotation.z(), 0, 0, 1);
		
		glScalef(transform.scale.x(), transform.scale.y(), transform.scale.z());

		//Rendering
		glBegin(GL_POLYGON);
		{
			Vector3* vertices = new Vector3[4]{
			Vector3(-0.5f, -0.5f, -1),
			Vector3(0.5f, -0.5f, -1),
			Vector3(0.5f, 0.5f, -1),
			Vector3(-0.5f, 0.5f, -1)
			};

			float xMin = 0, xMax = 1.0 / 4, yMin = 0, yMax = 1.0 / 4;
			
			// Vertex3f for 3D
			glTexCoord2f(xMin, yMin);
			glVertex2f(1, 1); 
			glTexCoord2f(xMax, yMin);
			glVertex2f(1, 1);
			glTexCoord2f(xMax, yMax);
			glVertex2f(1, 1);
			glTexCoord2f(xMin, yMax);
			glVertex2f(1, 1);
		}
		glEnd();
	}
	glPopMatrix();
}

void Enemy::Init(char* fileName, int vframe, int hframe)
{
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	int vfrm = 4, hfrm = 4;

	textureLoader->Load(fileName, tex);
}

void Enemy::Update()
{
}
