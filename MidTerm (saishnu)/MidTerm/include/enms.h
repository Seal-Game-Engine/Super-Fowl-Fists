#ifndef ENMS_H
#define ENMS_H

#include<GL/gl.h>
#include<textureLoader.h>
#include<commons.h>
#include<time.h>

class enms
{
    public:
        enms();
        virtual ~enms();
        void drawEnemy();
        void placeEnemy(vec3);
        void initEnemy(GLuint, int, int);
        void enemyTexture(char * );

        enum acts{IDLE,WALKR,WALKL,ROLLR,ROLLL,JUMP,ATTACK,DIE,WALKUP, WALKDOWN};
        void actions();
        acts action;

        int hFrames; // horizontal frames
        int vFrames; // vertical frames

        float xMax,yMax,xMin,yMin;// for the texture
        vec3 ePos;   // position of the enemy
        vec2 eSize;
        vec2 eSpeed; // moving speed

        vec3 eRotation;
        clock_t startTime;

        GLuint tex;
        textureLoader *tLoad = new textureLoader();
        float theta, velocity, t; // t is time on projectiles

    protected:

    private:
};

#endif // ENMS_H

