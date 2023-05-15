#include "Boss.h"
#include "Prefab.h"

#include <cmath>
#include "EventManagers/GameEventManager.h"
#include "GameplayData.h"

void Boss::OnDamageTaken(DamageData data, Vector2 knockbackDirection) {
	if (!isAlive()) return;

	Entity::OnDamageTaken(data, knockbackDirection);
	GameEventManager::instance->UpdateUi();
}

void Boss::OnDeath() {
	_renderer->enabled = false;
	Instantiate(Prefab::Explosion64_Object, transform()->position);
	Invoke([] {	GameEventManager::instance->OnLevelCompleted();	}, 2);
}

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

	currentHp *= GameplayData::playerCount;
}