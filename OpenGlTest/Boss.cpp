#include "Boss.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "Obstacle.h"
#include <cmath>

//const std::array<const AnimatorController*, 2> Player::animatorControllers{ &AssetManager::MiniTikeMyson_Controller, &AssetManager::BigTikeMyson_Controller }; //change to small and big guy controller

void Boss::Awake() {
	renderer = gameObject->GetComponent<SpriteRenderer>();
	animator = gameObject->GetComponent<Animator>();
	rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Boss::Update() {
	//int x = Input::GetAxisRaw(Input::Axis::Horizontal);
	//Vector2 horizontalMovement = Vector2::right();
	//rigidbody->velocity = Vector2((float)x * _speed, rigidbody->velocity.y());

	//if (_canJump && (Input::GetKeyDown(KeyCode::W) || Input::GetKeyDown(KeyCode::UpArrow))) {
	//	animator->Play("Jump");
	//	rigidbody->AddForce(Vector2::up() * 5.0f, Rigidbody2D::ForceMode2D::Impulse);
	//	_canJump = false;
	//}

	//if (Input::GetKeyDown(KeyCode::Space)) {
	//	InvokeRepeating([&]() {
	//		powerState = (PowerState)(((int)powerState + 1) % 2);
	//	animator->SetAnimatorController(animatorControllers[(int)powerState]);
	//		}, 1, 1);
	//}
	if (Input::GetKeyDown(KeyCode::Q)) {
		animator->SetInteger("move",1);
		//animator->Play("BombId");
	}
	if (Input::GetKeyDown(KeyCode::W)) {
		animator->SetInteger("move", 2);
	}

	//animator->SetBool("isWalking", std::abs(x) > 0);
	//animator->SetBool("isJumping", !_canJump);
	//if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

//void Boss::OnCollisionEnter2D(Collision2D collision) {
//	if (collision.gameObject()->CompareTag("Ground")) _canJump = true;
//}