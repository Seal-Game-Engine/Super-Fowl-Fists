#include "XwingPlayer.h"
#include "Projectile.h"
#include "AssetManager.h"
#include <cmath>

void XwingPlayer::Awake() {
	rigidbody = gameObject->GetComponent<Rigidbody2D>();
	renderer = gameObject->GetComponent<SpriteRenderer>();
	animator = gameObject->GetComponent<Animator>();
}

void XwingPlayer::Update() {
	int x = Input::GetAxisRaw(Input::Axis::Horizontal);
	int y = Input::GetAxisRaw(Input::Axis::Vertical);

	Vector2 horizontalMovement = Vector2::right() * (float)x * _speed;
	Vector2 verticalMovement = Vector2::up() * (float)y * _speed;
	//rigidbody->AddForce(horizontalMovement + verticalMovement);
	if ((horizontalMovement + verticalMovement).magnitude() > 0)
		rigidbody->velocity = horizontalMovement + verticalMovement;
	else rigidbody->velocity = Vector2::zero();


	//if (std::abs(transform()->position.x()) > (float)ApplicationManager::width / 280.0f) transform()->position -= horizontalMovement;
	//if (std::abs(transform()->position.y()) > (float)ApplicationManager::height / 280.0f) transform()->position -= verticalMovement;

	if (Input::GetKey(KeyCode::Space) && Time::time() >= _nextFire) {
		Instantiate(AssetManager::ProjectileObject_Blue, transform()->position + Vector2::up() * 0.5f);
		_nextFire = Time::time() + 0.15f;
	}
	animator->SetInteger("x", x);

	if (Input::GetKeyDown(KeyCode::R))
		if (!renderer->enabled)renderer->enabled = true;
}