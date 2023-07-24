#pragma once
#include "Vector3.h"
#include "MonoBehaviour.h"

namespace SealEngine
{
class Transform : public MonoBehaviour
{
public:
    Vector3 position = Vector3::zero();
    Vector3 rotation = Vector3::zero();
    Vector3 scale = Vector3::one();

    Vector3 up() const;
    Vector3 right() const;
    Vector3 forward() const;

    Transform() = default;
    Transform(const Vector3& position);
    Transform(const Vector3& position, const Vector3& rotation, const Vector3& scale);

private:
    Transform* _Clone() const override { return new Transform(*this); }
};
}
