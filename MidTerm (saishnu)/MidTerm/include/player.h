#ifndef PLAYER_H
#define PLAYER_H

#include<GL/gl.h>
#include<textureLoader.h>
#include<commons.h>
#include <GLScene.h>



class player
{
    public:
        player();
        virtual ~player();

        vec3 scaleSize;
        vec3 verts[4];

        enum acts{IDLE,WALKR,WALKL,JUMP,ATTACK,DIE};

        float runSpeed;
        float jumpSpeed;
        acts actionTrigger;

        char playerDir;  // to find out player's direction

        void drawPlayer();
        void playerInit(char *, int,int);
        void actions(acts);

        int hFrames; // horizontal frames
        int vFrames; // vertical frames

        int playerHit; //Player Hit

        float xMax,yMax,xMin,yMin;
        vec3 pPos;

        GLuint tex;
        textureLoader *tLoad = new textureLoader();

        //Update Function to detect if player has hit the side of the screen
        void update() {
        // get the screen width and height
        //int screenWidth = glutGet(GLUT_WINDOW_WIDTH);
        //int screenHeight = glutGet(GLUT_WINDOW_HEIGHT);

        // calculate the left and right edge of the screen
        //float leftEdge = -1.0f;
        //float rightEdge = 1.0f - (float)screenWidth / (float)screenHeight;

        // check if player has hit the left side of the screen
        //if (pPos.x < leftEdge) {
        // handle the collision with the left edge of the screen
        // for example, you could stop the player or move it back
       // pPos.x = leftEdge;
        //}

        // check if player has hit the right side of the screen
        //else if (pPos.x > rightEdge) {
        // handle the collision with the right edge of the screen
        // for example, you could stop the player or move it back
       // pPos.x = rightEdge;
        //}
        // move the player normally
        //else {
        //pPos.x += runSpeed;
        //pPos.y += jumpSpeed;
        //}
    }

    protected:

    private:
};

#endif // PLAYER_H
