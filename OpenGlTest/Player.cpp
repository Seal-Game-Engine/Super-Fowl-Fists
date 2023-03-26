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
	static float frameId = 0;
	frameId += 15.0f * Time::deltaTime();
	renderer.sprite = &AssetManager::Hector_Run[idleFrames.get()[(int)frameId % 4]];

	if (Inputs::GetKeyDown(KeyCode::Space)) {
		Time::timeScale = 0;
	}
	if (Inputs::GetKeyUp(KeyCode::Space)) {
		Time::timeScale = 1;
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