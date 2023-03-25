#pragma once
namespace SealEngine { struct Vector2; }

namespace SealEngine {
    struct Vector3 {
    public:
        const float& x() const;
        const float& y() const;
        const float& z() const;

        void Set(const float x, const float y, const float z);
        float sqrMagnitude() const;
        float magnitude() const;
        Vector3 normalized() const;


        static float Dot(const Vector3&, const Vector3&);
        static Vector3 Cross(const Vector3&, const Vector3&);
        static float Distance(const Vector3&, const Vector3&);
        static Vector3 ProjectOnPlane(const Vector3& vector, const Vector3& planeNormal);

        static Vector3 zero();
        static Vector3 one();
        static Vector3 up();
        static Vector3 down();
        static Vector3 left();
        static Vector3 right();
        static Vector3 forward();
        static Vector3 back();


        Vector3(const float x, const float y, const float z);
        Vector3(const Vector3&);


        Vector3 operator+(const Vector3&) const;
        Vector3 operator-(const Vector3&) const;
        Vector3 operator*(const float) const;
        Vector3 operator/(const float) const;

        Vector3& operator+=(const Vector3&);
        Vector3& operator-=(const Vector3&);
        Vector3& operator*=(const float);
        Vector3& operator/=(const float);

        bool operator==(const Vector3&) const;
        bool operator!=(const Vector3&) const;

        operator Vector2() const;

    private:
        float _x, _y, _z;
    };
}