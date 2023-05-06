#pragma once
#include "MonoBehaviour.h"

namespace SealEngine {
    class Camera : public MonoBehaviour {
    public:
        static Camera* mainCamera;

        enum class Projection { Perspective, Orthographic };
        Projection projection = Projection::Orthographic;
        float size = 3;

        Camera(Projection projection = Projection::Orthographic, float size = 3);

        void Awake() override;
        void OnDestroy() override;

    private:
        Camera* _Clone() const override { return new Camera(*this); }
    };
}
