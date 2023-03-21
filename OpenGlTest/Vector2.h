#pragma once
namespace SealEngine { struct Vector3; }

namespace SealEngine {
    struct Vector2 {
    public:
        Vector2(const float&, const float&);
        Vector2(const Vector2&);
        operator Vector3() const;

        const float& x() const;
        const float& y() const;

        void Set(const float&, const float&);

        static Vector2 zero();
        static Vector2 one();
        static Vector2 up();
        static Vector2 down();
        static Vector2 left();
        static Vector2 right();

        Vector2 operator+(const Vector2&) const;
        Vector2 operator-(const Vector2&) const;
        Vector2 operator*(const float&) const;
        Vector2 operator/(const float&) const;

        Vector2& operator+=(const Vector2&);
        Vector2& operator-=(const Vector2&);
        Vector2& operator*=(const float&);
        Vector2& operator/=(const float&);


        bool operator==(const Vector2&) const;
        bool operator!=(const Vector2&) const;

        float sqrMagnitude() const;
        float magnitude() const;
        Vector2 normalized() const;

        static float Dot(const Vector2&, const Vector2&);
        static float Distance(const Vector2&, const Vector2&);

        bool isPerpendicular(const Vector2&) const;

    private:
        float _x, _y;
    };
}
