#include "LandingScene.h"
#include "Player.h"
#include "Parallax.h"
#include "Parallax2.h"
#include "AssetManager.h"
#include "Obstacle.h"

std::vector<std::unique_ptr<Obstacle>> LandingScene::obstacles = std::vector<std::unique_ptr<Obstacle>>{};

LandingScene::LandingScene() {
}

void LandingScene::Load() {
    Object::Instantiate(AssetManager::NarioObject);
    Object::Instantiate(AssetManager::ObstacleSpawnerObject);
}

void LandingScene::Refresh() {
    static std::unique_ptr<Parallax> parallax = std::make_unique<Parallax>();
    static std::unique_ptr<Parallax2> parallax2 = std::make_unique<Parallax2>();

    if (Inputs::GetKey(KeyCode::A) || Inputs::GetKey(KeyCode::LeftArrow)) {
        parallax->Scroll(Vector2::left());parallax2->Scroll(Vector2::left());
    }
    if (Inputs::GetKey(KeyCode::D) || Inputs::GetKey(KeyCode::RightArrow)) {
        parallax->Scroll(Vector2::right());parallax2->Scroll(Vector2::right());
    }
    parallax->Update();
    parallax2->Update();
    

    Scene::Refresh();
}
