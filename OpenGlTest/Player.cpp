#include "Player.h"
#include "AssetManager.h"
#include <irrKlang/irrKlang.h>

#pragma comment(lib, "irrKlang.lib") // link with irrKlang.dll

Player::Player() {
	renderer._transform = &transform;
	renderer.sprite = &AssetManager::Hector_Run[1];
	animator.SetAnimatorController(&AssetManager::Hector_Controller);
	animator.renderer = &renderer;
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

void Player::Update() {
	if (Inputs::GetKeyDown(KeyCode::Space)) {
		Time::timeScale = 0;
	}
	if (Inputs::GetKeyUp(KeyCode::Space)) {
		Time::timeScale = 1;
	}
	if (Inputs::GetKey(KeyCode::W)) {
		transform.position += Vector2::up() * Time::deltaTime();
		animator.SetInteger("y", 1);
	}
	else if (Inputs::GetKey(KeyCode::S)) {
		transform.position += Vector2::down() * Time::deltaTime();
		animator.SetInteger("y", -1);
	}
	else {

	}
}



//void Player::Update() {
//
//	using namespace irrklang;
//	using namespace InputSystem;
//	if (Inputs::GetKeyDown(KeyCode::UpArrow)) {
//		//ISoundEngine* audioEngine = createIrrKlangDevice();
//		//audioEngine->play2D("PlasmaBlast.wav");
//		//audioEngine->drop();
//	}
//}