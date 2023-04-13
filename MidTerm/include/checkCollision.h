#ifndef CHECKCOLLISION_H
#define CHECKCOLLISION_H
#include <commons.h>

class checkCollision
{
    public:
        checkCollision();
        virtual ~checkCollision();
        bool isRadialCollision(float,float,float, float,float,float);
        bool isLinearCollision(float x1, float x2);
        bool isSphereCollision(vec3 x, vec3 y);
        bool isQuadCollision(vec2 x, vec2 y);

    private:
};

#endif // CHECKCOLLISION_H
