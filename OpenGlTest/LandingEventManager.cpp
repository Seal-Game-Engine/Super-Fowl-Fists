#include "LandingEventManager.h"

void LandingEventManager::Update()
{
    using namespace InputSystem;

    if (Input::GetKeyDown(KeyCode::Return)) SceneManager::LoadScene(1);
    if (Input::GetKeyDown(KeyCode::Escape)) SceneManager::Quit();
}

LandingEventManager* LandingEventManager::Clone_impl() const
{
    return new LandingEventManager(*this);
}
