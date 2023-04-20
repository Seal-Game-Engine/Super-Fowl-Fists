#include "Inputs.h"


Inputs::Inputs()
{
    //ctor
}

Inputs::~Inputs()
{
    //dtor
}
void Inputs::keyEnv(parallax* plx, float speed)
{
     switch(wParam)
  {
  case VK_LEFT:
    plx->xMax -=speed;
    plx->xMin -=speed;
    break;

  case VK_RIGHT:
    plx->xMax +=speed;
    plx->xMin +=speed;
    break;

  case VK_DOWN:
    plx->yMax +=speed;
    plx->yMin +=speed;
    break;

  case VK_UP:
    plx->yMax -=speed;
    plx->yMin -=speed;
    break;
}
}

void Inputs::keyPressed(Model * mdl)
{
  switch(wParam)
  {
  case VK_LEFT:
    mdl->rotateY -=1.0;
    break;

  case VK_RIGHT:
    mdl->rotateY +=1.0;
    break;

  case VK_DOWN:
    mdl->rotateX +=1.0;
    break;

  case VK_UP:
    mdl->rotateX -=1.0;
    break;

  case VK_SUBTRACT:
    mdl->zoom -=1.0;
    break;

    case VK_ADD:
    mdl->zoom +=1.0;
    break;
  }
}

void Inputs::keyPlayer(player*  ply)
{
    switch(wParam)
  {

  case VK_RIGHT:
   ply->actions(ply->WALKR);
    break;

  case VK_LEFT:
    ply->actions(ply->WALKL);
    break;

  case VK_DOWN:

    break;

  case VK_UP:

    break;
}
}

void Inputs::keyUp()
{
   switch(wParam)
  {}
}

void Inputs::mouseBtnDwn(Model * mdl,double x, double y)
{
     prev_Mx = x;
     prev_My = y;

     switch(wParam)
     {
         case MK_LBUTTON: Mouse_Rotate = true; break;
         case MK_RBUTTON: Mouse_translate = true; break;
         case MK_MBUTTON: break;
     }
}

void Inputs::mouseBtnUp()
{
    Mouse_Rotate = false;
    Mouse_translate = false;
}

void Inputs::mouseWheel(Model * mdl,double delta)
{
    mdl->zoom +=delta/100.0;
}

void Inputs::mouseMove(Model * mdl,double x, double y)
{
    if(Mouse_translate)
    {
        mdl->posX += (x - prev_Mx)/100.0;
        mdl->posY -= (y - prev_My)/100.0;

        prev_Mx =x;
        prev_My =y;
    }

    if(Mouse_Rotate)
    {
        mdl->rotateX += (x - prev_Mx)/3.0;
        mdl->rotateY += (y - prev_My)/3.0;

        prev_Mx =x;
        prev_My =y;
    }

}


