#include "Student.h"

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
}

void Student::Update()
{
	_rigidbody->velocity = Vector2(-1, _rigidbody->velocity.y());
}
