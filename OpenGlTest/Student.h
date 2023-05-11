#pragma once
#include "Entity.h"
#include "Hitbox.h"
class Student :    public Entity{
public:
	Student(const float hp) :Entity(hp) {}

	void OnDamageDealt() override;

	void OnDeath() override;
	void Awake() override;

	void Update() override;
private: 
	Rigidbody2D* _rigidbody = nullptr;
	Hitbox* hitbox = nullptr;

	Student* _Clone() const override { return new Student(*this); }
};

