#include "Student.h"
#include "GameplayData.h"
#include "Player.h"

void Student::OnDamageDealt(){
	hitbox->enabled = false;
	Invoke([&] {hitbox->enabled = true; }, 1);
}

void Student::OnDeath()
{
	Entity::OnDeath();
	Destroy(*gameObject);
}

void Student::Awake()
{
	_rigidbody = gameObject->GetComponent<Rigidbody2D>();
	hitbox = gameObject->GetComponent<Hitbox>();
	hitbox->data.entity = this;

	//InvokeRepeating([&] {hitbox->enabled = !hitbox->enabled; }, 2,2);

	_target = Scene::FindObjectsByType<Player>()[rand() % GameplayData::playerCount]->gameObject;
}

void Student::Update()
{
	float direction = (_target->transform->position.x() - transform()->position.x()) > 0 ? 1 : -1;

	_rigidbody->velocity = Vector2(direction, _rigidbody->velocity.y());
}
