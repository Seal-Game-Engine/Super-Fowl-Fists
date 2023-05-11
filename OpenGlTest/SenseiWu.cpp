#include "SenseiWu.h"
#include "Projectile.h"
#include "Hitbox.h"

void SenseiWu::OnDeath() {
	SetState(ActionState::Idle);
	Boss::OnDeath();
}

SenseiWu::SenseiWu(const float hp) :Boss(hp) {}

void SenseiWu::Awake() {
	Boss::Awake();
	//_audioSource->clip = "Assets/Sounds/RobotStartUp.wav";
	//_audioSource->Play();
	SetState(ActionState::Idle);
}

void SenseiWu::Update() {
	if (!isAlive()) return;

	_rigidbody->velocity = Vector2(-0.05, _rigidbody->velocity.y());

	switch (actionState) {
	case ActionState::Idle: Idle(); break;
	case ActionState::FireballAttack: FireballAttack(); break;
	case ActionState::StudentAttack: StudentAttack(); break;
	}

	//animator->SetBool("isWalking", std::abs(x) > 0);
	//animator->SetBool("isJumping", !_canJump);
	//if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());
}

void SenseiWu::SetState(ActionState state) {
	OnStateExit();
	actionState = state;
	OnStateEnter();
}

void SenseiWu::OnStateEnter() {
	switch (actionState) {
	case ActionState::Idle:
		_nextActionTime = Time::time() + rand() % 3 + 2;
		break;
	case ActionState::FireballAttack:
		_nextActionTime = Time::time() + _fireballAttackDuration;
		break;
	case ActionState::StudentAttack:
		_nextActionTime = Time::time() + _studentAttackDuration;
		break;
	}
}

void SenseiWu::OnStateExit() {
	switch (actionState) {
	case ActionState::Idle:
		switch (rand() % 2) {
		case 0:
			_animator->SetInteger("move", 1);
			Invoke([&] { SetState(ActionState::FireballAttack); }, 0.1f);
			break;
		case 1:
			_animator->SetInteger("move", 2);
			Invoke([&] { SetState(ActionState::StudentAttack); }, 0.1f);
			break;
		}
		break;

	case ActionState::FireballAttack:
	case ActionState::StudentAttack:
		_animator->SetInteger("move", 0);
		_animator->Play("Close");
		Invoke([&] { SetState(ActionState::Idle); }, 0.8f);
		break;
	}
}

void SenseiWu::Idle() {
	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}

void SenseiWu::FireballAttack() {
	if (Time::time() >= _nextFireballTime) {

		Vector2 direction = Vector2::right() * transform()->scale.x();
		GameObject* projectile = _projectilePool.Get();
		projectile->transform->position = transform()->position + direction * 0.25f;
		projectile->transform->rotation = Vector3::forward() * -90 * transform()->scale.x();
		projectile->GetComponent<Projectile>()->Initialize(direction, gameObject, &_projectilePool);
		projectile->GetComponent<Hitbox>()->data.faction = faction;
		projectile->GetComponent<Hitbox>()->data.entity = this;

		_audioSource->clip = "Assets/Sounds/Blaster.wav";
		_audioSource->Play();

		_nextFireballTime = Time::time() + _fireballAttackCooldown;
	}

	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}

void SenseiWu::StudentAttack() {
	if (Time::time() >= _nextStudentTime) {
		Instantiate(Prefab::Students_Object, transform()->position + Vector2::right() * ((rand()%2) ==0? -1:1));
		_nextStudentTime = Time::time() + _studentAttackCooldown;
	}
	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}