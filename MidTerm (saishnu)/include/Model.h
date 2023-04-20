#ifndef MODEL_H
#define MODEL_H

#include<windows.h>
#include<GL/glut.h>

#include<textureLoader.h>

class Model
{
    public:
        Model();
        virtual ~Model();

        void drawModel();
        void modelInit(char *fileName);

        float rotateX;
        float rotateY;
        float rotateZ;

        float zoom;
        float posX;
        float posY;

        GLuint tex;
        textureLoader *tLoad = new textureLoader();

    protected:

    private:
};

#endif // MODEL_H
