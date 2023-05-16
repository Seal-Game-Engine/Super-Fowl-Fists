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
	actionState = ActionState::Idle;
	_nextActionTime = Time::time() + rand() % 3 + 1;
}

void SenseiWu::Update() {
	if (!isAlive()) return;

	//_rigidbody->velocity = Vector2(-0.05, _rigidbody->velocity.y());

	switch (actionState) {
	case ActionState::Idle: Idle(); break;
	case ActionState::FireballAttack: FireballAttack(); break;
	case ActionState::TeleportOut: TeleportOut(); break;
	case ActionState::TeleportIn: TeleportIn(); break;
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
		_nextActionTime = Time::time() + rand() % 3 + 1;
		break;
	case ActionState::FireballAttack:
		_nextActionTime = Time::time() + _fireballAttackDuration;
		break;
	case ActionState::StudentAttack:
		_animator->Play("Call");
		_nextActionTime = Time::time() + _studentAttackDuration;
		break;

	case ActionState::TeleportOut:
		break;
	}
}

void SenseiWu::OnStateExit() {
	switch (actionState) {
	case ActionState::Idle:
		switch (rand() % 3) {
		case 0:
		case 1:
			_animator->Play("Hadoken");
			Invoke([&] { SetState(ActionState::FireballAttack); }, 0.2f);
			break;
		case 2:
			_animator->Play("TeleportOut");
			Invoke([&] { SetState(ActionState::TeleportOut); }, 0.7f);
			break;
		}
		break;

	case ActionState::FireballAttack:
	case ActionState::TeleportIn:
		_animator->Play("Idle");
		Invoke([&] { SetState(ActionState::Idle); }, 0);
		break;

	case ActionState::TeleportOut:
		Invoke([&] { SetState(ActionState::StudentAttack); }, 0.6f);
		break;

	case ActionState::StudentAttack:
		_animator->Play("TeleportOut");
		Invoke([&] { SetState(ActionState::TeleportIn); }, 0.7f);
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

void SenseiWu::TeleportOut(){
	transform()->position = Vector2(0, 0);
	SetState(ActionState::InTransition);
}

void SenseiWu::TeleportIn() {
	transform()->position = Vector2(2, -1.4f);
	SetState(ActionState::InTransition);
}

void SenseiWu::StudentAttack() {
	if (Time::time() >= _nextStudentTime) {
		Instantiate(Prefab::Students_Object, transform()->position + Vector2::right() * ((rand()%2) == 0 ? -1 : 1) * 2);
		_nextStudentTime = Time::time() + _studentAttackCooldown;
	}
	if (Time::time() >= _nextActionTime) SetState(ActionState::InTransition);
}