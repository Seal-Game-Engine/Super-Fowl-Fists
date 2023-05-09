#include "XwingPlayer.h"
#include "../Projectile.h"
#include "../AssetManager.h"
#include <cmath>

void XwingPlayer::Awake() {
	rigidbody = gameObject->GetComponent<Rigidbody2D>();
	renderer = gameObject->GetComponent<SpriteRenderer>();
	animator = gameObject->GetComponent<Animator>();
	audioSource = gameObject->GetComponent<AudioSource>();
}

void XwingPlayer::Update() {
	float x = Input::GetAxisRaw(Input::Axis::Horizontal);
	float y = Input::GetAxisRaw(Input::Axis::Vertical);

	Vector2 horizontalMovement = Vector2::right() * (float)x * _speed;
	Vector2 verticalMovement = Vector2::up() * (float)y * _speed;
	//rigidbody->AddForce(horizontalMovement + verticalMovement);
	if ((horizontalMovement + verticalMovement).magnitude() > 0)
		rigidbody->velocity = horizontalMovement + verticalMovement;
	else rigidbody->velocity = Vector2::zero();

	if (Input::GetKey(KeyCode::Space) && Time::time() >= _nextFire) {
		FireProjectile();
	}

	if (Input::GetKeyDown(KeyCode::T)) transform()->position = Vector2::up() * -1.5f;
	animator->SetInteger("x", (int)x);

	if(Input::GetKeyDown(KeyCode::MouseRight))
		audioSource->Play();

	if (Input::GetKeyDown(KeyCode::P))
		audioSource->Pause();
	if (Input::GetKeyDown(KeyCode::O))
		audioSource->UnPause();

	if (Input::GetKeyDown(KeyCode::L))
		audioSource->Stop();
}

void XwingPlayer::FireProjectile() {
	Instantiate(AssetManager::ProjectileObject_Blue, transform()->position + Vector2::up() * 0.5f);
	_nextFire = Time::time() + 0.15f;
}

void XwingPlayer::LateUpdate() {
	if(Camera::mainCamera) Camera::mainCamera->transform()->position = Vector2::Lerp(Camera::mainCamera->transform()->position, transform()->position, _speed * 0.75f * Time::deltaTime());
}