#include "Boss.h"
#include "Prefab.h"
#include "Projectile.h"
#include "Hitbox.h"
#include <cmath>

Boss::Boss(const float hp) :Entity(hp) {
	faction = Factions::Faction2;
}

void Boss::Awake() {
	_renderer = gameObject->GetComponent<SpriteRenderer>();
	_animator = gameObject->GetComponent<Animator>();
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
	_audioSource = gameObject->GetComponent<AudioSource>();

	Invoke([&] {
		_rigidbody->bodyType = Rigidbody2D::BodyType::Kinematic;
		_rigidbody->velocity = Vector2::zero();
		}, 1);

	//temp
	transform()->scale.Set(transform()->scale.x() * -1, transform()->scale.y(), transform()->scale.z());

	_audioSource->clip = "Assets/Sounds/RobotStartUp.wav";
	_audioSource->Play();
}

void Boss::Update() {
	_rigidbody->velocity = Vector2(-0.05, _rigidbody->velocity.y());

	switch (actionState) {
	case ActionState::Charge:
		break;
	case ActionState::BombAttack:
		BombAttack();
		
		break;
	case ActionState::ChompAttack:
		ChompAttack();
		//_audioSource->clip = "Assets/Sounds/RobotChomp.wav";
		//_audioSource->Play();
		break;
	}


	if (Time::time() >= _nextActionTime) {
		
		
	}

	if (Input::GetKeyDown(KeyCode::W)) {
		_animator->SetInteger("move", 2);
	}
	if (Input::GetKeyDown(KeyCode::E)) {
		_animator->SetInteger("move", 3);
		//_audioSource->clip = "Assets/Sounds/RobotMoving.wav";
		//_audioSource->Play();
	}
	if (Input::GetKeyDown(KeyCode::T)) {
		_animator->Play("Hurt");


	}
	//animator->SetBool("isWalking", std::abs(x) > 0);
	//animator->SetBool("isJumping", !_canJump);
	//if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

void Boss::SetState(ActionState state){
	OnStateExit();
	actionState = state;
	OnStateEnter();
}

void Boss::OnStateEnter(){
	switch (actionState) {
	case ActionState::Charge:
		_nextActionTime = Time::time() + rand() % 3 + 2;
		break;
	case ActionState::BombAttack:
		_nextActionTime = Time::time() + _bombAttackDuration;
		break;
	}
}

void Boss::OnStateExit() {
	switch (actionState) {
	case ActionState::Charge:
		switch (rand() % 2) {
		case 0:
			_animator->SetInteger("move", 1);
			Invoke([&] { SetState(ActionState::BombAttack); }, 3.2f);
			break;
		case 1: 
			_animator->SetInteger("move", 2);
			Invoke([&] { SetState(ActionState::ChompAttack); }, 3.2f);
			break;
		}
		break;

	case ActionState::BombAttack:
	case ActionState::ChompAttack:
		_animator->SetInteger("move", 0);
		Invoke([&] { SetState(ActionState::Charge); }, 0.8f);
		break;
	}
}

void Boss::Charge(){
	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}

void Boss::BombAttack() {
	if (Time::time() >= _nextBombTime) {
		GameObject* bomb = InstantiateT(Prefab::ProjectileObject_Blue, transform()->position + Vector2(transform()->scale.x() + 0.9, -0.125) * 1);
		bomb->GetComponent<Projectile>()->Initialize(Vector2(transform()->scale.x(), -0.5f), gameObject);
		bomb->GetComponent<Hitbox>()->data.entity = this;

		_audioSource->clip = "Assets/Sounds/RobotHit.wav";
		//_audioSource->clip = "Assets/Sounds/Blaster.wav";
		_audioSource->Play();

		_nextBombTime = Time::time() + _bombAttackCooldown;
	}

	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}

void Boss::ChompAttack(){
	if (Time::time() >= _nextBombTime) {
		//GameObject* bomb = InstantiateT(Prefab::ProjectileObject_Blue, transform()->position + Vector2(transform()->scale.x() + 0.9, -0.125) * 1);
		//bomb->GetComponent<Projectile>()->Initialize(Vector2(transform()->scale.x(), -0.5f), gameObject);
		//bomb->GetComponent<Hitbox>()->data.entity = this;

		//_audioSource->clip = "Assets/Sounds/RobotHit.wav";
		////_audioSource->clip = "Assets/Sounds/Blaster.wav";
		//_audioSource->Play();

		//_nextBombTime = Time::time() + _bombAttackCooldown;
	}

	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}
