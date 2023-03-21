#pragma once
#include "Player.h"
#include <memory>
#include "IMessageHandler.h"
#include <GL/freeglut.h>

class SceneManager : public IMessageHandler {
public:
    int RefreshScene();
    bool InitGl();
    void ResizeGl(GLfloat, GLfloat);
    //std::unique_ptr<Player> player = std::unique_ptr<Player>(new Player);

    bool TryHandleMessage(const UINT uMsg, const WPARAM wParam, const LPARAM lParam) override;

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

};