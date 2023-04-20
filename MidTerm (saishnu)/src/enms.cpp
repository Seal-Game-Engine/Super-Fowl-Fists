#include "enms.h"

enms::enms()
{
    //ctor
    ePos.x = 0.7;
    ePos.y= -0.5;
    ePos.z =-2.0;

    eSize.x =0.2;
    eSize.y =0.2;

    eRotation.x = eRotation.y =eRotation.z =0;
    eSpeed.x =-0.05;
    eSpeed.y =0.0;
    //action = WALKDOWN;
    action = IDLE;

    theta =30*PI/180.0;
    velocity =35;
    t=0;

    startTime = clock();
}

enms::~enms()
{
    //dtor
}
void enms::drawEnemy()
{  tLoad->binder(tex);
    glPushMatrix();

      glTranslated(ePos.x,ePos.y,ePos.z);
      glRotatef(eRotation.x,1.0,0.0,0.0);
      glRotatef(eRotation.y,0.0,1.0,0.0);
      glRotatef(eRotation.z,0.0,0.0,1.0);

      glScalef(eSize.x,eSize.y,1);

      glBegin(GL_POLYGON);
        glTexCoord2f(xMin,yMin);
        glVertex3f(1.0,1.0,0.0);

        glTexCoord2f(xMax,yMin);
        glVertex3f(-1.0,1.0,0.0);

        glTexCoord2f(xMax,yMax);
        glVertex3f(-1.0,-1.0,0.0);

        glTexCoord2f(xMin,yMax);
        glVertex3f(1.0,-1.0,0.0);

      glEnd();

     actions();
    glPopMatrix();

}

void enms::placeEnemy(vec3 p)
{
    ePos.x =p.x;
    ePos.y =p.y;
    ePos.z =p.z;
}


void enms::enemyTexture(char* fileName)
{
    tLoad->loadTexture(fileName,tex);
}

void enms::initEnemy(GLuint tex , int vfrm, int hfrm)
{
     glEnable(GL_BLEND);
     glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

     vFrames = vfrm;
     hFrames = hfrm;

    xMax = 1.0/(float)vFrames;
    xMin = 0.0;
    yMax = 1.0/(float)hFrames;
    yMin = 0.0;

    this->tex = tex;

}

void enms::actions()
{
    switch(action){
        case IDLE:
            if( clock() - startTime>60) {
                xMax += 1.0/(float)vFrames;
                xMin += 1.0/(float)vFrames;
                startTime =clock();
            }
            break;

        case WALKUP:
            if (clock() - startTime > 60) {
                yMax += 1.0 / (float)hFrames;
                yMin += 1.0 / (float)hFrames;
                xMax = 1.0 / (float)vFrames;
                xMin = 0.0;
                eRotation.z = 0;
                ePos.x = 1.0;
                ePos.y -= eSpeed.y;
                startTime = clock();
            }
            break;

        case WALKDOWN:
            if (clock() - startTime > 60) {
                yMax += 1.0 / (float)hFrames;
                yMin += 1.0 / (float)hFrames;
                xMax = 1.0 / (float)vFrames;
                xMin = 0.0;
                eRotation.z = 0;
                ePos.x = -1.0;
                ePos.y += eSpeed.y;
                startTime = clock();
            }
            break;

        case ROLLR:
            if( clock() - startTime>60) {
                xMax += 1.0/(float)vFrames;
                xMin += 1.0/(float)vFrames;
                yMax = 1.0;
                yMin = 1.0/(float)hFrames;
                eRotation.z += (float)(rand()/(float)(RAND_MAX))*100;
                ePos.x += 1.07;
                startTime =clock();
            }
            break;

        case ROLLL:
            if( clock() - startTime>60) {
                xMax += 1.0/(float)vFrames;
                xMin += 1.0/(float)vFrames;
                yMax = 1.0;
                yMin = 1.0/(float)hFrames;
                eRotation.z += (float)(rand()/(float)(RAND_MAX))*100;
                ePos.x -= (velocity*t*cos(theta))/1200.0;
                ePos.y += (velocity*t*sin(theta)-0.5*GRVITY*t*t)/700;
                if(ePos.y>=-0.5) t+=0.2;
                else{t=0; ePos.y=-0.5;}
                startTime =clock();
            }
            break;
    }
}
