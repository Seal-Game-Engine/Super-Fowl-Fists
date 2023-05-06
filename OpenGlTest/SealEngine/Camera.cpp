#include "Camera.h"
using namespace SealEngine;

Camera* Camera::mainCamera = nullptr;

Camera::Camera(Projection projection, float size) : projection(projection), size(size) {}

void Camera::Awake(){
	if (!mainCamera) mainCamera = this;
}
void Camera::OnDestroy() {
	if (mainCamera == this) mainCamera = nullptr;
}
