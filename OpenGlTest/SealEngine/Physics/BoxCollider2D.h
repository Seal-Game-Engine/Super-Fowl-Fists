#pragma once
#include "Collider2D.h"

namespace SealEngine {
    class BoxCollider2D : public Collider2D {
    public:
        Vector2 size = Vector2::one();

        BoxCollider2D(Vector2 size = Vector3::one(), bool isTrigger = false, Vector2 offset = Vector2::zero());

    private:
        void ProjectVerticesOn(const Vector2& axis, float& min, float& max) override;
        
        float circumradius() const override { return Vector2(size.x() / 2, size.y() / 2).magnitude(); }
        std::vector<Vector2> separationAxes(const std::vector<Vector2>& otherPolygonVertices) override;
        std::vector<Vector2> worldSpaceVertices() override;

        BoxCollider2D* _Clone() const override { return new BoxCollider2D(*this); }
    };
}

