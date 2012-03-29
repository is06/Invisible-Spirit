/******************************************************************************
Invisible Spirit by Thomas Noury is licensed under a Creative Commons
Attribution-NonCommercial-ShareAlike 3.0 Unported License. Based on a work at
is06.com. Permissions beyond the scope of this license may be available at
http://www.is06.com. Legal code in license.txt
*******************************************************************************/

#include "../../include/ref/core.h"
#include "../../include/gui/Window.h"
#include "../../include/gui/Picture.h"

using namespace irr;
using namespace std;

/**
 *
 */
Window::Window(f32 x, f32 y, f32 w, f32 h, f32 borderWidth, WindowStyle style) : Hud()
{
  pos = core::position2df(x, y);
  size = core::dimension2df(w, h);

  switch (style) {
    case WIN_STYLE_STD: applyStyleStd(x, y, w, h, borderWidth); break;
    default: applyStyleNone(); break;
  }
}

/**
 *
 */
void Window::applyStyleStd(f32 x, f32 y, f32 w, f32 h, f32 borderWidth)
{
  string texturePath = "resource/hud/window/window1.bmp";

  f32 sideW = w - borderWidth;
  f32 sideH = h - borderWidth;
  f32 sideWMin = x + (w / 2) * -1;
  f32 sideWMax = x + (w / 2);
  f32 sideHMin = y + (h / 2) * -1;
  f32 sideHMax = y + (h / 2);

  cornerTL = new Picture(sideWMin, sideHMin, borderWidth, borderWidth, texturePath);
  cornerTR = new Picture(sideWMax, sideHMin, borderWidth, borderWidth, texturePath);
  cornerBL = new Picture(sideWMin, sideHMax, borderWidth, borderWidth, texturePath);
  cornerBR = new Picture(sideWMax, sideHMax, borderWidth, borderWidth, texturePath);

  cornerBL->setTextureOffset(core::vector2df(0.0f, 0.0f), core::vector2df(0.0625f, 0.0625f));
  cornerBR->setTextureOffset(core::vector2df(0.9375f, 0.0f), core::vector2df(1.0f, 0.0625f));
  cornerTL->setTextureOffset(core::vector2df(0.0f, 0.9375f), core::vector2df(0.0625f, 1.0f));
  cornerTR->setTextureOffset(core::vector2df(0.9375f, 0.9375f), core::vector2df(1.0f, 1.0f));

  sideTop = new Picture(x, sideHMax, sideW, borderWidth, texturePath);
  sideLeft = new Picture(sideWMin, y, borderWidth, sideH, texturePath);
  sideRight = new Picture(sideWMax, y, borderWidth, sideH, texturePath);
  sideBottom = new Picture(x, sideHMin, sideW, borderWidth, texturePath);

  sideTop->setTextureOffset(core::vector2df(0.0625f, 0.0f), core::vector2df(0.9375f, 0.0625f));
  sideLeft->setTextureOffset(core::vector2df(0.0f, 0.0625f), core::vector2df(0.0625f, 0.9375f));
  sideRight->setTextureOffset(core::vector2df(0.9375f, 0.0625f), core::vector2df(1.0f, 0.9375f));
  sideBottom->setTextureOffset(core::vector2df(0.0625f, 0.9375f), core::vector2df(0.9375f, 1.0f));

  center = new Picture(x, y, sideW, sideH, texturePath);
  center->setTextureOffset(core::vector2df(0.0625f, 0.0625f), core::vector2df(0.9375f, 0.9375f));
}

/**
 *
 */
void Window::applyStyleNone()
{
  center = NULL;
}

/**
 *
 */
void Window::render()
{
  Hud::render();
  if (center) {
    cornerTL->render();
    cornerTR->render();
    cornerBL->render();
    cornerBR->render();
    sideTop->render();
    sideLeft->render();
    sideRight->render();
    sideBottom->render();
    center->render();
  }
}

void Window::show()
{
  cornerTL->show();
  cornerTR->show();
  cornerBL->show();
  cornerBR->show();
  sideTop->show();
  sideLeft->show();
  sideRight->show();
  sideBottom->show();
  center->show();
}

void Window::hide()
{
  cornerTL->hide();
  cornerTR->hide();
  cornerBL->hide();
  cornerBR->hide();
  sideTop->hide();
  sideLeft->hide();
  sideRight->hide();
  sideBottom->hide();
  center->hide();
}

void Window::setOpacity(u8 value)
{
  cornerTL->setOpacity(value);
  cornerTR->setOpacity(value);
  cornerBL->setOpacity(value);
  cornerBR->setOpacity(value);
  sideTop->setOpacity(value);
  sideLeft->setOpacity(value);
  sideRight->setOpacity(value);
  sideBottom->setOpacity(value);
  center->setOpacity(value);
}

/**
 *
 */
Window::~Window()
{
  if (center) {
    delete cornerTL;
    delete cornerTR;
    delete cornerBL;
    delete cornerBR;
    delete sideTop;
    delete sideLeft;
    delete sideRight;
    delete sideBottom;
    delete center;
  }
}
