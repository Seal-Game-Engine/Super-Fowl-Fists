#include "Obstacle.h"
#include "Projectile.h"

void Obstacle::Awake() {
	rigidbody = gameObject->GetComponent<Rigidbody2D>();
}

void Obstacle::Start(){
	player = Scene::FindFirstObjectByType<Player>();
	narioPlayer = Scene::FindFirstObjectByType<NarioPlayer>();
}

void Obstacle::Update() { //move to other direction
	Vector2 direction = ((player ? player->transform()->position : narioPlayer->transform()->position) - transform()->position).normalized();

	//transform()->position += direction * speed * Time::deltaTime();
	//rigidbody->velocity = direction * speed;
	rigidbody->AddForce(direction * speed);

	/*if (spawnedPosition.x() > 0)
		transform()->position += Vector2::left() * (rand() % 5) * Time::deltaTime();
	else
		transform()->position += Vector2::right() * (rand() % 5) * Time::deltaTime();*/
}

void Obstacle::OnCollisionEnter2D(Collision2D collision) {
	if (collision.gameObject()->GetComponent<Projectile>()) Destroy(*gameObject);
}
