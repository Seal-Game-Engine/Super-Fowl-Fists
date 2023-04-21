#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Parallax:public MonoBehaviour{
    public:
        const Sprite* sprite = nullptr;

        float speed = 0.1f;
        Vector2 direction = Vector2::down();

        void Update() override;

        Parallax() = default;
        Parallax(const Sprite* sprite, Vector2 direction, float speed);
        std::shared_ptr<Parallax> Clone() const;

    private:
        Rect rect = Rect(0, 0, 1, 1);

        Parallax* Clone_impl() const override;
};


