#ifndef TEXTURELOADER_H
#define TEXTURELOADER_H

#include<iostream>
#include<SOIL.h>
#include<gl/gl.h>

using namespace std;
class textureLoader
{
    public:
        textureLoader();         // constructor
        virtual ~textureLoader();//destructor

        void loadTexture(char *, GLuint&); // to load images
        void binder(GLuint); // To bind images

        unsigned char* image; //To hold image data
        int width, height;    // image width and height

       // GLuint test;

    protected:

    private:
};

#endif // TEXTURELOADER_H
