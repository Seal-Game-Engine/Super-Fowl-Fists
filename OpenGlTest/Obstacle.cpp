#include "Obstacle.h"
#include "AssetManager.h"
#include <random>

void Obstacle::Awake() {
	float determine = rand() % 10;
	float x = (rand() % 14) - 7;
	float y = (rand() % 4) - 3;
	transform()->position = Vector2(x, y);
	if (determine > 3) transform()->rotation = Vector3::forward() * 30 * Time::deltaTime();
	spawnedPosition = Vector2(x, y);
}

void Obstacle::Update() { //move to other direction
	if (spawnedPosition.x() > 0)
		transform()->position += Vector2::left() * (rand() % 5) * Time::deltaTime();
	else
		transform()->position += Vector2::right() * (rand() % 5) * Time::deltaTime();
}

void Obstacle::OnCollisionEnter2D() {
	Destroy(*gameObject);
}
