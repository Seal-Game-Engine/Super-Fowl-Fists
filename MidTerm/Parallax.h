#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Parallax
{
    public:
        Parallax();
        void Update();
        void Scroll(Vector2 direction);

        float speed = 0.02f;
        Sprite sprite;

    private:
        Rect rect = Rect(0, 0, 1, 1);
};


