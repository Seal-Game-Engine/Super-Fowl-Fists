#include "Player.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "Obstacle.h"
#include <cmath>

const std::array<const AnimatorController*, 2> Player::animatorControllers{ &AssetManager::MiniTikeMyson_Controller, &AssetManager::BigTikeMyson_Controller }; //change to small and big guy controller

void Player::Awake(){
	renderer = gameObject->GetComponent<SpriteRenderer>();
	animator = gameObject->GetComponent<Animator>();
}

void Player::Update() {
	float screenWidth = 340.0f;
	float screenHeight = 340.0f;

	float gravityDelayTime = .15f;
	const float gForce = 10.0f;
	Vector2 gravity = Vector2::down() * gForce * Time::deltaTime();
	if (Time::time() >= stopGravity)
		transform()->position += gravity;
	else transform()->position -= gravity * 1.5f;
	int x = Input::GetAxisRaw("Horizontal");
	Vector2 horizontalMovement = Vector2::right() * (float)x * _speed * Time::deltaTime();

	transform()->position += horizontalMovement;

	if (Input::GetKeyDown(KeyCode::UpArrow) || Input::GetKeyDown(KeyCode::W)) { animator->Play("Jump"); stopGravity = Time::time() + gravityDelayTime; }
	
	if (std::abs(transform()->position.x()) > (float)ApplicationManager::width / screenWidth) transform()->position -= horizontalMovement;
	if (transform()->position.y() < -1) transform()->position.Set(transform()->position.x(), -1, transform()->position.z());
	
	if (Input::GetKeyDown(KeyCode::Space)) {
		powerState = (PowerState)(((int)powerState + 1) % 2);
		animator->SetAnimatorController(animatorControllers[(int)powerState]);
	}

	if (Input::GetKeyDown(KeyCode::H)) {
		animator->Play("Punch");
	}
	animator->SetBool("isWalking", std::abs(x) > 0);
	if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());


	if(Input::GetKeyDown(KeyCode::R))
		if (!renderer->enabled)renderer->enabled = true;
}

void Player::LateUpdate() {}

void Player::OnCollisionEnter2D(Collision2D collision){
	if (collision.gameObject() == gameObject) return;

	renderer->enabled = false;
	for (auto& obstacle : FindObjectsByType<Obstacle>()) Destroy(*obstacle->gameObject);
	powerState = PowerState::Small;
	animator->SetAnimatorController(animatorControllers[(int)powerState]);
}

