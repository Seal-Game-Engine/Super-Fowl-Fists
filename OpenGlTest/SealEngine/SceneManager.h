#pragma once
#include "SealPackages.h"
#include <memory>
#include <vector>
#include <queue>
#include <list>
#include "IMessageHandler.h"
//#include "Scene.h"
namespace SealEngine {
    class Scene;
    class GameObject;
}

namespace SealEngine {
    class SceneManager {
    public:
        static void LoadScene(int sceneBuildIndex);
        static Scene* GetActiveScene();
        static bool IsDontDestroyOnLoad(const GameObject* target);

        bool RefreshScene();
        bool InitGl();
        void ResizeGl(GLfloat, GLfloat);

        static void Quit();

        static float aspectRatio() { return width / height; }

        //static const std::vector<std::unique_ptr<Scene>> scenes;

        static float camDist;
        static float width, height;
        //Unity
        //static int sceneCount	The total number of currently loaded Scenes.
        //  sceneCountInBuildSettings	Number of Scenes in Build Settings.

        //CreateScene	Create an empty new Scene at runtime with the given name.
        //GetActiveScene	Gets the currently active Scene.
        //GetSceneAt	Get the Scene at index in the SceneManager's list of loaded Scenes.
        //GetSceneByBuildIndex	Get a Scene struct from a build index.
        //GetSceneByName	Searches through the Scenes loaded for a Scene with the given name.
        //GetSceneByPath	Searches all Scenes loaded for a Scene that has the given asset path.
        //LoadScene	Loads the Scene by its name or index in Build Settings.
        //MoveGameObjectToScene	Move a GameObject from its current Scene to a new Scene.

        //Events
        //activeSceneChanged	Subscribe to this event to get notified when the active Scene has changed.
        //sceneLoaded	Add a delegate to this to get notifications when a Scene has loaded.
        //sceneUnloaded
        static std::list<std::shared_ptr<GameObject>> dontDestroyOnLoadObjects;

    private:
        static std::vector<Scene*> scenes;
        static int currentSceneId;
        static std::queue<int> sceneLoadQuery;
        static bool _quitApplication;
    };
}