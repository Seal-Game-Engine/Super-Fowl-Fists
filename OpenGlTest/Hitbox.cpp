#include "Hitbox.h"

Hitbox::Hitbox(DamageData data) :data(data) {}

void Hitbox::OnTriggerEnter2D(Collider2D* collider) {
	if (collider->gameObject->CompareTag("Entity") || collider->gameObject->CompareTag("Interactable")) {
		if (auto damageable = collider->gameObject->GetComponent<IDamageable>()) {
			if (data.faction == damageable->faction && data.faction != Factions::NoFaction) return;
			
			damageable->OnDamageTaken(data, (collider->gameObject->transform->position - transform()->position).normalized());
		}
	}
}
void Hitbox::OnCollisionEnter2D(Collision2D collision) { OnTriggerEnter2D(collision.collider); }