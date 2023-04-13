#include "parallax.h"

parallax::parallax()
{
    //ctor
    xMax = 1.0;
    xMin = 0.0;
    yMax = 0.0;
    yMin = 1.0;

    startTime = clock();
}

parallax::~parallax()
{
    //dtor
}
void parallax::drawSquare(float width, float height)
{
    glColor3f(1.0,1.0,1.0);
     bTex->binder(tex);
    glBegin(GL_POLYGON);
       glTexCoord2f(xMin,yMin);
       glVertex3f(-1*width/height, -1,-8.0);

       glTexCoord2f(xMax,yMin);
       glVertex3f(width/height, -1,-8.0);

       glTexCoord2f(xMax,yMax);
       glVertex3f(width/height, 1,-8.0);

       glTexCoord2f(xMin,yMax);
       glVertex3f(-1*width/height,1,-8.0);

    glEnd();
}

void parallax::initParallax(char *fileName)
{
   bTex->loadTexture(fileName,tex);
}

void parallax::scroll(bool scrl, string Dir, float speed)
{
       if(scrl){

        if(clock()-startTime>15){
        if(Dir == "x"){ xMin +=speed; xMax +=speed;}
        else if(Dir == "-x"){ xMin -=speed; xMax -=speed;}
        else  if(Dir == "y"){ yMin -=speed; yMax -=speed;}
        else{ yMin +=speed; yMax +=speed;}

        startTime =clock();
        }
       }
}
