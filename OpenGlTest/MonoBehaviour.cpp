#include "MonoBehaviour.h"
#include "Transform.h"
#include "GameObject.h"
using namespace SealEngine;

bool MonoBehaviour::operator!=(const MonoBehaviour& obj) {

    return this != &obj;
}

Transform& MonoBehaviour::transform()
{
    return *_transform;
}

SealEngine::MonoBehaviour::MonoBehaviour(const GameObject& gameObject) : gameObject(gameObject){
}
