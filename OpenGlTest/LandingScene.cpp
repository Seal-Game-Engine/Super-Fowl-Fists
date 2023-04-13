#include "LandingScene.h"

#include "Player.h"
#include "Parallax.h"

std::vector<std::unique_ptr<Projectile>> LandingScene::projectiles = std::vector<std::unique_ptr<Projectile>>{};

void LandingScene::Refresh() {
    static std::unique_ptr<Player> player = std::unique_ptr<Player>(new Player);
    static std::unique_ptr<Parallax> parallax = std::unique_ptr<Parallax>(new Parallax);

    Object::FindFirstObjectByType<Object>();
    Object::FindObjectsByType<Object>();

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
