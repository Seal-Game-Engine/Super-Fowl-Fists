#include "NarioPlayer.h"
#include "AssetManager.h"
#include <cmath>

void NarioPlayer::Awake() {
	animator = gameObject->GetComponent<Animator>();
}

void NarioPlayer::Update() {
	//308.0f
	//315.0f

	float screenWidth = 340.0f;
	float screenHeight = 340.0f;
	int x = (Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::LeftArrow)) && (Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::RightArrow)) ? 0
		: Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::LeftArrow) ? -1
		: Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::RightArrow) ? 1
		: 0;

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
}

void NarioPlayer::LateUpdate() {

	std::vector<Collider2D*> myColliders = gameObject->GetComponents<Collider2D>();
	for (auto& _gameObject : SceneManager::scenes[SceneManager::currentSceneId]->gameObjects) {
		std::vector<Collider2D*> otherColliders = _gameObject->GetComponents<Collider2D>();
		for (auto& myCollider : myColliders)
			for (auto& otherCollider : otherColliders) {
				if (Collider2D::checkCollision(*myCollider, *otherCollider)) {
					for (auto& component : gameObject->components) component->OnCollisionEnter2D();
					for (auto& component : otherCollider->gameObject->components) component->OnCollisionEnter2D();
				}
			}
	}
}
