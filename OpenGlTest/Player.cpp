#include "Player.h"
#include "Projectile.h"
#include "AssetManager.h"
#include "Obstacle.h"
#include <cmath>

const std::array<const AnimatorController*, 2> Player::animatorControllers{ &AssetManager::MiniTikeMyson_Controller, &AssetManager::BigTikeMyson_Controller }; //change to small and big guy controller

void Player::Awake(){
	renderer = gameObject->GetComponent<SpriteRenderer>();
	animator = gameObject->GetComponent<Animator>();
}

void Player::Update() {
	float screenWidth = 340.0f;
	float screenHeight = 340.0f;

	float gravityDelayTime = .15f;
	const float gForce = 10.0f;
	Vector2 gravity = Vector2::down() * gForce * Time::deltaTime();
	if (Time::time() >= stopGravity)
		transform()->position += gravity;
	else transform()->position -= gravity * 1.5f;
	int x = (Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::LeftArrow)) && (Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::RightArrow)) ? 0
		: Input::GetKey(KeyCode::A) || Input::GetKey(KeyCode::LeftArrow) ? -1
		: Input::GetKey(KeyCode::D) || Input::GetKey(KeyCode::RightArrow) ? 1
		: 0;
	Vector2 horizontalMovement = Vector2::right() * (float)x * _speed * Time::deltaTime();

	transform()->position += horizontalMovement;

	if (Input::GetKeyDown(KeyCode::UpArrow) || Input::GetKeyDown(KeyCode::W)) { animator->Play("Jump"); stopGravity = Time::time() + gravityDelayTime; }
	
	if (std::abs(transform()->position.x()) > (float)ApplicationManager::width / screenWidth) transform()->position -= horizontalMovement;
	if (transform()->position.y() < -1) transform()->position.Set(transform()->position.x(), -1, transform()->position.z());
	
	if (Input::GetKeyDown(KeyCode::Space)) {
		powerState = (PowerState)(((int)powerState + 1) % 2);
		animator->SetAnimatorController(animatorControllers[(int)powerState]);
	}

	animator->SetBool("isWalking", std::abs(x) > 0);
	if (std::abs(x) > 0) transform()->scale.Set(x > 0 ? 1 : -1, transform()->scale.y(), transform()->scale.z());


	if(Input::GetKeyDown(KeyCode::R))
		if (!renderer->enabled)renderer->enabled = true;

	//animator->SetInteger("x", x);

	/*
	//308.0f
	//315.0f
	

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
	*/
}

void Player::LateUpdate() {

	std::vector<Collider2D*> myColliders = gameObject->GetComponents<Collider2D>();
	auto& z = SceneManager::scenes[SceneManager::currentSceneId];
	for (auto& _gameObject : SceneManager::GetActiveScene()->gameObjects) {
		auto x = gameObject->GetInstanceId();
		auto y = _gameObject->GetInstanceId();
		if (x == y) continue;
  		std::vector<Collider2D*> otherColliders = _gameObject->GetComponents<Collider2D>();
		for (auto& myCollider : myColliders)
			for (auto& otherCollider : otherColliders) {
				if (*myCollider->gameObject != *otherCollider->gameObject && Collider2D::checkCollision(*myCollider, *otherCollider)) {
					for (auto& component : gameObject->components) component->OnCollisionEnter2D();
					for (auto& component : otherCollider->gameObject->components) component->OnCollisionEnter2D();
				}
			}
	}
}

void Player::OnCollisionEnter2D(){
	renderer->enabled = false;
	for (auto& obstacle : FindObjectsByType<Obstacle>()) Destroy(*obstacle->gameObject);
	powerState = PowerState::Small;
	animator->SetAnimatorController(animatorControllers[(int)powerState]);

}

