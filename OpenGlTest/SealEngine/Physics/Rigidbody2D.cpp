#include "Rigidbody2D.h"
#include "Collider2D.h"
#include "../GameObject.h"
#include "../Clock.h"
using namespace SealEngine;

void Rigidbody2D::Update(){
	_initialPosition = transform()->position;


	//AddForce(Vector2::down() * mass * 0.98f * gravityScale);
	//velocity = Vector2::Lerp(velocity, Vector2::zero(), Time::deltaTime());

}

void Rigidbody2D::LateUpdate() {
	transform()->position += velocity * Time::deltaTime();
	//velocity = (transform()->position - _initialPosition);
}

void Rigidbody2D::OnCollisionEnter2D(Collision2D collision) {
	float e = 0.5f;
	int minId = 0;
	float separation = FLT_MAX;
	for (int i = 0; i < collision.contactCount(); i++) {
		//transform()->position += collision.GetContact(i).normal * collision.GetContact(i).separation * Time::deltaTime();

		//if (Vector2::Dot(collision.relativeVelocity(), collision.GetContact(i).normal) > 0) continue;

		//auto normal = collision.GetContact(i).normal;
		//auto j = -(1.0f + e) * Vector2::Dot(collision.relativeVelocity(), normal) /
		//	(1.0f / mass + 1.0f / (collision.otherRigidbody() ? collision.otherRigidbody()->mass : FLT_MAX));
		////velocity -= normal * (j / mass);
		//auto impulse = normal * j;
		//velocity -= impulse / mass;
		
		//velocity -= collision.GetContact(i).normal * 1 * Time::deltaTime();
		//transform()->position += velocity * Time::deltaTime();
		if (collision.GetContact(i).separation < separation) {
			minId = i;
			separation = collision.GetContact(i).separation;
		}
	}

	
	transform()->position += collision.GetContact(minId).normal * -collision.GetContact(minId).separation;// *Time::deltaTime();

	if (Vector2::Dot(collision.relativeVelocity(), collision.GetContact(minId).normal) > 0) return;

	auto normal = collision.GetContact(minId).normal;
	auto j = -(1.0f + e) * Vector2::Dot(collision.relativeVelocity(), normal);//
	j/=	(1.0f / mass) + (1.0f / (collision.otherRigidbody() ? collision.otherRigidbody()->mass : FLT_MAX));
	//velocity -= normal * (j / mass);
	auto impulse = normal * -j;
	velocity -= impulse / mass;

	//velocity -= collision.GetContact(i).normal * 1 * Time::deltaTime();
	//transform()->position += velocity * Time::deltaTime();

	//AddForce(collision.GetContact(minSeparation).normal * -collision.GetContact(minSeparation).separation);

	//for (int i = 0; i < collision.contactCount(); i++) {
	//}
	//transform()->position += velocity * Time::deltaTime();
}

void Rigidbody2D::AddForce(Vector2 force, ForceMode2D mode) { velocity += force / mass * Time::deltaTime(); }

int Rigidbody2D::GetAttachedColliders(std::vector<Collider2D*>& results) {
	results = gameObject->GetComponents<Collider2D>();
	_attachedColliderCount = results.size();
	return attachedColliderCount();
}