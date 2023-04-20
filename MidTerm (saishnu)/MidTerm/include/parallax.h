#ifndef PARALLAX_H
#define PARALLAX_H

#include<textureLoader.h>
#include <time.h>


class parallax
{
    public:
        parallax();
        virtual ~parallax();

        void drawSquare(float, float);
        void initParallax(char *);
        void scroll(bool,string, float);

        float xMax,xMin,yMax,yMin;

        textureLoader *bTex = new textureLoader();

        clock_t startTime;

        GLuint tex;


    protected:

    private:
};

#endif // PARALLAX_H
