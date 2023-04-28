#pragma once
#include "Collider2D.h"

namespace SealEngine {
    class CircleCollider2D : public Collider2D {
    public:
        float radius = 0.5f;

        CircleCollider2D(float radius = 0.5f, Vector2 offset = Vector2::zero());
    private:
        float circumradius() const override { return radius; }

        CircleCollider2D* _Clone() const override { return new CircleCollider2D(*this); }
    };
}

