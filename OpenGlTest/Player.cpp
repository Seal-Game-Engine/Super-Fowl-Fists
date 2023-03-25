#include "Player.h"
#include "AssetManager.h"
#include <irrKlang/irrKlang.h>

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

Player::Player() {
	renderer.sprite = &AssetManager::Hector_Run[1];
	runSpeed = 0;
	jumpSpeed = 0;
	actionTrigger = 0;


}

void Player::Actions(int action) {
	switch (action) {
		case 0:
			break;
		default:
			break;
	}
}

void Player::LateUpdate() {
	static int frameId = 0;

	if (std::chrono::duration_cast<std::chrono::milliseconds>(std::chrono::high_resolution_clock::now() - lastAnimatedFrame).count() > 50) {
		renderer.sprite = &AssetManager::Hector_Run[idleFrames.get()[frameId++ % 4]];
		lastAnimatedFrame = std::chrono::high_resolution_clock::now();
	}
}



void Player::Update() {

	using namespace irrklang;
	using namespace InputSystem;
	if (Inputs::GetKeyDown(KeyCode::UpArrow)) {
		ISoundEngine* audioEngine = createIrrKlangDevice();
		audioEngine->play2D("PlasmaBlast.wav");
		//audioEngine->drop();
	}
}