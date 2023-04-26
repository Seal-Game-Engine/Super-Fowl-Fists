#include "Player.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "LandingScene.h"
#include <cmath>
void Player::Awake() {
animator = gameObject->GetComponent<Animator>();
}

void Player::Update() {
	/*
	308.0f
	315.0f
	*/

	float screenWidth = 340.0f;
	float screenHeight = 340.0f;
	int x = (Inputs::GetKey(KeyCode::A) || Inputs::GetKey(KeyCode::LeftArrow)) && (Inputs::GetKey(KeyCode::D) || Inputs::GetKey(KeyCode::RightArrow)) ? 0
		: Inputs::GetKey(KeyCode::A) || Inputs::GetKey(KeyCode::LeftArrow) ? -1
		: Inputs::GetKey(KeyCode::D) || Inputs::GetKey(KeyCode::RightArrow) ? 1
		: 0;

	float gravityDelayTime = .3f;
	const float gForce = 10.0f;
	Vector2 horizontalMovement = Vector2::right() * (float)x * _speed * Time::deltaTime();
	
	if (Inputs::GetKeyDown(KeyCode::UpArrow) || Inputs::GetKeyDown(KeyCode::W)) { animator->Play("Jump"); stopGravity = Time::time() + gravityDelayTime; }

	Vector2 gravity = Vector2::down() * gForce * Time::deltaTime();

	if (Time::time() >= stopGravity)
		transform()->position += gravity;
	else transform()->position -= gravity * 1.5f;
	
	transform()->position +=  horizontalMovement;

	if (std::abs(transform()->position.x()) > (float)ApplicationManager::width / screenWidth) transform()->position -= horizontalMovement;
	if (transform()->position.y() < -((float)ApplicationManager::height / screenHeight)) transform()->position.Set(transform()->position.x(), -(float)ApplicationManager::height / screenHeight, transform()->position.z());

	animator->SetInteger("x", x);
}

void Player::LateUpdate() {

	std::vector<Collider2D*> myColliders = gameObject->GetComponents<Collider2D>();
	for (auto& _gameObject : SceneManager::scenes[SceneManager::currentSceneId]->gameObjects) {
  		std::vector<Collider2D*> otherColliders = _gameObject->GetComponents<Collider2D>();
		for (auto& myCollider : myColliders)
			for (auto& otherCollider : otherColliders) {
				if (Collider2D::checkCollision(*myCollider,*otherCollider)) {
					for (auto& component : gameObject->components) component->OnCollisionEnter2D();
					for (auto& component : otherCollider->gameObject->components) component->OnCollisionEnter2D();
				}
			}
	}
}

