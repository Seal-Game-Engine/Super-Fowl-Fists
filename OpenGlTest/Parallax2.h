#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Parallax2 {
public:
    Parallax2();
    void Update();
    void Scroll(Vector2 direction);

    float speed = 0.08f;
    Sprite sprite;

private:
    Rect rect = Rect(0, 0, 1, 1);
};
