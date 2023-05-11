#include "Robot.h"
#include "Projectile.h"
#include "Hitbox.h"

void Robot::OnDeath() {
	SetState(ActionState::Charge);
	Boss::OnDeath();
}

Robot::Robot(const float hp) :Boss(hp) {}

void Robot::Awake(){
	Boss::Awake();
	_audioSource->clip = "Assets/Sounds/RobotStartUp.wav";
	_audioSource->Play();
	SetState(ActionState::Charge);
}

void Robot::Update() {
	if (!isAlive()) return;

	_rigidbody->velocity = Vector2(-0.05, _rigidbody->velocity.y());

	switch (actionState) {
	case ActionState::Charge: Charge(); break;
	case ActionState::BombAttack: BombAttack(); break;
	case ActionState::ChompAttack: ChompAttack(); break;
	}

	//animator->SetBool("isWalking", std::abs(x) > 0);
	//animator->SetBool("isJumping", !_canJump);
	//if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}


void Robot::SetState(ActionState state) {
	OnStateExit();
	actionState = state;
	OnStateEnter();
}

void Robot::OnStateEnter() {
	switch (actionState) {
	case ActionState::Charge:
		_nextActionTime = Time::time() + rand() % 3 + 2;
		break;
	case ActionState::BombAttack:
		_nextActionTime = Time::time() + _bombAttackDuration;
		break;
	case ActionState::ChompAttack:
		_nextActionTime = Time::time() + _chompAttackDuration;
		break;
	}
}

void Robot::OnStateExit() {
	switch (actionState) {
	case ActionState::Charge:
		switch (rand() % 2) {
		case 0:
			_animator->SetInteger("move", 1);
			Invoke([&] { SetState(ActionState::BombAttack); }, 3.0f);
			break;
		case 1:
			_animator->SetInteger("move", 2);
			Invoke([&] { SetState(ActionState::ChompAttack); }, 3.0f);
			break;
		}
		break;

	case ActionState::BombAttack:
	case ActionState::ChompAttack:
		_animator->SetInteger("move", 0);
		_animator->Play("Close");
		Invoke([&] { SetState(ActionState::Charge); }, 0.8f);
		break;
	}
}

void Robot::Charge() {
	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}

void Robot::BombAttack() {
	if (Time::time() >= _nextBombTime) {

		GameObject* bomb = _bombPool.Get();
		bomb->transform->position = transform()->position + Vector2(transform()->scale.x() + 0.9, -0.125) * 1;
		bomb->GetComponent<Projectile>()->Initialize(Vector2(transform()->scale.x(), -0.5f), gameObject, &_bombPool);

		_audioSource->clip = "Assets/Sounds/RobotHit.wav";
		_audioSource->Play();

		_nextBombTime = Time::time() + _bombAttackCooldown;
	}

	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}

void Robot::ChompAttack() {
	if (Time::time() >= _nextChompTime) {

		std::array<Vector2, 5> directions{
			Vector2::right() * transform()->scale.x() + Vector2::down() * 0.4f,
			Vector2::right() * transform()->scale.x() + Vector2::down() * 0.2f,
			Vector2::down() + Vector2::left(),
			Vector2::right() * transform()->scale.x() * 0.2f + Vector2::down(),
			Vector2::down(),
		};
		for (auto& direction : directions) {
			GameObject* projectile = _projectilePool.Get();
			projectile->transform->position = transform()->position + direction * 0.25f;
			projectile->GetComponent<Projectile>()->Initialize(direction, gameObject, &_projectilePool);
			projectile->GetComponent<Hitbox>()->data.faction = faction;
			projectile->GetComponent<Hitbox>()->data.entity = this;
		}

		_audioSource->clip = "Assets/Sounds/Blaster.wav";
		_audioSource->Play();

		_nextChompTime = Time::time() + _chompAttackCooldown;
	}

	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}
