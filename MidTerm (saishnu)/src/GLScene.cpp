#include "GLScene.h"
#include <GLLight.h>
#include <Model.h>
#include <Inputs.h>
#include <parallax.h>
#include <player.h>
#include <enms.h>
#include <checkCollision.h>

Model *myFirstModel = new Model();
Inputs *KbMs = new Inputs(); //Input
parallax *prLX = new parallax(); //Parallax
player *ply = new player(); //Player
checkCollision *hit = new checkCollision(); //Collision check

enms en[5]; //Generating enemies

parallax paral[3]; //For multiple parallax images

int playerHitCount = 0; // Player hit count
int currentLevel = 1; //Current level

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

void GLScene::gameReset()
{
    playerHitCount = 0; // Reset player hit count
    currentLevel = 1;

    // Reset player position to far left of screen
    ply->pPos.x = -5 / 2.0;
    ply->pPos.y = 0.0;

    // Reset enemies
    en[0].ePos.y = 5.0;
    en[1].ePos.y = 5.0;
    en[2].ePos.y = 5.0;

    // Reset parallax images
    for (int i = 0; i < 3; i++) {
        paral[i];
    }
}

int GLScene::drawScene()
{
    glClear(GL_COLOR_BUFFER_BIT|GL_DEPTH_BUFFER_BIT);
    glLoadIdentity();

    glColor3f(1.0,0.0,0.0);   // R, G, B

    //Resets the player position when entering a new level
    if(ply->pPos.x > 5 / 2.0)
    {
        currentLevel++;

        //Resets the player position to far left of screen
        ply->pPos.x = -5 / 2.0;
        ply->pPos.x = 0.0;
    }

    switch(currentLevel)
    {

    //First Level
    case 1:
        //Background Implementation
        glPushMatrix();
        glScaled(5.33, 5.33, 1.0);
        paral[0].drawSquare(screenWidth, screenHeight);
        paral[0].scroll(true, "x", 0.0005f);
        glPopMatrix();

        //--Enemy Implementations
        //Enemy Drawn
        for (int i = 0; i < 5; i++)
        {
        //Enemy Fall
        if (en[i].ePos.y > -3.5) // check if enemy is still on the screen
        {
        en[i].action = en[i].WALKUP;
        en[i].eSpeed.y = -0.01; // subtract 0.01 from the y-position in each iteration
        //en[i].ePos = en[i].eSpeed; // update the position
        }
        en[i].drawEnemy();

            // Check if enemy is visible on screen
            if (en[i].ePos.y > 3.5)
            {
                if (ply->actionTrigger == ply->WALKR && ply->pPos.x < en[i].ePos.x)
                {
                    if (hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y, 0.1, 0.11))
                    {
                        playerHitCount++; // Increment playerHitCount if player is hit
                    }
                }
                else if (ply->actionTrigger == ply->WALKL && ply->pPos.x > en[i].ePos.x)
                {
                    if (hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y, 0.1, 0.11))
                    {
                        playerHitCount++; // Increment playerHitCount if player is hit
                    }
                }
            }
        }

        // Check if player has been hit 5 times and reset the game if true
        if(playerHitCount >= 5)
        {
            gameReset();
        }

        break;


    //Second Level
    case 2:
        //Background Implementation
        glPushMatrix();
        glScaled(5.33, 5.33, 1.0);
        paral[1].drawSquare(screenWidth, screenHeight);
        paral[1].scroll(true, "x", 0.0005f);
        glPopMatrix();

        //Enemy Drawn
        for (int i = 0; i < 5; i++)
        {
            en[i].drawEnemy();
        }

        //Enemy Fall
        if (en[1].ePos.y < 3.5)
        {
            en[1].action = en[1].WALKUP;
            en[1].eSpeed.y = 0.01;
        }

        //--Enemy Implementations
        //Enemy Drawn
        for (int i = 0; i < 5; i++)
        {
            //Enemy Fall
            if (en[i].ePos.y < 3.5)
            {
                en[i].action = en[i].WALKUP;
                en[i].eSpeed.y = 0.01;
            }

            // Check if enemy is visible on screen
            if (en[i].ePos.y > 3.5)
            {
                if (ply->actionTrigger == ply->WALKR && ply->pPos.x < en[i].ePos.x)
                {
                    if (hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y, 0.1, 0.11))
                    {
                        playerHitCount++; // Increment playerHitCount if player is hit
                    }
                }
                else if (ply->actionTrigger == ply->WALKL && ply->pPos.x > en[i].ePos.x)
                {
                    if (hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y, 0.1, 0.11))
                    {
                        playerHitCount++; // Increment playerHitCount if player is hit
                    }
                }
            }
            en[i].drawEnemy();
        }

        // Check if player has been hit 5 times and reset the game if true
        if(playerHitCount >= 5)
        {
            gameReset();
        }
        break;

    //Third Level
    case 3:
        //Background Implementation
        glPushMatrix();
        glScaled(5.33, 5.33, 1.0);
        paral[2].drawSquare(screenWidth, screenHeight);
        paral[2].scroll(true, "x", 0.0005f);
        glPopMatrix();

        //Enemy Drawn
        for (int i = 0; i < 5; i++)
        {
            en[2].drawEnemy();
        }

        //Enemy Fall
        if (en[2].ePos.y < 3.5)
        {
            en[2].action = en[2].WALKUP;
            en[2].eSpeed.y = 0.01;
        }

        //--Enemy Implementations
        //Enemy Drawn
        for (int i = 0; i < 5; i++)
        {
            //Enemy Fall
            if (en[i].ePos.y < 3.5)
            {
                en[i].action = en[i].WALKUP;
                en[i].eSpeed.y = 0.01;
            }

            // Check if enemy is visible on screen
            if (en[i].ePos.y > 3.5)
            {
                if (ply->actionTrigger == ply->WALKR && ply->pPos.x < en[i].ePos.x)
                {
                    if (hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y, 0.1, 0.11))
                    {
                        playerHitCount++; // Increment playerHitCount if player is hit
                    }
                }
                else if (ply->actionTrigger == ply->WALKL && ply->pPos.x > en[i].ePos.x)
                {
                    if (hit->isRadialCollision(ply->pPos.x, en[i].ePos.x, ply->pPos.y, en[i].ePos.y, 0.1, 0.11))
                    {
                        playerHitCount++; // Increment playerHitCount if player is hit
                    }
                }
            }
            en[i].drawEnemy();
        }

        // Check if player has been hit 5 times and reset the game if true
        if(playerHitCount >= 5)
        {
            gameReset();
        }
        break;

    //Automatically exits the game
    case 4:
        exit(0);
        break;
    }
    glPopMatrix();

    //Player
    glPushMatrix();
    glTranslated(-1.25, 0, 0);
    ply->drawPlayer();
    glPopMatrix();
}


