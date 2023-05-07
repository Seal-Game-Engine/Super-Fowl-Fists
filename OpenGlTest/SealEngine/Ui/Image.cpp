#include "Image.h"
#include "../Camera.h"

using namespace SealEngine::Ui;

Image::Image(const Sprite* sprite) :IRenderer(sprite) {}

void Image::OnGui() {
	if (Camera::mainCamera) Render(transform());
}
