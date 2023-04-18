#include "LandingScene.h"

#include "Player.h"
#include "Parallax.h"
#include "AssetManager.h"

LandingScene::LandingScene() {
}

void LandingScene::Load() {
    Object::Instantiate(AssetManager::XwingObject);
    Object::Instantiate(AssetManager::HectorObject, Vector3(1, 0, 0), Transform());

    Object::Instantiate(
        GameObject("Button",
            std::vector<std::shared_ptr<MonoBehaviour>>{
        std::make_shared<SpriteRenderer>(&AssetManager::GreenSlime[1], false, false),
            std::make_shared<Button>(),
    }
    )
    );
}

void LandingScene::Refresh() {
    static std::unique_ptr<Parallax> parallax = std::make_unique<Parallax>();

    parallax->Scroll(Vector2::down());
    parallax->Update();

    Scene::Refresh();
}