int GLScene::GLinit()
{
    glEnable(GL_BLEND);
    glBlendFunc(GL_SRC_ALPHA, GL_ONE_MINUS_SRC_ALPHA);

    glClearDepth(1.0f);
    glEnable(GL_DEPTH_TEST);
    glDepthFunc(GL_LEQUAL);
    glClearColor(0.0f,0.0f,0.0f,0.0f);

    glEnable(GL_LIGHTING);
    glEnable(GL_LIGHT0);

    GLLight Light(GL_LIGHT0);
    Light.setLight(GL_LIGHT0);

    glEnable(GL_TEXTURE_2D);

    //Background Images
    paral[0].initParallax("images/level_1.png"); //Level 1
    paral[1].initParallax("images/level_2.png"); //Level 2
    paral[2].initParallax("images/level_3.png"); //Level 3

    //Player Image
    ply->playerInit("images/player.png", 4, 4);


    if(currentLevel == 1){
    en[0].enemyTexture("images/enemy_1.png"); //Enemy 1

    //Level 1 Enemy Generation
    for(int i = 0; i < 5; i++){
    en[i].initEnemy(en[0].tex, 1, 1);
    //Enemy placements
    float x = (float)rand()/(float)(RAND_MAX) * 5.0;
    float y = (float)rand()/(float)(RAND_MAX) * 1.0;
    float z = (float)rand()/(float)(RAND_MAX) * -4.5;
    en[i].placeEnemy(vec3{x, y, z});
    en[i].eSize.x = en[i].eSize.y = 0.2;
    }}

    //Level 2 Enemy Generation
    else if(currentLevel == 2){
    en[1].enemyTexture("images/enemy_2.png"); //Enemy 2
    for(int i = 0; i < 5; i++){
    en[i].initEnemy(en[1].tex, 1, 1);
    //Enemy placements
    float x = (float)rand()/(float)(RAND_MAX) * 5.0;
    float y = (float)rand()/(float)(RAND_MAX) * 1.0;
    float z = (float)rand()/(float)(RAND_MAX) * -4.5;
    en[i].placeEnemy(vec3{x, y, z});
    en[i].eSize.x = en[i].eSize.y = 0.2;
    }}

    //Level 3 Enemy Generation
    else if(currentLevel == 3){
    en[2].enemyTexture("images/enemy_3.png"); //Enemy 3
    for(int i = 0; i < 5; i++){
    en[i].initEnemy(en[2].tex, 1, 1);
    //Enemy placements
    float x = (float)rand()/(float)(RAND_MAX) * 5.0;
    float y = (float)rand()/(float)(RAND_MAX) * 1.0;
    float z = (float)rand()/(float)(RAND_MAX) * -4.5;
    en[i].placeEnemy(vec3{x, y, z});
    en[i].eSize.x = en[i].eSize.y = 0.2;
    }}

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
