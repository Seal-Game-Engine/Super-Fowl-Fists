#include "../SealEngine.h"
//#include "Font.h"
#include "../AssetManager.h"
#include "../Assets_Scenes.h"
#include "Scene.h"
#include "Camera.h"
using namespace SealEngine::InputSystem;

int SceneManager::currentSceneId = 0;
float SceneManager::width = 0;
float SceneManager::height = 0;
float SceneManager::camDist = -6;
bool SceneManager::_quitApplication = false;
//std::vector<std::unique_ptr<Scene>> SceneManager::scenes = std::vector<std::unique_ptr<Scene>>{};
std::vector<Scene*> SceneManager::scenes = std::vector<Scene*>{};
std::queue<int> SceneManager::sceneLoadQuery = std::queue<int>{};

void SceneManager::LoadScene(int sceneBuildIndex) { sceneLoadQuery.emplace(sceneBuildIndex); }

Scene* SceneManager::GetActiveScene() { return scenes[currentSceneId]; }

bool SceneManager::RefreshScene() {
    float camX = 0, camY = 0;

    if (Input::GetKeyDown(KeyCode::Alpha1))camX--;
    else if (Input::GetKeyDown(KeyCode::Alpha2))camX++;
    glTranslatef(-camX, camY, 0);

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (Camera::mainCamera) {
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        switch (Camera::mainCamera->projection){
        case Camera::Projection::Perspective:
            break;
        case Camera::Projection::Orthographic:
            gluOrtho2D(-Camera::mainCamera->size * aspectRatio(), Camera::mainCamera->size * aspectRatio(), -Camera::mainCamera->size, Camera::mainCamera->size);
            break;
        default:
            break;
        }

        Vector3 position = Camera::mainCamera->transform()->position;
        glTranslatef(-position.x(), -position.y(), -position.z());
    }

    glMatrixMode(GL_MODELVIEW);
    glPushMatrix();
    {
        if (scenes.size() > currentSceneId) scenes[currentSceneId]->Refresh();
        //Font::RenderText("Hello World", Vector2(-10,-10), 1);
    }
    glPopMatrix();
    glFinish();

    while (!sceneLoadQuery.empty()) {
        if (scenes.size() > sceneLoadQuery.front()) {
            GetActiveScene()->Unload();
            currentSceneId = sceneLoadQuery.front();
            GetActiveScene()->Load();
        }
        sceneLoadQuery.pop();
    }
    SwapBuffers(ApplicationManager::deviceContextHandler); // (Double Buffering)

    return _quitApplication;
}

bool SceneManager::InitGl() {
#if _WIN64
    glutInit(&__argc, __argv);
#endif

    glClearDepth(1.0f);

    //glEnable(GL_DEPTH_TEST);

    //ResizeGl(0, 0);
   
    //---
    //glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);
    //glDisable(GL_DEPTH_TEST);
    //glDisable(GL_LIGHTING);
    //glEnable(GL_LIGHTING);
    //glEnable(GL_LIGHT0);

    //GLLight Light(GL_LIGHT0);
    //Light.Set(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);
    glEnable(GL_COLOR_MATERIAL);
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);
    Texture2D::LoadUninitializedTextures();

    scenes.emplace_back(&Assets_Scenes::LandingScene);
    scenes.emplace_back(&Assets_Scenes::MenuScene);
    scenes.emplace_back(&Assets_Scenes::TutorialScene);
    scenes.emplace_back(&Assets_Scenes::GameScene);
    scenes.emplace_back(&Assets_Scenes::TestingScene);
    scenes.emplace_back(&Assets_Scenes::XwingScene);
    LoadScene(0);
    return true;
}

void SceneManager::ResizeGl(GLfloat width, GLfloat height) {
    glViewport(0, 0, width, height);

    this->width = (float)width;
    this->height = (float)height;
}

void SceneManager::Quit() { _quitApplication = true; }
