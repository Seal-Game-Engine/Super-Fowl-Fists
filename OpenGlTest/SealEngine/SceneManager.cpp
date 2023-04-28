#include "../GLLight.h"
#include "../SealEngine.h"
//#include "CheckCollision.h"
//#include "Font.h"
#include "../AssetManager.h"
#include "../Assets_Scenes.h"
#include "Scene.h"
using namespace SealEngine::InputSystem;

int SceneManager::currentSceneId = 0;
float SceneManager::camDist = -6;
bool SceneManager::_quitApplication = false;
//std::vector<std::unique_ptr<Scene>> SceneManager::scenes = std::vector<std::unique_ptr<Scene>>{};
std::vector<Scene*> SceneManager::scenes = std::vector<Scene*>{};
std::queue<int> SceneManager::sceneLoadQuery = std::queue<int>{};

void SceneManager::LoadScene(int sceneBuildIndex) { sceneLoadQuery.emplace(sceneBuildIndex); }

Scene* SceneManager::GetActiveScene() { return scenes[currentSceneId]; }

bool SceneManager::RefreshScene() {
    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    if (Input::GetKeyDown(KeyCode::Q))camDist++;
    else if (Input::GetKeyDown(KeyCode::E))camDist--;

    glPushMatrix();
    {//gluLookAt(0, 0, -100,               0, 0, 0,               0, 1, 0);
        //glTranslatef(0, 0, camDist);

        if (scenes.size() > currentSceneId) scenes[currentSceneId]->Refresh();
        ////glLoadIdentity();

        //Font::RenderText("Hello World", Vector2(-10,-10), 1);
    }
    glPopMatrix();
    glFinish();
    SwapBuffers(ApplicationManager::deviceContextHandler); // (Double Buffering)

    while (!sceneLoadQuery.empty()) {
        if (scenes.size() > sceneLoadQuery.front()) {
            GetActiveScene()->Unload();
            currentSceneId = sceneLoadQuery.front();
            GetActiveScene()->Load();
        }
        sceneLoadQuery.pop();
    }

    return _quitApplication;
}

bool SceneManager::InitGl() {
#if _WIN64
    glutInit(&__argc, __argv);
#endif

    //glClearDepth(1.0f);

    //glEnable(GL_DEPTH_TEST);

    //ResizeGl(0, 0);
    glMatrixMode(GL_PROJECTION);
    //glLoadIdentity();
    //glOrtho(0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0, -100, 100);
    //gluOrtho2D(0, 100, 100, 0);
    //gluPerspective(45.0, width / height, 0.1, 1000);
    //glMatrixMode(GL_MODELVIEW);

    //---
    //glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //glDisable(GL_DEPTH_TEST);
    glDisable(GL_LIGHTING);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    //GLLight Light(GL_LIGHT0);
    //Light.Set(GL_LIGHT0);
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    Texture2D::LoadUninitializedTextures();

    scenes.emplace_back(&Assets_Scenes::LandingScene);
    scenes.emplace_back(&Assets_Scenes::MenuScene);
    scenes.emplace_back(&Assets_Scenes::TutorialScene);
    scenes.emplace_back(&Assets_Scenes::GameScene);
    scenes.emplace_back(&Assets_Scenes::NarioScene);
    scenes.emplace_back(&Assets_Scenes::XwingScene);
    LoadScene(0);
    return true;
}

void SceneManager::ResizeGl(GLfloat width, GLfloat height) {
    glViewport(0, 0, width, height);

    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();

    float scale = 3;
    float aspectRatio = (float)width / height;
    //glOrtho(-scale * aspectRatio, scale * aspectRatio, -scale, scale, 0, 100);
    //gluPerspective(45.0, width / height, 0, 1000);
    gluOrtho2D(-scale * aspectRatio, scale * aspectRatio, -scale, scale);

    //glMatrixMode(GL_MODELVIEW);
    //glLoadIdentity();

    //glOrtho(0, width, 0, height, 1, -1); // Origin in lower-left corner
    //glOrtho(0, width, height, 0, 1, -1); // Origin in upper-left corner
}

void SceneManager::Quit() { _quitApplication = true; }
