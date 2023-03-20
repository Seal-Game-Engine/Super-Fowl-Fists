#include "Player.h"
#include "AssetManager.h"
#include <windows.h>

Player::Player()
	: textureLoader(AssetManager::Hector_Run) {
	runSpeed = 0;
	jumpSpeed = 0;
	actionTrigger = 0;
}

void Player::Draw() {
	//textureLoader.Bind();
	glTranslated(0, 0, -2);
	glColor3f(1, 1, 1);
	glBegin(GL_POLYGON);
	{
		Vector3* vertices = new Vector3[4]{
			Vector3(-0.5f, -0.5f, -1),
			Vector3(0.5f, -0.5f, -1),
			Vector3(0.5f, 0.5f, -1),
			Vector3(-0.5f, 0.5f, -1)
		};

		float xMin = 0, xMax = 1.0 / 4, yMin = 0, yMax = 1.0 / 4;

		glTexCoord2f(xMin, yMax);//top left
		glVertex3f(vertices[0].x(), vertices[0].y(), vertices[0].z());

		glTexCoord2f(xMax, yMax);//top right
		glVertex3f(vertices[1].x(), vertices[1].y(), vertices[1].z());

		glTexCoord2f(xMax, yMin);//bottom left
		glVertex3f(vertices[2].x(), vertices[2].y(), vertices[2].z());

		glTexCoord2f(xMin, yMin);//bottom right
		glVertex3f(vertices[3].x(), vertices[3].y(), vertices[3].z());
	}
	glEnd();
}

void Player::Init() {
	glEnable(GL_BLEND);
	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

	int vfrm = 4, hfrm = 4;
}

void Player::Actions(int action) {
	switch (action) {
		case 0:
			break;
		default:
			break;
	}
}

void Player::Update() {
	using namespace InputSystem;
	if (Inputs::GetKeyDown(VK_UP)) {
	}
}