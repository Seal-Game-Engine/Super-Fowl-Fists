#include "MonoBehaviour.h"
#include "Transform.h"
#include "GameObject.h"
using namespace SealEngine;

std::shared_ptr<MonoBehaviour> SealEngine::MonoBehaviour::Clone() const { return std::shared_ptr<MonoBehaviour>(Clone_impl()); }

bool MonoBehaviour::operator!=(const MonoBehaviour& obj) {

    return this != &obj;
}

MonoBehaviour* SealEngine::MonoBehaviour::Clone_impl() const { return new MonoBehaviour(*this); }

bool MonoBehaviour::isActiveAndEnabled() { return enabled && gameObject->activeSelf(); }

Transform* MonoBehaviour::transform() { return gameObject->transform; }
