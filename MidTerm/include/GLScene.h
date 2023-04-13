#ifndef GLSCENE_H
#define GLSCENE_H

#include <windows.h>
#include<GL/glut.h>
#include<iostream>

using namespace std;

class GLScene
{
    public:
        GLScene();
        virtual ~GLScene();
        int drawScene();   // main renderer
        int GLinit();       // initialization of the scene
        void GLReSize(GLsizei, GLsizei);// callback function for resize

        int winMsg(HWND,UINT,WPARAM,LPARAM);

        float screenWidth,screenHeight;
    protected:

    private:
};

#endif // GLSCENE_H
