#include "CreditEventManager.h"
#include "../Parallax.h"

void CreditEventManager::Update() {
    using namespace InputSystem;

    if (Input::GetKeyDown(KeyCode::Return)) SceneManager::LoadScene(1);
    if (Input::GetKeyDown(KeyCode::Escape)) SceneManager::LoadScene(1);

    float x = Input::GetKeyDown(KeyCode::Q) ? 1
        : Input::GetKeyDown(KeyCode::E) ? -1
        : 0;

    //Scene::FindFirstObjectByType<Parallax>()->transform()->position += Vector3::forward() * Time::deltaTime() * x;
}

CreditEventManager* CreditEventManager::_Clone() const {
    return new CreditEventManager(*this);
}