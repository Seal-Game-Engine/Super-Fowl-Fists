#pragma once
namespace SealEngine { struct Vector3; }

namespace SealEngine {
    struct Vector2 {
    public:
        float x() const;
        float y() const;
        float sqrMagnitude() const;
        float magnitude() const;
        Vector2 normalized() const;

        void Set(const float x, const float y);


        static float Dot(const Vector2&, const Vector2&);
        static float Distance(const Vector2&, const Vector2&);
        static Vector2 Perpendicular(const Vector2&);
        static Vector2 Lerp(const Vector2& a, const Vector2& b, float t);

        static Vector2 zero();
        static Vector2 one();
        static Vector2 up();
        static Vector2 down();
        static Vector2 left();
        static Vector2 right();


        Vector2(const float x, const float y);
        Vector2(const Vector2&);

        Vector2 operator-() const;

        Vector2 operator+(const Vector2&) const;
        Vector2 operator-(const Vector2&) const;
        Vector2 operator*(const float) const;
        Vector2 operator/(const float) const;

        Vector2& operator+=(const Vector2&);
        Vector2& operator-=(const Vector2&);
        Vector2& operator*=(const float);
        Vector2& operator/=(const float);

        bool operator==(const Vector2&) const;
        bool operator!=(const Vector2&) const;

        operator Vector3() const;

    private:
        float _x, _y;
    };
}
