#include "MonoBehaviour.h"
#include "Transform.h"
#include "GameObject.h"
using namespace SealEngine;

bool MonoBehaviour::operator!=(const MonoBehaviour& obj) {

    return this != &obj;
}

Transform MonoBehaviour::transform()
{
    return Transform();
}

SealEngine::MonoBehaviour::MonoBehaviour(const GameObject& gameObject) : gameObject(gameObject){
}
