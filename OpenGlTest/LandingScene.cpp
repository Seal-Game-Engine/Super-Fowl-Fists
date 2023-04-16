#include "LandingScene.h"

#include "Player.h"
#include "Parallax.h"
#include "AssetManager.h"

std::vector<std::unique_ptr<Projectile>> LandingScene::projectiles = std::vector<std::unique_ptr<Projectile>>{};

LandingScene::LandingScene() {
    //auto xwing = Object::Instantiate(AssetManager::XwingObject);
    //gameObjects.emplace_back(std::shared_ptr<GameObject>(dynamic_cast<GameObject*>(xwing)));
    //if(xwing)
    //gameObjects.emplace_back(std::shared_ptr<GameObject>((GameObject*)(xwing)));

    //const GameObject* xxwing = &AssetManager::XwingObject;
    //auto hi = AssetManager::XwingObject.Clone();
    //auto hii = dynamic_cast<GameObject*>(hi.get());

    //gameObjects.push_back(std::shared_ptr<GameObject>(dynamic_cast<GameObject*>(AssetManager::XwingObject.Clone().get())));
    gameObjects.push_back(AssetManager::XwingObject.Clone());


    /*gameObjects.emplace_back(std::make_shared<GameObject>(
        "Player",
        std::vector<std::shared_ptr<MonoBehaviour>>{
        std::make_shared<SpriteRenderer>(&AssetManager::Xwing[0], false, false),
            std::make_shared<Animator>(&AssetManager::Xwing_Controller),
            std::make_shared<Player>(),
    }
    ));*/
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

    for (auto& projectile : projectiles) {
        if (!projectile) continue;
        projectile->Update();
        //projectile->renderer.LateUpdate();
    }

    Scene::Refresh();

    if(Inputs::GetKeyDown(KeyCode::H)) gameObjects.push_back(AssetManager::XwingObject.Clone());

}
