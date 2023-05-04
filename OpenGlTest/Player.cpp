#include "Player.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "Obstacle.h"
#include <cmath>

const std::array<const AnimatorController*, 2> Player::animatorControllers{ &AssetManager::MiniTikeMyson_Controller, &AssetManager::BigTikeMyson_Controller }; //change to small and big guy controller

void Player::Awake(){
	renderer = gameObject->GetComponent<SpriteRenderer>();
	animator = gameObject->GetComponent<Animator>();
	rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Player::Update() {
	float screenWidth = 340.0f;
	float screenHeight = 340.0f;

	float gravityDelayTime = .15f;
	const float gForce = 10.0f;

	//Vector2 gravity = Vector2::down() * gForce * Time::deltaTime();

	//if (Time::time() >= stopGravity)
	//	transform()->position += gravity;
	//else transform()->position -= gravity * 1.5f;

	int x = Input::GetAxisRaw(Input::Axis::Horizontal);
	Vector2 horizontalMovement = Vector2::right();
	rigidbody->velocity = Vector2((float)x * _speed, rigidbody->velocity.y());

	if (Input::GetKeyDown(KeyCode::W) || Input::GetKeyDown(KeyCode::UpArrow)) { 
		animator->Play("Jump");
		rigidbody->AddForce(Vector2::up() * 5.0f, Rigidbody2D::ForceMode2D::Impulse);
		//stopGravity = Time::time() + gravityDelayTime; 
	}

	if (Input::GetKeyDown(KeyCode::Space)) {
		InvokeRepeating([&]() {
			powerState = (PowerState)(((int)powerState + 1) % 2);
			animator->SetAnimatorController(animatorControllers[(int)powerState]);
			}, 1, 1);
	}

	if (Input::GetKeyDown(KeyCode::H)) {
		animator->Play("Punch");
	}

	animator->SetBool("isWalking", std::abs(x) > 0);
	if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

void Player::LateUpdate() {}

void Player::OnCollisionEnter2D(Collision2D collision){
	/*if (collision.gameObject() == gameObject) return;

	renderer->enabled = false;
	for (auto& obstacle : Scene::FindObjectsByType<Obstacle>()) Destroy(*obstacle->gameObject);
	powerState = PowerState::Small;
	animator->SetAnimatorController(animatorControllers[(int)powerState]);*/
}

