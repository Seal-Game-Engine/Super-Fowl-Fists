#include "Camera.h"
#include "Transform.h"
using namespace SealEngine;

Camera* Camera::mainCamera = nullptr;

Camera::Camera(Projection projection, float size) : projection(projection), size(size) {}

Vector3 Camera::ScreenToViewportPoint(Vector2 position){
	return Vector3(0,0,0);
}

Vector3 Camera::ScreenToWorldPoint(Vector2 position){
	GLdouble projectionMatrix[16];
	GLdouble modelViewMatrix[16];
	GLint viewPort[4];
	GLdouble winX, winY, winZ;
	GLdouble posX, posY, posZ;

	glGetDoublev(GL_PROJECTION_MATRIX, projectionMatrix);
	glGetDoublev(GL_MODELVIEW_MATRIX, modelViewMatrix);
	glGetIntegerv(GL_VIEWPORT, viewPort);

	winX = position.x();
	winY = viewPort[3] - position.y();
	glReadPixels(position.x(), viewPort[3] - position.y(), 1, 1, GL_DEPTH_COMPONENT, GL_FLOAT, &winZ);

	gluUnProject(winX, winY, winZ, modelViewMatrix, projectionMatrix, viewPort, &posX, &posY, &posZ);

	return Vector3((float)posX, (float)posY, (float)posZ) - transform()->position;
}

void Camera::Awake(){
	if (!mainCamera) mainCamera = this;
}
void Camera::OnDestroy() {
	if (mainCamera == this) mainCamera = nullptr;
}
