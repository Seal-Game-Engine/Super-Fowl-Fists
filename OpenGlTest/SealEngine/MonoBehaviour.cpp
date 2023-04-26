#include "MonoBehaviour.h"
#include "Transform.h"
#include "GameObject.h"
using namespace SealEngine;

bool MonoBehaviour::isActiveAndEnabled() { return enabled && gameObject->activeSelf(); }

Transform* MonoBehaviour::transform() { return gameObject->transform; }
