#include "GLScene.h"
#include <GLLight.h>
#include <Model.h>
#include<Inputs.h>
#include <parallax.h>
#include<player.h>
#include<enms.h>
#include<checkCollision.h>

Model *myFirstModel = new Model();
Inputs *KbMs = new Inputs();
parallax *prLX = new parallax();
player *ply = new player();
checkCollision *hit = new checkCollision();

enms en[20];

GLScene::GLScene()
{
    //ctor
    screenHeight = GetSystemMetrics(SM_CYSCREEN);
    screenWidth  = GetSystemMetrics(SM_CXSCREEN);
}

GLScene::~GLScene()
{
    //dtor
}

int GLScene::drawScene()
{
   glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
   glLoadIdentity();

   glColor3f(1.0,0.0,0.0);   // R, G,B

   glPushMatrix();
   glScaled(3.33,3.33,1.0);
   prLX->drawSquare(screenWidth,screenHeight);
   glPopMatrix();
}

int GLScene::GLinit()
{
    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);


    return true;
}

void GLScene::GLReSize(GLsizei width, GLsizei height)
{
    screenWidth= width;
    screenHeight = height;
    float ratio = (float)width/(float)height;
    glViewport(0,0, width,height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0,ratio,0.1,100);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
}

int GLScene::winMsg(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    KbMs->wParam = wParam;

    switch(uMsg)
    {
    case WM_KEYDOWN:

        KbMs->keyPressed(myFirstModel);
        KbMs->keyEnv(prLX,0.005);
        KbMs->keyPlayer(ply);

        break;

    case WM_KEYUP:
        KbMs ->keyUp();
        ply->actions(ply->IDLE);
        break;

    case WM_LBUTTONDOWN:

        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_RBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MBUTTONDOWN:
        KbMs->mouseBtnDwn(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case    WM_LBUTTONUP:
    case    WM_RBUTTONUP:
    case    WM_MBUTTONUP:

             KbMs ->mouseBtnUp();
            break;

    case WM_MOUSEMOVE:
        KbMs->mouseMove(myFirstModel, LOWORD(lParam),HIWORD(lParam));
        break;

    case WM_MOUSEWHEEL:
        KbMs->mouseWheel(myFirstModel,(double)GET_WHEEL_DELTA_WPARAM(wParam));
        break;
    }

}
