#include "CheckCollision.h"
#include <cmath>

bool CheckCollision::isLinearCollision(float x1, float x2) {
    return (abs(x1 - x2) < 0.01);
}
