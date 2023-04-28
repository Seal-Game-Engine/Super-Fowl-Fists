#include "LandingEventManager.h"
#include "Parallax.h"

void LandingEventManager::Update()
{
    using namespace InputSystem;

    if (Input::GetKeyDown(KeyCode::Return)) SceneManager::LoadScene(1);
    if (Input::GetKeyDown(KeyCode::Escape)) SceneManager::Quit();

    float x = Input::GetKeyDown(KeyCode::Q) ? 1
        : Input::GetKeyDown(KeyCode::E) ? -1
        : 0;

    FindFirstObjectByType<Parallax>()->transform()->position += Vector3::forward() * Time::deltaTime() * x;
}

LandingEventManager* LandingEventManager::_Clone() const
{
    return new LandingEventManager(*this);
}
