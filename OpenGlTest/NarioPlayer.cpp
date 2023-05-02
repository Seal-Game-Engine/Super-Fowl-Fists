#include "NarioPlayer.h"
#include "AssetManager.h"
#include "Obstacle.h"
#include <cmath>

void NarioPlayer::Awake() {
	animator = gameObject->GetComponent<Animator>();
}

void NarioPlayer::Update() {
	//308.0f
	//315.0f

	float screenWidth = 340.0f;
	float screenHeight = 340.0f;
	int x = Input::GetAxisRaw(Input::Axis::Horizontal);

	float gravityDelayTime = .3f;
	const float gForce = 10.0f;
	Vector2 horizontalMovement = Vector2::right() * (float)x * _speed * Time::deltaTime();

	if (Input::GetKeyDown(KeyCode::UpArrow) || Input::GetKeyDown(KeyCode::W)) { animator->Play("Jump"); stopGravity = Time::time() + gravityDelayTime; }

	Vector2 gravity = Vector2::down() * gForce * Time::deltaTime();

	if (Time::time() >= stopGravity)
		transform()->position += gravity;
	else transform()->position -= gravity * 1.5f;

	transform()->position += horizontalMovement;

	if (std::abs(transform()->position.x()) > (float)ApplicationManager::width / screenWidth) transform()->position -= horizontalMovement;
	if (transform()->position.y() < -((float)ApplicationManager::height / screenHeight)) transform()->position.Set(transform()->position.x(), -(float)ApplicationManager::height / screenHeight, transform()->position.z());

	animator->SetInteger("x", x);

	if (Input::GetKeyDown(KeyCode::Space)) {
		auto obstacles = FindObjectsByType<Obstacle>();
		for (auto& obstacle : obstacles) Destroy(*obstacle->gameObject);
	}
}