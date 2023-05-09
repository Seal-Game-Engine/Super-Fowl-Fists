#include "../SealEngine.h"
//#include "Font.h"
#include "../Prefab.h"
#include "../GlobalMenuScene.h"
#include "../GlobalGameScene.h"
#include "../Testing/TestScene.h"
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

std::list<std::shared_ptr<GameObject>> SceneManager::dontDestroyOnLoadObjects = std::list<std::shared_ptr<GameObject>>{};


void SceneManager::LoadScene(int sceneBuildIndex) { sceneLoadQuery.emplace(sceneBuildIndex); }

Scene* SceneManager::GetActiveScene() { return scenes[currentSceneId]; }

bool SceneManager::IsDontDestroyOnLoad(const GameObject* target){
    for (auto& gameObject : dontDestroyOnLoadObjects) if (target == gameObject.get()) return true;
    return false;
}

bool SceneManager::RefreshScene() {
    bool hasCamera = false;
    Transform* camera = nullptr;

    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    if (Camera::mainCamera) {
        hasCamera = true;
        glMatrixMode(GL_PROJECTION);
        glLoadIdentity();
        switch (Camera::mainCamera->projection) {
        case Camera::Projection::Perspective:
            break;
        case Camera::Projection::Orthographic:
            gluOrtho2D(-Camera::mainCamera->size * aspectRatio(), Camera::mainCamera->size * aspectRatio(), -Camera::mainCamera->size, Camera::mainCamera->size);
            break;
        }

        camera = Camera::mainCamera->transform();
        glTranslatef(-camera->position.x(), -camera->position.y(), -camera->position.z());
        glRotatef(-camera->rotation.x(), 1, 0, 0);
        glRotatef(-camera->rotation.y(), 0, 1, 0);
        glRotatef(-camera->rotation.z(), 0, 0, 1);
    }

    glMatrixMode(GL_MODELVIEW);
    GetActiveScene()->RefreshWorld();

    if (hasCamera) {
        glMatrixMode(GL_PROJECTION);
        glTranslatef(camera->position.x(), camera->position.y(), camera->position.z());
        glRotatef(camera->rotation.x(), 1, 0, 0);
        glRotatef(camera->rotation.y(), 0, 1, 0);
        glRotatef(camera->rotation.z(), 0, 0, 1);
    }

    glMatrixMode(GL_MODELVIEW);
    GetActiveScene()->RefreshGui();

    GetActiveScene()->RefreshHierarchy();

    while (!sceneLoadQuery.empty()) {
        if (scenes.size() > sceneLoadQuery.front()) {
            GetActiveScene()->Unload();
            currentSceneId = sceneLoadQuery.front();
            GetActiveScene()->Load();
        }
        sceneLoadQuery.pop();
    }
    SwapBuffers(ApplicationManager::deviceContextHandler); // (Double Buffering)
    glFinish();

    return _quitApplication;
}

bool SceneManager::InitGl() {
#if _WIN64
    glutInit(&__argc, __argv);
#endif

    glClearDepth(1.0f);
    //glDepthFunc(GL_LEQUAL);

    //glEnable(GL_DEPTH_TEST);
    //glDisable(GL_DEPTH_TEST);

    //ResizeGl(0, 0);
   

    glClearColor(0.0f, 0.0f, 0.0f, 0.0f);

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

    scenes.emplace_back(&GlobalMenuScene::LandingScene);    //Scene 0 
    scenes.emplace_back(&GlobalMenuScene::MenuScene);       //Scene 1
    scenes.emplace_back(&GlobalMenuScene::CreditScene);     //Scene 2
    scenes.emplace_back(&GlobalGameScene::TutorialScene);   //Scene 3
    scenes.emplace_back(&GlobalGameScene::Lv0Scene);      //Scene 4
    scenes.emplace_back(&GlobalGameScene::Lv1Scene);      //Scene 5
    scenes.emplace_back(&TestScene::TestingScene);          //Scene 6
    scenes.emplace_back(&GlobalMenuScene::SealLogoScene);
    LoadScene(7);
    return true;
}

void SceneManager::ResizeGl(GLfloat width, GLfloat height) {
    glViewport(0, 0, width, height);

    this->width = (float)width;
    this->height = (float)height;
}

void SceneManager::Quit() { _quitApplication = true; }
