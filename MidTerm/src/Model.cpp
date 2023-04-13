#include "Model.h"

Model::Model()
{
    //ctor
    rotateX =0;
    rotateY =0;
    rotateZ =0;

    zoom = -3.0;
    posX = 0.0;
    posY = 0.0;

}

Model::~Model()
{
    //dtor
}
void Model::drawModel()
{
    tLoad->binder(tex);
    glTranslated(posX,posY,zoom);
    glRotated(rotateX,1,0,0);
    glRotated(rotateY,0,1,0);
    glRotated(rotateZ,0,0,1);

     glutSolidTeapot(0.5);

}

void Model::modelInit(char *fileName)
{
   //    glEnable(GL_COLOR_MATERIAL);
   tLoad->loadTexture(fileName,tex);
}
