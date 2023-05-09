#include "Player.h"
#include "Projectile.h"
#include "Prefab.h"
#include <cmath>

//void Player::TakeDamage(float damage)
//{
//}

Player::InputData Player::GetInputData(ControlScheme controlScheme) {
	switch (controlScheme) {
	case ControlScheme::Solo:
		return InputData{
			Input::GetAxisRaw(Input::Axis::Horizontal),
			Input::GetAxisRaw(Input::Axis::Vertical),
			(
				Input::GetKeyUp(KeyCode::W) || Input::GetKeyUp(KeyCode::A) || Input::GetKeyUp(KeyCode::S) || Input::GetKeyUp(KeyCode::D) ||
				Input::GetKeyUp(KeyCode::UpArrow) || Input::GetKeyUp(KeyCode::DownArrow) || Input::GetKeyUp(KeyCode::LeftArrow) || Input::GetKeyUp(KeyCode::RightArrow)
			),

		};
	case ControlScheme::Player1:
		return InputData{
			(float)(Input::GetKey(KeyCode::A) ? -1 : 0) + (Input::GetKey(KeyCode::D) ? 1 : 0),
			(float)(Input::GetKey(KeyCode::W) ? 1 : 0) + (Input::GetKey(KeyCode::S) ? -1 : 0),
			Input::GetKeyUp(KeyCode::W) || Input::GetKeyUp(KeyCode::A) || Input::GetKeyUp(KeyCode::S) || Input::GetKeyUp(KeyCode::D),

		};
	case ControlScheme::Player2:
		return InputData{
			(float)(Input::GetKey(KeyCode::LeftArrow) ? -1 : 0) + (Input::GetKey(KeyCode::RightArrow) ? 1 : 0),
			(float)(Input::GetKey(KeyCode::UpArrow) ? 1 : 0) + (Input::GetKey(KeyCode::DownArrow) ? -1 : 0),
			Input::GetKeyUp(KeyCode::UpArrow) || Input::GetKeyUp(KeyCode::DownArrow) || Input::GetKeyUp(KeyCode::LeftArrow) || Input::GetKeyUp(KeyCode::RightArrow),

		};
	}
}

void Player::Awake(){
	_renderer = gameObject->GetComponent<SpriteRenderer>();
	_animator = gameObject->GetComponent<Animator>();
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Player::Update() {
	int x = Input::GetAxisRaw(Input::Axis::Horizontal);
	Vector2 horizontalMovement = Vector2::right();
	_rigidbody->velocity = Vector2((float)x * _speed, _rigidbody->velocity.y());

	if (_canJump && (Input::GetKeyDown(KeyCode::W) || Input::GetKeyDown(KeyCode::UpArrow))) { 
		_animator->Play("Jump");
		_rigidbody->AddForce(Vector2::up() * 5.0f, Rigidbody2D::ForceMode2D::Impulse);
		_canJump = false;
	}

	if (Input::GetKeyDown(KeyCode::Space)) {
		InvokeRepeating([&]() {
			_powerState = (PowerState)(((int)_powerState + 1) % 2);
			//_animator->SetAnimatorController(animatorControllers[(int)_powerState]);
			}, 1, 1);
	}

	if (Input::GetKeyDown(KeyCode::H)) {
		_animator->Play("Punch");
	}

	_animator->SetBool("isWalking", std::abs(x) > 0);
	_animator->SetBool("isJumping", !_canJump);
	if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

void Player::OnCollisionEnter2D(Collision2D collision) {
	if (collision.gameObject()->CompareTag("Ground")) _canJump = true;
}

void Player::OnCollisionStay2D(Collision2D collision) {
	
}

void Player::OnCollisionExit2D(Collision2D collision){

}
