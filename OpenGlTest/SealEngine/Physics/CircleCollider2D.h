#pragma once
#include "Collider2D.h"

namespace SealEngine {
    class CircleCollider2D : public Collider2D {
    public:
        float radius = 0.5f;

        CircleCollider2D(float radius = 0.5f, Vector2 offset = Vector2::zero());
    private:
        void ProjectVerticesOn(const Vector2& axis, float& min, float& max) override;
        
        float circumradius() const override { return radius; }
        std::vector<Vector2> separationAxes(const std::vector<Vector2>& otherPolygonVertices) override;

        CircleCollider2D* _Clone() const override { return new CircleCollider2D(*this); }
    };
}

