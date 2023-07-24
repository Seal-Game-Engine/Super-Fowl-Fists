#pragma once
#include "../MonoBehaviour.h"
#include "Collider2D.h"

namespace SealEngine {
    class Rigidbody2D : public MonoBehaviour {
    public:
        enum class BodyType { Dynamic, Kinematic };
        enum class ForceMode2D { Force, Impulse };

        void AddForce(Vector2 force, ForceMode2D mode = ForceMode2D::Force);
        int GetAttachedColliders(std::vector<Collider2D*>& results);

        int attachedColliderCount() { return _attachedColliderCount; }

        BodyType bodyType = BodyType::Dynamic;
        float mass = 1;
        float gravityScale = 1;
        float linearDrag = 0;
        Vector2 velocity = Vector2::zero();

        Rigidbody2D(BodyType bodyType = BodyType::Dynamic, float mass = 1, float gravityScale = 1);

        void Update() override;
        void LateUpdate() override;
        void OnCollisionStay2D(Collision2D collision) override;

    private:
        int _attachedColliderCount = 0;

        Rigidbody2D* _Clone() const override { return new Rigidbody2D(*this); }
    };
}