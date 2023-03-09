#include <windows.h>

#include "GLLight.h"
#include "SealEngine.h"
#include "Model.h"
#include "Player.h"
#include "Enemy.h"
using namespace SealEngine::InputSystem;

Inputs* KbMs = new Inputs();
Model* mdl = new Model();
Player* player = new Player();
Enemy* enemy = new Enemy();

int SceneManager::RefreshScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    glTranslated(0, 0, -8);
    glPopMatrix();

    //---
    glPushMatrix();
    mdl->DrawModel();
    player->Draw();
    //glLoadIdentity();
    glPopMatrix();

    SwapBuffers(ApplicationManager::deviceContextHandler); // (Double Buffering)
    return 0;
}

bool SceneManager::InitGl() {
    glutInit(&__argc, __argv);

    glClearDepth(1.0);

    glEnable(GL_DEPTH_TEST);

    //ResizeGl(0, 0);
    glMatrixMode(GL_PROJECTION);

    //gluOrtho2D(0, 100, 100, 0);
    //gluPerspective(45.0, width / height, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);

    //---
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    glEnable(GL_COLOR_MATERIAL);
    GLLight Light(GL_LIGHT0);
    Light.Set(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);

    mdl->Initialize();
    player->Init((char*)"Hector_Run.png");
    enemy->Init((char*)"Googleplex.jpg", 1, 1);

    return true;
}

void SceneManager::ResizeGl(GLfloat width, GLfloat height) {
    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0, width / height, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();//todo: test with not fullscreen
}

bool SceneManager::TryHandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    mdl->Update();
    player->Update();
    player->Update();
    if (uMsg == WM_SIZE) {
        ResizeGl(LOWORD(lParam), HIWORD(lParam)); // LoWord=Width, HiWord=Heigh
        return true;
    }
    return false;
}