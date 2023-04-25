#include "GLLight.h"
#include "SealEngine.h"
#include "CheckCollision.h"
#include "Font.h"
using namespace SealEngine::InputSystem;

int SceneManager::currentSceneId = 0;
std::vector<std::unique_ptr<Scene>> SceneManager::scenes = std::vector<std::unique_ptr<Scene>>{};
std::unique_ptr<CheckCollision> hit = std::unique_ptr<CheckCollision>(new CheckCollision);

void SceneManager::LoadScene(int sceneBuildIndex){
    if (scenes.size() > sceneBuildIndex && scenes[sceneBuildIndex]) {
        currentSceneId = sceneBuildIndex;
        scenes[currentSceneId]->Load();
    }
}

int SceneManager::RefreshScene() {
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glPushMatrix();
    {//gluLookAt(0, 0, -100,               0, 0, 0,               0, 1, 0);
        glTranslatef(0, 0, -10);

        if (scenes.size() > currentSceneId && scenes[currentSceneId]) scenes[currentSceneId]->Refresh();
        ////glLoadIdentity();

        //Font::RenderText("Hello World", Vector2(-10,-10), 1);
    }
    glPopMatrix();

    SwapBuffers(ApplicationManager::deviceContextHandler); // (Double Buffering)
    return 0;
}

bool SceneManager::InitGl() {
#if _WIN64
    glutInit(&__argc, __argv);
#endif

    glClearDepth(1.0f);

    glEnable(GL_DEPTH_TEST);

    //ResizeGl(0, 0);
    glMatrixMode(GL_PROJECTION);

    //gluOrtho2D(0, 100, 100, 0);
    //gluPerspective(45.0, width / height, 0.1, 1000);
    //glMatrixMode(GL_MODELVIEW);

    //---
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);
    
    //GLLight Light(GL_LIGHT0);
    //Light.Set(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);
    Texture2D::LoadUninitializedTextures();
    //player->renderer.Awake();
    //player->Awake();
    //player->renderer.transform().position += Vector3::forward() * 5;
    // 
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
   // enemy.Init(1, 1);

    return true;
}

void SceneManager::ResizeGl(GLfloat width, GLfloat height) {
    glViewport(0, 0, width, height);
    glLoadIdentity();
    glMatrixMode(GL_PROJECTION);
    
    gluPerspective(45.0, width / height, 0.1, 1000);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    //glOrtho(0, width, 0, height, 1, -1); // Origin in lower-left corner
    //glOrtho(0, width, height, 0, 1, -1); // Origin in upper-left corner
}

bool SceneManager::TryHandleMessage(UINT uMsg, WPARAM wParam, LPARAM lParam) {
    if (uMsg == WM_SIZE) {
        ResizeGl(LOWORD(lParam), HIWORD(lParam)); // LoWord=Width, HiWord=Heigh
        return true;
    }
    return false;
}
