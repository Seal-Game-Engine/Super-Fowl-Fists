#include "SealLogoEventManager.h"
#include "../Parallax.h"

void SealLogoEventManager::Awake() {
    Invoke([] { SceneManager::LoadScene(0); }, 0.5f);

    //Scene::FindFirstObjectByType<Parallax>()->transform()->position += Vector3::forward() * Time::deltaTime() * x;
}

SealLogoEventManager* SealLogoEventManager::_Clone() const {
    return new SealLogoEventManager(*this);
}