#include "LandingScene.h"

#include "Player.h"
#include "Parallax.h"
#include "AssetManager.h"

std::vector<std::unique_ptr<Projectile>> LandingScene::projectiles = std::vector<std::unique_ptr<Projectile>>{};

LandingScene::LandingScene() {
}

void LandingScene::Load() {
    Object::Instantiate(AssetManager::XwingObject);
}

void LandingScene::Refresh() {
    static std::unique_ptr<Parallax> parallax = std::make_unique<Parallax>();

    /*static std::unique_ptr<GameObject> bob = std::make_unique<GameObject>(
        "Bob", std::vector<MonoBehaviour>{
        SpriteRenderer(&AssetManager::GreenSlime[1], false, false),
            Animator(&AssetManager::GreenSlime_Controller),
            Player(),
    });

    static Player* player = bob->GetComponent<Player>();
    static bool test = bob->TryGetComponent<Player>(player);*/

    parallax->Scroll(Vector2::down());
    parallax->Update();

    //for (auto& projectile : projectiles) {
    //    if (!projectile) continue;
    //    projectile->Update();
    //    //projectile->renderer.LateUpdate();
    //}

    Scene::Refresh();
}
