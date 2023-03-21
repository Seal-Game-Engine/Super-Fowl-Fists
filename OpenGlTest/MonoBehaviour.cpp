#include "MonoBehaviour.h"
#include "Transform.h"
using namespace SealEngine;

bool MonoBehaviour::operator!=(const MonoBehaviour& obj) {

    return this != &obj;
}

Transform MonoBehaviour::transform()
{
    return Transform();
}
