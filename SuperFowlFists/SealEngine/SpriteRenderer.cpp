#include "SpriteRenderer.h"
#include "Camera.h"
using namespace SealEngine;

SpriteRenderer::SpriteRenderer(const Sprite* sprite, bool flipX, bool flipY)
	: IRenderer(sprite), flipX(flipX), flipY(flipY) {}

void SpriteRenderer::Update() {
}

void SpriteRenderer::LateUpdate() {
	if (Camera::mainCamera) Render(transform());
}