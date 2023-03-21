#include "CheckCollision.h"
#include <cmath>

bool CheckCollision::isRadialCollision(Vector2 a, Vector2 b, float r1, float r2) { return Vector2::Distance(a, b) < r1 + r2; }

bool CheckCollision::isLinearCollision(float x1, float x2) {
    return (abs(x1 - x2) < 0.01);
}
