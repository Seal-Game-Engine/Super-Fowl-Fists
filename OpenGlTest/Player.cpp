#include "Player.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "LandingScene.h"
#include <cmath>

void Player::Update() {
	if (!animator) animator = gameObject->GetComponent<Animator>();

	int x = (Inputs::GetKey(KeyCode::A) || Inputs::GetKey(KeyCode::LeftArrow)) && (Inputs::GetKey(KeyCode::D) || Inputs::GetKey(KeyCode::RightArrow)) ? 0
		: Inputs::GetKey(KeyCode::A) || Inputs::GetKey(KeyCode::LeftArrow) ? -1
		: Inputs::GetKey(KeyCode::D) || Inputs::GetKey(KeyCode::RightArrow) ? 1
		: 0;

	int y = Inputs::GetKey(KeyCode::W) || Inputs::GetKey(KeyCode::UpArrow) ? 1
		: Inputs::GetKey(KeyCode::S) || Inputs::GetKey(KeyCode::DownArrow) ? -1
		: 0;

	Vector2 horizontalMovement = Vector2::right() * (float)x * speed * Time::deltaTime();
	Vector2 verticalMovement = Vector2::up() * (float)y * speed * Time::deltaTime();
	transform()->position += horizontalMovement + verticalMovement;
	if (std::abs(transform()->position.x()) > (float)ApplicationManager::width / 280.0f) transform()->position -= horizontalMovement;
	if (std::abs(transform()->position.y()) > (float)ApplicationManager::height / 280.0f) transform()->position -= verticalMovement;

	animator->SetInteger("x", x);


	static float nextFire = 0;
	if (Inputs::GetKey(KeyCode::Space) && Time::time() >= nextFire) {
		LandingScene::projectiles.push_back(std::make_unique<Projectile>(transform()->position + Vector2::up() * 0.5f));
		nextFire = Time::time() + 0.15f;
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
