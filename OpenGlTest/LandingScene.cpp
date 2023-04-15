#include "LandingScene.h"

#include "Player.h"
#include "Parallax.h"

std::vector<std::unique_ptr<Projectile>> LandingScene::projectiles = std::vector<std::unique_ptr<Projectile>>{};

void LandingScene::Refresh() {
    static std::unique_ptr<Player> player = std::make_unique<Player>();
    static std::unique_ptr<Parallax> parallax = std::make_unique<Parallax>();

    static std::unique_ptr<GameObject> gameObject = std::make_unique<GameObject>(
        "Bob", std::vector<MonoBehaviour>{
        SpriteRenderer(),
            Animator(),
    });

    parallax->Scroll(Vector2::down());
    parallax->Update();

    player->Update();

    player->animator.Update();
    player->renderer.LateUpdate();

    for (auto& projectile : projectiles) {
        if (!projectile) continue;
        projectile->Update();
        projectile->renderer.LateUpdate();
    }
}
