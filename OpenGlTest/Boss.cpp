#include "Boss.h"
#include "Prefab.h"
#include "Projectile.h"
#include "Hitbox.h"
#include <cmath>

//const std::array<const AnimatorController*, 2> Player::animatorControllers{ &AssetManager::MiniTikeMyson_Controller, &AssetManager::BigTikeMyson_Controller }; //change to small and big guy controller



void Boss::Awake() {
	_renderer = gameObject->GetComponent<SpriteRenderer>();
	_animator = gameObject->GetComponent<Animator>();
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();

	Invoke([&] { 
		_rigidbody->bodyType = Rigidbody2D::BodyType::Kinematic; 
		_rigidbody->velocity = Vector2::zero();
		}, 1);

	//temp
	transform()->scale.Set(transform()->scale.x() * -1, transform()->scale.y(), transform()->scale.z());
}

void Boss::Update() {
	_rigidbody->velocity = Vector2(-0.05, _rigidbody->velocity.y());

	switch (actionState) {
	case ActionState::None:

		BeginBombAttack();
		actionState = ActionState::Idle;
		break;
	case ActionState::Idle:
		break;
	case ActionState::BombAttack:
		BombAttack();
		break;
	case ActionState::ChompAttack:
		break;
	}


	if (Time::time() >= _nextActionTime) {
		
		
	}

	if (Input::GetKeyDown(KeyCode::W)) {
		_animator->SetInteger("move", 2);
	}
	if (Input::GetKeyDown(KeyCode::E)) {
		_animator->SetInteger("move", 3);
	}
	if (Input::GetKeyDown(KeyCode::T)) {
		_animator->Play("Hurt");
	}
	//animator->SetBool("isWalking", std::abs(x) > 0);
	//animator->SetBool("isJumping", !_canJump);
	//if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

void Boss::BeginBombAttack(){
	_animator->SetInteger("move", 1);
	Invoke([&] {
		_nextActionTime = Time::time() + _bombAttackDuration;
		actionState = ActionState::BombAttack;
		}, 3.2f);
}

void Boss::BombAttack(){
	if (Time::time() >= _nextBombTime) {
		GameObject* bomb = InstantiateT(Prefab::ProjectileObject_Blue, transform()->position + Vector2(transform()->scale.x(), -0.125) * 1);
		bomb->GetComponent<Projectile>()->Initialize(Vector2(transform()->scale.x(), 0), gameObject);
		bomb->GetComponent<Hitbox>()->data.entity = this;

		_nextBombTime = Time::time() + _bombAttackCooldown;
	}

	if (Time::time() >= _nextActionTime) {
		actionState = ActionState::Idle;
		_animator->SetInteger("move", 0);
		Invoke([&] {
			actionState = ActionState::None;
			}, 0.8f);
	}
}
