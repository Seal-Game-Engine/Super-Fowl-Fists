#include "Player.h"
#include "Projectile.h"
#include "AssetManager.h"
#include <cmath>

void Player::Awake(){
	animator = gameObject->GetComponent<Animator>();
}

void Player::Update() {
	int x = (Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::LeftArrow)) && (Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::RightArrow)) ? 0
		: Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::LeftArrow) ? -1
		: Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::RightArrow) ? 1
		: 0;

	int y = Input::GetKey(KeyCode::W) || Input::GetKey(KeyCode::UpArrow) ? 1
		: Input::GetKey(KeyCode::S) || Input::GetKey(KeyCode::DownArrow) ? -1
		: 0;

	Vector2 horizontalMovement = Vector2::right() * (float)x * speed * Time::deltaTime();
	Vector2 verticalMovement = Vector2::up() * (float)y * speed * Time::deltaTime();
	transform()->position += horizontalMovement + verticalMovement;
	
	if (std::abs(transform()->position.x()) > (float)ApplicationManager::width / 280.0f) transform()->position -= horizontalMovement;
	if (std::abs(transform()->position.y()) > (float)ApplicationManager::height / 280.0f) transform()->position -= verticalMovement;

	animator->SetInteger("x", x);


	if (Input::GetKey(KeyCode::Space) && Time::time() >= _nextFire) {
		Instantiate(AssetManager::ProjectileObject_Blue, transform()->position + Vector2::up() * 0.5f, Transform());
		_nextFire = Time::time() + 0.15f;
	}
}

Player* Player::Clone_impl() const { return new Player(*this); }
