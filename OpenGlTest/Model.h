#pragma once
#include "SealEngine.h"
using namespace SealEngine;

class Model {
public:
    void DrawModel();
    void Update();
    void Initialize();

    Transform transform;

    GLuint tex;
    Texture2D tLoad;
};