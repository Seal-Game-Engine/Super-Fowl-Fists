#include "checkCollision.h"

checkCollision::checkCollision()
{
    //ctor
}

checkCollision::~checkCollision()
{
    //dtor
}
bool checkCollision::isRadialCollision(float x1, float x2, float y1, float y2, float r1, float r2)
{
    if(sqrt(pow(x1-x2,2)+pow(y1-y2,2))< r1+r2)return true;
     return false;
}

bool checkCollision::isLinearCollision(float x1, float x2)
{
    if(fabs(x1-x2<0.1))return true;
    else return false;
}

bool checkCollision::isSphereCollision(vec3 x, vec3 y)
{

}

bool checkCollision::isQuadCollision(vec2 x, vec2 y)
{

}
