#include "Player.h"
#include "Projectile.h"
#include "Prefab.h"
#include "Hitbox.h"
#include <cmath>
#include "EventManagers/GameEventManager.h"

//void Player::TakeDamage(float damage)
//{
//}

Player::InputData Player::GetInputData(ControlScheme controlScheme) {
	switch (controlScheme) {
	case ControlScheme::Solo:
		return InputData{
			Input::GetAxisRaw(Input::Axis::Horizontal),
			Input::GetKeyUp(KeyCode::A) || Input::GetKeyUp(KeyCode::D) || Input::GetKeyUp(KeyCode::LeftArrow) || Input::GetKeyUp(KeyCode::RightArrow),

			Input::GetKeyDown(KeyCode::W) || Input::GetKeyDown(KeyCode::UpArrow),

			Input::GetKeyDown(KeyCode::R) || Input::GetKeyDown(KeyCode::Period),

			Input::GetKeyDown(KeyCode::T) || Input::GetKeyDown(KeyCode::Comma)
		};
	case ControlScheme::Player1:
		return InputData{
			(float)(Input::GetKey(KeyCode::A) ? -1 : 0) + (Input::GetKey(KeyCode::D) ? 1 : 0),
			Input::GetKeyUp(KeyCode::A) || Input::GetKeyUp(KeyCode::D),

			Input::GetKeyDown(KeyCode::W),

			Input::GetKeyDown(KeyCode::R),

			Input::GetKeyDown(KeyCode::T)
		};
	case ControlScheme::Player2:
		return InputData{
			(float)(Input::GetKey(KeyCode::LeftArrow) ? -1 : 0) + (Input::GetKey(KeyCode::RightArrow) ? 1 : 0),
			Input::GetKeyUp(KeyCode::LeftArrow) || Input::GetKeyUp(KeyCode::RightArrow),

			Input::GetKeyDown(KeyCode::UpArrow),

			Input::GetKeyDown(KeyCode::Period),

			Input::GetKeyDown(KeyCode::Comma)
		};
	}
}

void Player::OnDamageTaken(DamageData data, Vector2 knockbackDirection){
	if (!isAlive())return;

	switch (_powerState) {
	case PowerState::Mini:
		_animator->Play("Mini_Hurt"); 
		_audioSource->clip = "Assets/Sounds/Hit.wav";
		_audioSource->Play();
		break;
	case PowerState::Big: 
		_animator->Play("Big_Hurt"); 
		_audioSource->clip = "Assets/Sounds/Hit.wav";
		_audioSource->Play();
		break;
	}
	Entity::OnDamageTaken(data, knockbackDirection);
	GameEventManager::instance->UpdateUi();
}

void Player::OnDeath() {
	SetPowerState(PowerState::Mini);
	_animator->Play("Mini_Die");
	_audioSource->clip = "Assets/Sounds/Death.wav";
	_audioSource->Play();
	Invoke([&] {
		_rigidbody->enabled = false;
		_collider->enabled = false;
		}, 1);
}

Player::Player(const float hp) :Entity(hp) {
	faction = Factions::Faction1;
}

void Player::Awake() {
	_animator = gameObject->GetComponent<Animator>();
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
	_collider = gameObject->GetComponent<CircleCollider2D>();
	_audioSource = gameObject->GetComponent<AudioSource>();

	_collider->radius = miniColliderRadius;
	//_collider->offset = miniCollider.offset;

	GameObject hitboxObject = GameObject(
		"Hitbox", "Hitbox",
		std::vector<std::shared_ptr<MonoBehaviour>>{
		std::make_shared<BoxCollider2D>(Vector2(1, 1), true),
			std::make_shared<Hitbox>(DamageData{ Factions::Faction1, 2, 2, this }),
			std::make_shared<Rigidbody2D>(Rigidbody2D::BodyType::Dynamic, 1, 0),
	});
	hitbox = InstantiateT(hitboxObject);
	hitbox->SetActive(false);
}

void Player::Update() {
	if (!isAlive()) return;

	InputData inputData = GetInputData(controlScheme);

	_rigidbody->velocity = Vector2(
		inputData.horizontalUp ? 0 : inputData.horizontal * _speed, 
		_rigidbody->velocity.y()
	);

	if (inputData.jumpDown && _canJump) { 
		switch (_powerState) {
		case PowerState::Mini: 
			_animator->Play("Mini_Jump"); 
			_audioSource->clip = "Assets/Sounds/LightJump.wav";
			_audioSource->Play();
			break;
		case PowerState::Big: 
			_animator->Play("Big_Jump"); 
			_audioSource->clip = "Assets/Sounds/HeavyJump.wav";
			_audioSource->Play();
			break;
		}
		_rigidbody->AddForce(Vector2::up() * 5.0f, Rigidbody2D::ForceMode2D::Impulse);
		_canJump = false;
	}

	if (inputData.juiceDown) SetPowerState((PowerState)(((int)_powerState + 1) % 2));

	if (inputData.attackDown && Time::time() >= _nextAttack) {
		switch (_powerState) {
		case PowerState::Mini: Attack_Mini(); break;
		case PowerState::Big: Attack_Big(); break;
		}
	}

	_animator->SetBool("isWalking", std::abs(inputData.horizontal) > 0);
	_animator->SetBool("isJumping", !_canJump);
	if (std::abs(inputData.horizontal) > 0) transform()->scale.Set(inputData.horizontal > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
	if(_rigidbody->velocity.y() > _maxVerticalVelocity) _rigidbody->velocity = Vector2(_rigidbody->velocity.x(), _maxVerticalVelocity);
}

void Player::OnCollisionEnter2D(Collision2D collision) {
	if (collision.gameObject()->CompareTag("Ground")) _canJump = true;
}

void Player::OnCollisionStay2D(Collision2D collision) {
	//if (collision.gameObject()->CompareTag("Ground")) _canJump = true;
}

void Player::OnCollisionExit2D(Collision2D collision){

}

void Player::Attack_Mini(){
	_animator->Play("Mini_Attack"); 
	_nextAttack = Time::time() + 0.3f;
	_audioSource->clip = "Assets/Sounds/Blaster.wav"; //Blaster sound 
	_audioSource->Play();
}

void Player::Attack_Big() {
	_animator->Play("Big_Punch");
	_nextAttack = Time::time() + 0.3f;
	_audioSource->clip = "Assets/Sounds/Punch.wav"; //Punch sound 
	_audioSource->Play();

	hitbox->transform->position = transform()->position + Vector2::right() * transform()->scale.x();
	hitbox->SetActive(true);
	Invoke([&] {
		hitbox->SetActive(false); 
		hitbox->transform->position = Vector2(0, -100);
		//hitbox->GetComponent<Rigidbody2D>()->_activeCollisions.clear();
		}, 0.1f);
}

void Player::SetPowerState(PowerState powerState) {
	_powerState = powerState;

	switch (_powerState) {
	case PowerState::Mini:
		_animator->Play("Mini_Idle");
		_collider->radius = miniColliderRadius;
		_maxVerticalVelocity = 6;
		_audioSource->clip = "Assets/Sounds/SizeDown.wav";
		_audioSource->Play();
		break;
	case PowerState::Big:
		_animator->Play("Big_Idle");
		_collider->radius = bigColliderRadius;
		_maxVerticalVelocity = 5;
		_audioSource->clip = "Assets/Sounds/SizeUp.wav";
		_audioSource->Play();
		break;
	}
}

//Player::Player(ControlScheme controlScheme) :_controlScheme(controlScheme) {}
