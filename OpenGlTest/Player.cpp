#include "Player.h"
#include "AssetManager.h"
#include <windows.h>
#include <memory>
#include <chrono>

Player::Player() {
	renderer.sprite = &AssetManager::Hector_Run[0];
	runSpeed = 0;
	jumpSpeed = 0;
	actionTrigger = 0;
}

void Player::Awake() {
//	glEnable(GL_BLEND);
//	glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
}



void Player::Actions(int action) {
	switch (action) {
		case 0:
			break;
		default:
			break;
	}
}
std::unique_ptr<const int> idleFrames = std::unique_ptr<const int>(new int[4] {0, 4, 0, 8});
auto lastAnimatedFrame = std::chrono::high_resolution_clock::now();

void Player::LateUpdate() {
	static int frameId = 0;

	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lastAnimatedFrame).count() > 50) {
		renderer.sprite = &AssetManager::Hector_Run[idleFrames.get()[frameId++ % 4]];
		lastAnimatedFrame = std::chrono::high_resolution_clock::now();
	}
}

void Player::Update() {

	using namespace InputSystem;
	if (Inputs::GetKeyDown(KeyCode::UpArrow)) {
	}
}