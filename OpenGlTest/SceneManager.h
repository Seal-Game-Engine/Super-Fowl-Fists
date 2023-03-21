#pragma once
#include "IMessageHandler.h"
#include <GL/freeglut.h>
namespace SealEngine {
class IMessageHandler;
}

class SceneManager : public IMessageHandler {
public:
    int RefreshScene();
    bool InitGl();
    void ResizeGl(GLfloat, GLfloat);
    bool TryHandleMessage(const UINT uMsg, const WPARAM wParam, const LPARAM lParam) override;
};